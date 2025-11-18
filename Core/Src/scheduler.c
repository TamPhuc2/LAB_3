/*
 * scheduler.c
 *
 *  Created on: Nov 18, 2025
 *      Author: tntam
 */


#include "scheduler.h"

sTask SCH_task_G[SCH_MAX_TASKS];
static uint32_t newTaskID = 0;

static  uint32_t getNewTaskID(void);

// tao taskID
static uint32_t getNewTaskID(void){
	newTaskID++;
	if(newTaskID == NO_TASK_ID){
		newTaskID++;
	}
	return newTaskID;
}

void SCH_Init(void){
	uint32_t i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_task_G[i].pTask = NULL;
		SCH_task_G[i].Delay = 0;
		SCH_task_G[i].Period = 0;
		SCH_task_G[i].RunMe = 0;
		SCH_task_G[i].Task_ID = NO_TASK_ID;
	}
}

//Update task function ----- MUST O(1)
void SCH_Update(void){
	// pTask != Null, RUNME wait
	if(SCH_task_G[0].pTask && SCH_task_G[0].RunMe == 0){
		if(SCH_task_G[0].Delay > 0){
			SCH_task_G[0].Delay--;
		}
		//set RUMME flag
		if(SCH_task_G[0].Delay == 0){
			SCH_task_G[0].RunMe = 1;
		}
	}
}
//Add task function ----- O(n^2)
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period){
	uint8_t newTaskIndex = 0; //new position task
	uint32_t sumDelay = 0; //[0 -> added position]
	uint32_t newDelay = 0; //delay time for new task

	for(newTaskIndex = 0; newTaskIndex < SCH_MAX_TASKS; newTaskIndex++){
		//check exist task
		if(SCH_task_G[newTaskIndex].pTask){
			sumDelay += SCH_task_G[newTaskIndex].Delay;
		}

		if(sumDelay > delay){
			//delay for new task
			newDelay = delay - (sumDelay - SCH_task_G[newTaskIndex].Delay);
			//new delay for current task
			SCH_task_G[newTaskIndex].Delay = sumDelay - delay;

			//shift right
			for(uint8_t i = SCH_MAX_TASKS - 1; i > newTaskIndex; i--){
				SCH_task_G[i].pTask = SCH_task_G[i-1].pTask;
				SCH_task_G[i].Delay = SCH_task_G[i-1].Delay;
				SCH_task_G[i].Period = SCH_task_G[i-1].Period;
				SCH_task_G[i].Task_ID = SCH_task_G[i-1].Task_ID;
				SCH_task_G[i].RunMe = SCH_task_G[i-1].RunMe;
			}
			//add new task into current position
			SCH_task_G[newTaskIndex].pTask = pFunction;
			SCH_task_G[newTaskIndex].Delay = newDelay;
			SCH_task_G[newTaskIndex].Period = period;
			SCH_task_G[newTaskIndex].Task_ID = getNewTaskID();
			//SCH_task_G[newTaskIndex].RunMe = 0;

			//set RUMME flag
			if(SCH_task_G[newTaskIndex].Delay == 0){
				SCH_task_G[newTaskIndex].RunMe = 1;
			}
			else{
				SCH_task_G[newTaskIndex].RunMe = 0;
			}
			return SCH_task_G[newTaskIndex].Task_ID;
		}
		//sumdelay <= delay, chen cuoi mang
		else if(SCH_task_G[newTaskIndex].pTask == NULL){
			SCH_task_G[newTaskIndex].pTask = pFunction;
			SCH_task_G[newTaskIndex].Delay = delay - sumDelay;
			SCH_task_G[newTaskIndex].Period = period;
			SCH_task_G[newTaskIndex].Task_ID = getNewTaskID();
			//SCH_task_G[newTaskIndex].RunMe = 0;

			//set RUNME flag
			if(SCH_task_G[newTaskIndex].Delay == 0){
				SCH_task_G[newTaskIndex].RunMe = 1;
			}
			else{
				SCH_task_G[newTaskIndex].RunMe = 0;
			}
			return SCH_task_G[newTaskIndex].Task_ID;
		}
	}
	// full array
	return NO_TASK_ID;
}
//Dispatch task function ----- O(1)
void SCH_Dispatch_Tasks(void){
	if(SCH_task_G[0].RunMe > 0){
		(*SCH_task_G[0].pTask)();
		SCH_task_G[0].RunMe = 0;

		sTask currentTask = SCH_task_G[0];
		SCH_Delete_Task(currentTask.Task_ID);

		//add period task back to array
		if(currentTask.Period != 0){
			SCH_Add_Task(currentTask.pTask, currentTask.Period, currentTask.Period);
		}
	}
}
//Delete task function ----- O(n^2)
uint32_t SCH_Delete_Task(uint32_t task_ID){
	uint8_t task_Index;
	uint8_t temp_Index;
	//check valid taskID
	if(task_ID == NO_TASK_ID) return NO_TASK_ID;

	for(task_Index = 0; task_Index < SCH_MAX_TASKS; task_Index++){
		if(SCH_task_G[task_Index].Task_ID == task_ID){
			//sum delay of deleted tasks
			if(task_Index < SCH_MAX_TASKS - 1){
				if(SCH_task_G[task_Index + 1].pTask != NULL){
					SCH_task_G[task_Index + 1].Delay += SCH_task_G[task_Index].Delay;
				}
			}
			//shift task
			for(temp_Index = task_Index; temp_Index < SCH_MAX_TASKS - 1; temp_Index++){
				SCH_task_G[temp_Index].Delay = SCH_task_G[temp_Index + 1].Delay;
				SCH_task_G[temp_Index].Period = SCH_task_G[temp_Index + 1].Period;
				SCH_task_G[temp_Index].RunMe = SCH_task_G[temp_Index + 1].RunMe;
				SCH_task_G[temp_Index].pTask = SCH_task_G[temp_Index + 1].pTask;
				SCH_task_G[temp_Index].Task_ID = SCH_task_G[temp_Index + 1].Task_ID;
			}

			//set init task
			SCH_task_G[temp_Index].pTask = NULL;
			SCH_task_G[temp_Index].Delay = 0;
			SCH_task_G[temp_Index].Period = 0;
			SCH_task_G[temp_Index].RunMe = 0;
			SCH_task_G[temp_Index].Task_ID = NO_TASK_ID;

			return task_ID;
		}
	}
	return NO_TASK_ID;
}

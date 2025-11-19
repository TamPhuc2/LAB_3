/*
 * scheduler.h
 *
 *  Created on: Nov 18, 2025
 *      Author: tntam
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stddef.h>

#define SCH_MAX_TASKS	10
#define NO_TASK_ID		0

typedef struct{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t Task_ID;
} sTask;


void SCH_Init(void);
void SCH_Update(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Delete_Task(uint32_t task_ID);

#endif /* INC_SCHEDULER_H_ */

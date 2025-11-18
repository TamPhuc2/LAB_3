/*
 * software_timer.c
 *
 *  Created on: Oct 8, 2025
 *      Author: tntam
 */
#include "software_timer.h"

int timer_counter[NumOfTimer] = {0};
int timer_flag[NumOfTimer] = {0};
int TICK = 10;

void setTimer(int index, int duration){
	timer_counter[index] = duration / TICK;
	timer_flag[index] = 0;
}

void subTimerRun(int index){
	if(timer_counter[index] > 0){
		timer_counter[index]--;
		if(timer_counter[index] <= 0){
			timer_flag[index] = 1;
		}
	}
}
void timerRun(){
	subTimerRun(0);//led blinky
	subTimerRun(1);//FSM_automatic_run_0 led
	subTimerRun(2);//FSM_automatic_run_1 led
	subTimerRun(4);//counter led_timer_0
	subTimerRun(5);//display 7SEG_0
	subTimerRun(6);//display 7SEG_1
	subTimerRun(7);//counter led_timer_1
	subTimerRun(8);//modify red led_0
	subTimerRun(9);//modify red led_1
}

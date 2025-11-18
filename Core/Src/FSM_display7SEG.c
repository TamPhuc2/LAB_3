/*
 * FSM_display7SEG.c
 *
 *  Created on: Oct 31, 2025
 *      Author: tntam
 */

#include "FSM_display7SEG.h"

int status_7SEG_0 = INIT;
int status_7SEG_1 = INIT;


void FSM_display7SEG_0(){
	switch(status_7SEG_0){
	case INIT:
		status_7SEG_0 = COUNTDOWN_0;
		setTimer(5, 10);
	case COUNTDOWN_0:
		if(timer_flag[5] == 1)
		{
			update7SEG_0(indexLed_0);
			indexLed_0++;
			if(indexLed_0 == 2) indexLed_0 = 0;
			setTimer(5, 250);
		}
		break;
	case LEDMODE2_0:
		led_buffer0[0] = 0;
		led_buffer0[1] = 2;
		if(timer_flag[5] == 1)
		{
			update7SEG_0(indexLed_0);
			indexLed_0++;
			if(indexLed_0 == 2) indexLed_0 = 0;
			setTimer(5, 250);
		}

		break;
	case LEDMODE3_0:
		led_buffer0[0] = 0;
		led_buffer0[1] = 3;
		if(timer_flag[5] == 1)
		{
			update7SEG_0(indexLed_0);
			indexLed_0++;
			if(indexLed_0 == 2) indexLed_0 = 0;
			setTimer(5, 250);
		}
		break;
	case LEDMODE4_0:
		led_buffer0[0] = 0;
		led_buffer0[1] = 4;
		if(timer_flag[5] == 1)
		{
			update7SEG_0(indexLed_0);
			indexLed_0++;
			if(indexLed_0 == 2) indexLed_0 = 0;
			setTimer(5, 250);
		}
		break;
	default:
		break;
	}
}

void FSM_display7SEG_1(){
	switch(status_7SEG_1){
	case INIT:
		status_7SEG_1 = COUNTDOWN_0;
		setTimer(6, 10);
	case COUNTDOWN_0:
		if(timer_flag[6] == 1)
		{
			update7SEG_1(indexLed_1);
			indexLed_1++;
			if(indexLed_1 == 2) indexLed_1 = 0;
			setTimer(6, 250);
		}
		break;
	case LEDMODE2_0:
		//temp_red_timer = modify_red_timer;
		led_buffer1[0] = modify_red_timer / 10;;
		led_buffer1[1] = modify_red_timer % 10;;
		if(timer_flag[6] == 1)
		{
			update7SEG_1(indexLed_1);
			indexLed_1++;
			if(indexLed_1 == 2) indexLed_1 = 0;
			setTimer(6, 250);
		}
		break;
	case LEDMODE3_0:
		led_buffer1[0] = modify_yellow_timer / 10;;
		led_buffer1[1] = modify_yellow_timer % 10;;
		if(timer_flag[6] == 1)
		{
			update7SEG_1(indexLed_1);
			indexLed_1++;
			if(indexLed_1 == 2) indexLed_1 = 0;
			setTimer(6, 250);
		}
		break;
	case LEDMODE4_0:
		led_buffer1[0] = modify_green_timer / 10;;
		led_buffer1[1] = modify_green_timer % 10;;
		if(timer_flag[6] == 1)
		{
			update7SEG_1(indexLed_1);
			indexLed_1++;
			if(indexLed_1 == 2) indexLed_1 = 0;
			setTimer(6 , 250);
		}
		break;
	}
}




////////////////////////////

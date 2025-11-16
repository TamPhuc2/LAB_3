/*
 * FSM_automatic.c
 *
 *  Created on: Oct 30, 2025
 *      Author: tntam
 */

#include "FSM_automatic.h"

//TIMER 1
void FSM_automatic_run_0(){
	switch(TL_status){
	case INIT:
		TL_status = AUTO_RED;
		temp_red_timer = red_timer;
		setTimer(1, red_timer * 1000);
		setTimer(4, 1000);
		break;
	case AUTO_RED:
		setRed_0();
		led_buffer0[0] = temp_red_timer / 10;
		led_buffer0[1] = temp_red_timer % 10;

		//timerRed--
		if(timer_flag[4] == 1)
		{
			temp_red_timer--;
			if(temp_red_timer < 0)
				temp_red_timer = 0;
			setTimer(4, 1000);
		}

		//RED->GREEN
		if(timer_flag[1] == 1)
		{
			TL_status = AUTO_GREEN;
			setTimer(1, green_timer * 1000);
			temp_green_timer = green_timer;
		}
		break;
	case AUTO_GREEN:
		setGreen_0();
		led_buffer0[0] = temp_green_timer / 10;
		led_buffer0[1] = temp_green_timer % 10;

		if(timer_flag[4] == 1)
		{
			temp_green_timer--;
			if(temp_green_timer < 0)
				temp_green_timer = 0;
			setTimer(4, 1000);
		}

		if(timer_flag[1] == 1)
		{
			TL_status = AUTO_YELLOW;
			temp_yellow_timer = yellow_timer;
			setTimer(1, yellow_timer * 1000);
		}

		break;
	case AUTO_YELLOW:
		setYellow_0();
		led_buffer0[0] = temp_yellow_timer / 10;
		led_buffer0[1] = temp_yellow_timer % 10;

		if(timer_flag[4] == 1)
		{
			temp_yellow_timer--;
			if(temp_yellow_timer < 0)
				temp_yellow_timer = 0;
			setTimer(4, 1000);
		}

		if(timer_flag[1] == 1)
		{
			TL_status = AUTO_RED;
			setTimer(1, red_timer * 1000);
			temp_red_timer = red_timer;
		}
		break;
	case MODIFY_RED:
		if(timer_flag[8] == 1)
		{
			Modify_RedLed_0();
			setTimer(8, 250);
		}
		break;
	case MODIFY_YELLOW:
		if(timer_flag[8] == 1)
		{
			Modify_YellowLed_0();
			setTimer(8, 250);
		}
		break;
	case MODIFY_GREEN:
		if(timer_flag[8] == 1)
		{
			Modify_GreenLed_0();
			setTimer(8, 250);
		}
		break;
	default:
		break;
	}
}
//TIMER 2
void FSM_automatic_run_1(){
	switch(TL_status_1){
	case INIT:

		TL_status_1 = AUTO_GREEN;
		temp_green_timer_1 =  green_timer;
		setTimer(2, green_timer * 1000);
		setTimer(7, 1000);

		break;
	case AUTO_RED:
		setRed_1();
		led_buffer1[0] = temp_red_timer_1 / 10;
		led_buffer1[1] = temp_red_timer_1 % 10;

		//timerRed--
		if(timer_flag[7] == 1)
		{
			temp_red_timer_1--;
			if(temp_red_timer_1 < 0)
				temp_red_timer_1 = 0;
			setTimer(7, 1000);
		}
		if(timer_flag[2] == 1)
		{
			TL_status_1 = INIT;
			setTimer(2, green_timer * 1000);
			temp_green_timer_1 = green_timer;
		}
		break;
	case AUTO_GREEN:
		setGreen_1();
		led_buffer1[0] = temp_green_timer_1 / 10;
		led_buffer1[1] = temp_green_timer_1 % 10;

		//green timer--
		if(timer_flag[7] == 1)
		{
			temp_green_timer_1--;
			if(temp_green_timer_1 < 0)
				temp_green_timer_1 = 0;
			setTimer(7, 1000);
		}
		if(timer_flag[2] == 1)
		{
			TL_status_1 = AUTO_YELLOW;
			setTimer(2, yellow_timer * 1000);
			temp_yellow_timer_1 = yellow_timer;
		}
		break;
	case AUTO_YELLOW:
		setYellow_1();
		led_buffer1[0] = temp_yellow_timer_1 / 10;
		led_buffer1[1] = temp_yellow_timer_1 % 10;

		//yellow timer--
		if(timer_flag[7] == 1)
		{
			temp_yellow_timer_1--;
			if(temp_yellow_timer_1 == 0)
				temp_yellow_timer_1 = yellow_timer;
			setTimer(7, 1000);
		}
		if(timer_flag[2] == 1)
		{
			TL_status_1 = AUTO_RED;
			setTimer(2, red_timer * 1000);
			temp_red_timer_1 = red_timer;
		}
		break;
	case MODIFY_RED:
		if(timer_flag[9] == 1)
		{
			Modify_RedLed_1();
			setTimer(9, 250);
		}
		break;
	case MODIFY_YELLOW:
		if(timer_flag[9] == 1)
		{
			Modify_YellowLed_1();
			setTimer(9, 250);
		}
		break;
	case MODIFY_GREEN:
		if(timer_flag[9] == 1)
		{
			Modify_GreenLed_1();
			setTimer(9, 250);
		}
		break;
	default:
		break;
	}
}

void FSM_automatic_run(){
	FSM_automatic_run_0();
	FSM_automatic_run_1();
}

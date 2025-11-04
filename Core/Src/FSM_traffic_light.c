/*
 * FSM_traffic_light.c
 *
 *  Created on: Oct 31, 2025
 *      Author: tntam
 */
#include "main.h"
#include "FSM_traffic_light.h"
#include "FSM_display7SEG.h"

int modify_red_timer;
int modify_green_timer;
int modify_yellow_timer;

void FSM_TL_control_run(){
	switch(mode){
	case INIT:
		mode = MODE_1;
		break;
	case MODE_1: //NORMAL MODE
		if(isButton0Pressed() == 1)
		{
			//switch to mode 2
			mode = MODE_2;
			status_7SEG_0 = LEDMODE2_0;
			status_7SEG_1 = LEDMODE2_0;
			//set modify state for LED
			TL_status = MODIFY_RED;
			TL_status_1 = MODIFY_RED;
			reset_All_Led();
			setTimer(8, 250);
			setTimer(9, 250);
			modify_red_timer = red_timer;


			HAL_GPIO_TogglePin(LED_PINK_GPIO_Port, LED_PINK_Pin);
		}
		if(isButton0PressednHold() == 1)
		{
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		}

		break;
	case MODE_2: // MODIFY RED LEDS
		if(isButton0Pressed() == 1)
		{
			//switch to mode 3
			mode = MODE_3;
			status_7SEG_0 = LEDMODE3_0;
			status_7SEG_1 = LEDMODE3_0;
			//set modify state for LED
			TL_status = MODIFY_YELLOW;
			TL_status_1 = MODIFY_YELLOW;
			reset_All_Led();
			setTimer(8, 250);
			setTimer(9, 250);
			modify_yellow_timer = yellow_timer;

			HAL_GPIO_TogglePin(LED_PINK_GPIO_Port, LED_PINK_Pin);
		}
		//Increase modify_red_timer
		if(isButton1Pressed() == 1)
		{
			modify_red_timer++;
			if(modify_red_timer > 99) modify_red_timer = 1;
		}
		//set red_timer
		if(isButton2Pressed() == 1)
			red_timer = modify_red_timer;
		break;
	case MODE_3:// MODIFY YELLOW LEDS
		if(isButton0Pressed() == 1)
		{
			//switch to mode 4
			mode = MODE_4;
			status_7SEG_0 = LEDMODE4_0;
			status_7SEG_1 = LEDMODE4_0;
			//set modify state for led
			TL_status = MODIFY_GREEN;
			TL_status_1 = MODIFY_GREEN;
			reset_All_Led();
			setTimer(8, 250);
			setTimer(9, 250);
			modify_green_timer = green_timer;

			HAL_GPIO_TogglePin(LED_PINK_GPIO_Port, LED_PINK_Pin);
		}
		//increase modify_yellow_timer
		if(isButton1Pressed() == 1)
		{
			modify_yellow_timer++;
			if(modify_yellow_timer > 99) modify_yellow_timer = 1;
		}
		//set yellow_timer
		if(isButton2Pressed() == 1)
			yellow_timer = modify_yellow_timer;
		break;
	case MODE_4:// MODIFY GREEN LEDS
		if(isButton0Pressed() == 1)
		{
			status_7SEG_0 = COUNTDOWN_0;
			status_7SEG_1 = COUNTDOWN_0;
			mode = MODE_1;
			TL_status = INIT;
			TL_status_1 = INIT;
			status_7SEG_0 = COUNTDOWN_0;
			status_7SEG_1 = COUNTDOWN_0;
			// check valid timer
			if(red_timer < green_timer + yellow_timer)
			{
				red_timer = green_timer + yellow_timer;
			}
			else if(red_timer > green_timer + yellow_timer)
			{
				green_timer = red_timer - yellow_timer;
			}

			HAL_GPIO_TogglePin(LED_PINK_GPIO_Port, LED_PINK_Pin);
		}
		if(isButton0PressednHold())
			HAL_GPIO_TogglePin(LED_PINK_GPIO_Port, LED_PINK_Pin);
		//increase modify_green_timer
		if(isButton1Pressed() == 1)
		{
			modify_green_timer++;
			if(modify_green_timer > 99) modify_green_timer = 1;
		}
		//set green_timer
		if(isButton2Pressed() == 1)
			green_timer = modify_green_timer;
		break;
	default:
		break;
	}
}

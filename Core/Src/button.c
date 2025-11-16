/*
 * button.c
 *
 *  Created on: Oct 8, 2025
 *      Author: tntam
 */

#include "button.h"

//pressed flag
int button0_flag = 0;
int button1_flag = 0;
int button2_flag = 0;

//pressed and hold flag
int button0_flag_hold = 0;
int button1_flag_hold = 0;
int button2_flag_hold = 0;

//KeyReg
int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};//previous stable state

int timerForKeyPress = 200;//press and hold 2second

//pressed
	int isButton0Pressed(){
		if(button0_flag == 1){
			button0_flag = 0;
			return 1;
		}
		return 0;
	}
int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}


//pressed n hold
int isButton0PressednHold(){
	if(button0_flag_hold == 1){
		button0_flag_hold = 0;
		return 1;
	}
	return 0;
}
int isButton1PressednHold(){
	if(button1_flag_hold == 1){
		button1_flag_hold = 0;
		return 1;
	}
	return 0;
}
int isButton2PressednHold(){
	if(button2_flag_hold == 1){
		button2_flag_hold = 0;
		return 1;
	}
	return 0;
}

void getKeyInput0(){
	KeyReg0[0] = KeyReg1[0];
	KeyReg1[0] = KeyReg2[0];
	KeyReg2[0] = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);

	if((KeyReg0[0] == KeyReg1[0]) && (KeyReg1[0] == KeyReg2[0]))
	{
		//press
		if(KeyReg3[0] != KeyReg2[0])
		{
			KeyReg3[0] = KeyReg2[0];
			if(KeyReg2[0] == PRESSED_STATE) //NORMAL_STATE -> PRESSED_STATE
			{
				button0_flag = 1;
				timerForKeyPress = 200;
			}
			else button0_flag = 0;
		}
		//press and hold
//		else
//		{
//			timerForKeyPress--;
//			if(timerForKeyPress <= 0)
//			{
//				button0_flag_hold = 1;
//				KeyReg3[0] = NORMAL_STATE;
//			}
//		}
		else
		{
			if (KeyReg2[0] == PRESSED_STATE) {
				if (timerForKeyPress > 0) {
					timerForKeyPress--;
					if (timerForKeyPress == 0) {
						button0_flag_hold = 1;
					}
				}
			}
		}
	}
}
void getKeyInput1(){
	KeyReg0[1] = KeyReg1[1];
	KeyReg1[1] = KeyReg2[1];
	KeyReg2[1] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

	if((KeyReg0[1] == KeyReg1[1]) && (KeyReg1[1] == KeyReg2[1]))
	{
		//press
		if(KeyReg3[1] != KeyReg2[1])
		{
			KeyReg3[1] = KeyReg2[1];
			if(KeyReg2[1] == PRESSED_STATE) //NORMAL_STATE -> PRESSED_STATE
			{
				button1_flag = 1;
				timerForKeyPress = 200;
			}
			else button1_flag = 0;
		}
		//press and hold
		else
		{
			timerForKeyPress--;
			if(timerForKeyPress <= 0)
			{
				button1_flag_hold = 1;
				KeyReg3[1] = NORMAL_STATE;
			}
		}
	}
}
void getKeyInput2(){
	KeyReg0[2] = KeyReg1[2];
	KeyReg1[2] = KeyReg2[2];
	KeyReg2[2] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);

	if((KeyReg0[2] == KeyReg1[2]) && (KeyReg1[2] == KeyReg2[2]))
	{
		//press
		if(KeyReg3[2] != KeyReg2[2])
		{
			KeyReg3[2] = KeyReg2[2];
			if(KeyReg2[2] == PRESSED_STATE) //NORMAL_STATE -> PRESSED_STATE
			{
				button2_flag = 1;
				timerForKeyPress = 200;
			}
			else button2_flag = 0;
		}
		//press and hold
		else
		{
			timerForKeyPress--;
			if(timerForKeyPress <= 0)
			{
				button2_flag_hold = 1;
				KeyReg3[2] = NORMAL_STATE;
			}
		}
	}
}


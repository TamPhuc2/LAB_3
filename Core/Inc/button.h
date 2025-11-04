/*
 * button.h
 *
 *  Created on: Oct 8, 2025
 *      Author: tntam
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


//flag variables
extern int button0_flag;
extern int button1_flag;
extern int button2_flag;

extern int button0_hold_flag;
extern int button1_hold_flag;
extern int button2_hold_flag;

extern int timerForKeyPress;
//set pressed flag
int isButton0Pressed();
int isButton1Pressed();
int isButton2Pressed();

//set pressed and hold flag
int isButton0PressednHold();
int isButton1PressednHold();
int isButton2PressednHold();


void getKeyInput0();
void getKeyInput1();
void getKeyInput2();

#endif /* INC_BUTTON_H_ */

/*
 * global.h
 *
 *  Created on: Oct 30, 2025
 *      Author: tntam
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "FSM_automatic.h"
#include "FSM_traffic_light.h"
#include "FSM_display7SEG.h"

#define ERROR		0

#define TICKS		10

// ------ mode -----
#define INIT		1
#define AUTO_RED	2
#define AUTO_GREEN	3
#define AUTO_YELLOW 4

#define MODIFY_RED		5
#define MODIFY_YELLOW	6
#define MODIFY_GREEN	7
// -----------------
#define MODE_1		11//Normal mode
#define MODE_2		12//Modify red LEDs mode
#define MODE_3		13//Modify yellow LEDs mode
#define MODE_4		14//Modify green LEDs mode

#define COUNTDOWN_0		20
#define LEDMODE2_0		21
#define LEDMODE3_0		22
#define LEDMODE4_0		23

#define SET_TIME	25

extern int mode;


extern int led_buffer0[2];
extern int led_buffer1[2];

extern int status_7SEG_0;
extern int status_7SEG_1;


//state of traffic light
extern int TL_status;
extern int TL_status_1;

//timer of each light
extern int modify_red_timer;
extern int modify_yellow_timer;
extern int modify_green_timer;

extern int red_timer;
extern int yellow_timer;
extern int green_timer;

extern int temp_red_timer;
extern int temp_yellow_timer;
extern int temp_green_timer;

extern int temp_red_timer_1;
extern int temp_yellow_timer_1;
extern int temp_green_timer_1;


extern int indexLed_0;
extern int indexLed_1;



#endif /* INC_GLOBAL_H_ */

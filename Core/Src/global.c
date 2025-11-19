/*
 * global.c
 *
 *  Created on: Oct 30, 2025
 *      Author: tntam
 */

#include "global.h"

//MODE traffic light
//int mode = MODE_1;//MODE_1 -> MODE_2 -> MODE_3 -> MODE 4 -> MODE_1
int mode = INIT;
//state of traffic light
int TL_status = INIT; //INIT -> RED -> GREEN -> YELLOW
int TL_status_1 = INIT;//INIT -> GREEN -> YELLOW -> RED
int status_7SEG_0 = INIT;
int status_7SEG_1 = INIT;
//timer of each traffic light (second)
int red_timer = 5;
int yellow_timer = 2;
int green_timer = 3;

int temp_red_timer = 5;
int temp_yellow_timer = 2;
int temp_green_timer = 3;

int temp_red_timer_1 = 5;
int temp_yellow_timer_1 = 2;
int temp_green_timer_1 = 3;


int led_buffer0[2] = {0, 0};
int led_buffer1[2] = {0, 0};

int indexLed_0 = 0;
int indexLed_1 = 0;

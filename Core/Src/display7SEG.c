/*
 * display7SEG.c
 *
 *  Created on: Oct 30, 2025
 *      Author: tntam
 */

#include "display7SEG.h"

void display7SEG_0(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		break;
	}
}
void display7SEG_1(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, SET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, SET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, SET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, SET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, SET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, SET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, SET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, SET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, SET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, SET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, SET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, SET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, SET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, SET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, SET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, SET);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, RESET);
		break;
	}
}

void update7SEG_0(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		display7SEG_0(led_buffer0[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		display7SEG_0(led_buffer0[1]);
		break;
	default:
		break;
	}
}
void update7SEG_1(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG_1(led_buffer1[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG_1(led_buffer1[1]);
		break;
	default:
		break;
	}
}



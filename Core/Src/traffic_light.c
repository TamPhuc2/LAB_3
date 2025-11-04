/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2025
 *      Author: tntam
 */

#include "traffic_light.h"

void setRed_0(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
}
void setYellow_0(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
}
void setGreen_0(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
}

void setRed_1(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void setYellow_1(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void setGreen_1(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
}

//TIMER 8
void Modify_RedLed_0(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
}
void Modify_YellowLed_0(){
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
}
void Modify_GreenLed_0(){
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
}

//TIMER 8
void Modify_RedLed_1(){
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void Modify_YellowLed_1(){
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void Modify_GreenLed_1(){
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
}

void reset_All_Led(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);

	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}

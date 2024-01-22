/*
 * pwm2.cpp
 *
 *  Created on: Jan 19, 2024
 *      Author: user
 */

#include "pwm2.h"
#include "stm32g4xx_hal.h"

extern TIM_HandleTypeDef htim3;
int IC1, IC2;
double duty, f;
int PSC = 15;

void setup(){
	HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim -> Channel == HAL_TIM_ACTIVE_CHANNEL_1){
		IC1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
		if(IC1 != 0){
			IC2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);
			duty = (double)(IC2+1)/(IC1+1)*100;
			f = (double)16000000/(PSC+1)/(IC1+1);
		}
	}
}

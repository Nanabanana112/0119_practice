/*
 * pwm.cpp
 *
 *  Created on: Jan 19, 2024
 *      Author: user
 */

#include "pwm.h"
#include "stm32g4xx_hal.h"
extern TIM_HandleTypeDef htim2;

void pwm_gnr(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

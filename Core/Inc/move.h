#ifndef __MOVE_H__
#define __MOVE_H__

#define L1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)
#define R1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)
#define L2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)
#define R2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11)

#include "stm32f1xx.h"
#include "pwm.h"
#include "pid.h"

void move(void);

#endif

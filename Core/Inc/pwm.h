#ifndef __PWM_H__
#define __PWM_H__

#include "stm32f1xx_hal.h"
#include "tim.h"
#include "gpio.h"

void pwm_Init(void);
void set_motor_pwm(uint32_t channel,uint32_t target);
void set_servo_pwm(uint32_t angle);

#endif

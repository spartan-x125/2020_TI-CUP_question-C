#ifndef __PID_H__
#define __PID_H__

#include "tim.h"
#include"stm32f1xx_hal.h"

void pid_Init(void);
int32_t pid_Cal(uint16_t LR,int32_t target);

#endif

#ifndef __LED_H__
#define __LED_H__
#include "stm32f10x.h"

void LED_Init(void);
void LED_On(uint8_t LED_Number);
void LED_Turn(uint8_t LED_Number);
void LED_Off(uint8_t LED_Number);

#endif

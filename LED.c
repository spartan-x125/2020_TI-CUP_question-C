#include "stm32f1xx.h"                  // Device header
#include "stdint.h"


//初始化
void LED_Init(void)
{
	//设置位1
	GPIO_SetBits(GPIOA,GPIO_PIN_All);
}

//选取位置0 ->IO
//GPIO口选择
void LED_On(uint8_t LED_Number)
{	
	if(LED_Number == 0)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_0);
	}
	if(LED_Number == 1)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_1);
	}
	if(LED_Number == 2)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_2);
	}
	if(LED_Number == 3)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_3);
	}
	if(LED_Number == 4)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_4);
	}
	if(LED_Number == 5)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_5);
	}
	if(LED_Number == 6)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_6);
	}
	if(LED_Number == 7)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_7);
	}
	if(LED_Number == 8)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_8);
	}
	if(LED_Number == 9)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_9);
	}
	if(LED_Number == 10)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_10);
	}
	if(LED_Number == 11)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_11);
	}
	if(LED_Number == 12)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_12);
	}
	if(LED_Number == 13)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_13);
	}
	if(LED_Number == 14)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_14);
	}
	if(LED_Number == 15)
	{
	GPIO_ResetBits(GPIOA,GPIO_PIN_15);
	}

}
//置1
void LED_Off(uint8_t LED_Number)
{	
	if(LED_Number == 0)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_0);
	}
	if(LED_Number == 1)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_1);
	}
	if(LED_Number == 2)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_2);
	}
	if(LED_Number == 3)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_3);
	}
	if(LED_Number == 4)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_4);
	}
	if(LED_Number == 5)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_5);
	}
	if(LED_Number == 6)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_6);
	}
	if(LED_Number == 7)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_7);
	}
	if(LED_Number == 8)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_8);
	}
	if(LED_Number == 9)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_9);
	}
	if(LED_Number == 10)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_10);
	}
	if(LED_Number == 11)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_11);
	}
	if(LED_Number == 12)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_12);
	}
	if(LED_Number == 13)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_13);
	}
	if(LED_Number == 14)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_14);
	}
	if(LED_Number == 15)
	{
	GPIO_SetBits(GPIOA,GPIO_PIN_15);
	}
}

//  1 | 0转换
void LED_Turn(uint8_t LED_Number)
{	
	if(LED_Number ==0)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_PIN_0) ==0)
		{
		GPIO_SetBits(GPIOA,GPIO_PIN_0);
		}else{
		GPIO_ResetBits(GPIOA,GPIO_PIN_0);
		}
	}
	if(LED_Number ==1)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_PIN_1) ==0)
		{
		GPIO_SetBits(GPIOA,GPIO_PIN_1);
		}else{
		GPIO_ResetBits(GPIOA,GPIO_PIN_1);
		}
	}
	if(LED_Number ==2)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_PIN_2) ==0)
		{
		LED_Off(2);
		}else{
		LED_On(2);
		}
	}
	if(LED_Number ==11)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_PIN_2) ==0)
		{
		LED_Off(11);
		}else{
		LED_On(11);
		}
	}

}

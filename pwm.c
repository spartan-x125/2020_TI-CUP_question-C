#include "pwm.h"

/**
 * @brief pwm初始化
 */
void pwm_Init(){
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
    //HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
}

/**
 * @brief 设置占空比驱动电机
 * @param channel 通道
 * @param target 目标占空比值
 */
void set_motor_pwm(uint32_t channel,uint32_t target){
    __HAL_TIM_SET_COMPARE(&htim1,channel,target);
}

/**
 * @brief 设置舵机角度
 * @param angle 舵机角度
 */
/*
void set_servo_pwm(uint32_t angle){
    uint32_t duty;
    duty=((double)angle/18+2.5)/100*2000;
    __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,duty);
}
*/

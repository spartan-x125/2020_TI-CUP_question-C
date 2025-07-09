#include "move.h"

extern int32_t TargetEncoder;

#define speed1 60
#define speed2 30


/**
 * @brief 直线行驶
 */
void go_straight(void){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,pid_Cal(0,TargetEncoder));
    set_motor_pwm(TIM_CHANNEL_4,pid_Cal(1,TargetEncoder));
}

/**
 * @brief 停车
 */
void stop(void){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,pid_Cal(0,0));
    set_motor_pwm(TIM_CHANNEL_4,pid_Cal(1,0));
}

void turn_left(int speed){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,pid_Cal(1,TargetEncoder+speed));
    set_motor_pwm(TIM_CHANNEL_4,pid_Cal(0,TargetEncoder));
}

void turn_right(int speed){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,pid_Cal(0,TargetEncoder+speed));
    set_motor_pwm(TIM_CHANNEL_4,pid_Cal(1,TargetEncoder));
}

/**
 * @brief 小车开始运行
 */
void move(void){
    //set_servo_pwm(90);
    if(L2==1&&R2==1){
        go_straight();
    }
    if(L1==1&&R1==R2==0){
        turn_left(speed1);
    }
    if(L2==1&&R1==R2==0){
        turn_left(speed2);
    }
    if(R1==1&&L1==L2==0){
        turn_right(speed1);
    }
    if(R2==1&&L1==L2==0){
        turn_right(speed2);
    }
    if(L1==R1==L2==R2==0)stop();
}

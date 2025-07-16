#include "move.h"

extern double TargetEncoder;
double LTargetEncoder,RTargetEncoder;

#define speed1 30
#define speed2 10
//转向中对编码器值的调整

extern int32_t lpwm,rpwm;

/**
 * @brief 直线行驶
 */
void go_straight(double speed){
    LTargetEncoder=TargetEncoder,RTargetEncoder=TargetEncoder;
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,lpwm);
    set_motor_pwm(TIM_CHANNEL_4,rpwm);
}

/**
 * @brief pwm刹车
 */
void pwm_stop(void){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,0);
    set_motor_pwm(TIM_CHANNEL_4,0);
}

/**
 * @brief 电机刹车
 */
void motor_stop(void){
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
}

void turn_left(double speed){
    LTargetEncoder+=speed;
    RTargetEncoder-=speed;
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,lpwm);
    set_motor_pwm(TIM_CHANNEL_4,rpwm);
}

void turn_right(double speed){
    LTargetEncoder-=speed;
    RTargetEncoder+=speed;
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    set_motor_pwm(TIM_CHANNEL_3,lpwm);
    set_motor_pwm(TIM_CHANNEL_4,rpwm);
}

/**
 * @brief 小车开始运行
 */
int move(void){
    uint8_t GO[2]={0x47,0x4F},LEFT[4]={0x4C,0x45,0x46,0x54},RIGHT[5]={0x52,0x49,0x47,0x48,0x54},STOP[4]={0x53,0x54,0x4F,0x50};
    lpwm=pid_Cal(0,LTargetEncoder);
    rpwm=pid_Cal(1,RTargetEncoder);
    OLED_PrintNumber(85,30,lpwm,&afont8x6,OLED_COLOR_NORMAL);
    OLED_PrintNumber(85,40,rpwm,&afont8x6,OLED_COLOR_NORMAL);
    OLED_ShowFrame();
    if(L1==0&&R1==0&&L2==0&&R2==0){
        motor_stop();
        HAL_UART_Transmit(&huart2,STOP,sizeof(STOP),HAL_TIMEOUT);
        return 1;
    }
    //if(L2==0&&R2==0&&L1==1&&R1==1){
        //go_straight();
    //}
    else if(L1==0&&R1==1&&R2==1){
        turn_left(speed1);
        HAL_UART_Transmit(&huart2,LEFT,sizeof(LEFT),HAL_TIMEOUT);
    }
    else if(L2==0&&R1==1&&R2==1){
        turn_left(speed2);
        //HAL_UART_Transmit(&huart2,LEFT,sizeof(LEFT),HAL_TIMEOUT);
        OLED_PrintASCIIString(50,50,"left",&afont8x6,OLED_COLOR_NORMAL);
        OLED_ShowFrame();
    }
    else if(R1==0&&L1==1&&L2==1){
        turn_right(speed1);
        HAL_UART_Transmit(&huart2,RIGHT,sizeof(RIGHT),HAL_TIMEOUT);
        OLED_PrintASCIIString(50,50,"right",&afont8x6,OLED_COLOR_NORMAL);
        OLED_ShowFrame();
    }
    else if(R2==0&&L1==1&&L2==1){
        turn_right(speed2);
        //HAL_UART_Transmit(&huart2,RIGHT,sizeof(RIGHT),HAL_TIMEOUT);
    }
    else {
        go_straight(TargetEncoder);
        //HAL_UART_Transmit(&huart2,GO,sizeof(GO),HAL_TIMEOUT);
    }
    return 0;
}

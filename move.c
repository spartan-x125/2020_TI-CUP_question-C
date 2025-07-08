#include "move.h"

extern int32_t TargetEncoder;

#define angle1 30
#define angle2 60


/**
 * @brief 直线行驶
 */
void go_straight(void){
    set_motor_pwm(TIM_CHANNEL_3,pid_Cal(0,TargetEncoder));
    set_motor_pwm(TIM_CHANNEL_4,pid_Cal(1,TargetEncoder));
}

/**
 * @brief 停车
 */
void stop(void){
    set_motor_pwm(TIM_CHANNEL_3,pid_Cal(0,0));
    set_motor_pwm(TIM_CHANNEL_4,pid_Cal(1,0));
}

void turn(speed){
    set_motor_pwm()
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
        //set_servo_pwm(angle1);
    }
    if(L2==1&&R1==R2==0){
        //set_servo_pwm(angle2);
    }
    if(R1==1&&L1==L2==0){
        //set_servo_pwm(180-angle1);
    }
    if(R2==1&&L1==L2==0){
        //set_servo_pwm(180-angle2);
    }
    if(L1==R1==L2==R2==0)stop();
}

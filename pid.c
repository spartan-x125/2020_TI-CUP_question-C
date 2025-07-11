#include "pid.h"

typedef struct {
    __IO uint16_t target;
    __IO uint16_t lasterror,preverror;
}pid;

#define P_value 12
#define I_value 3
#define D_value 2
//pid参数

#define return_value 1
//pid计算编码器转数->pwm占空比的比例系数

#define Left 0
#define Right 1

extern int32_t TargetEncoder;//目标编码器数值
int16_t LEncoder,REncoder;//左右编码器实际值
int16_t Lpwm,Rpwm;//返回的pwm值
pid Lpidval,Rpidval;
pid *Lpid=&Lpidval,*Rpid=&Rpidval;


/**
 * @brief pid初始化
 */
void pid_Init(void){
    HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
    Lpid->target=TargetEncoder;
    Rpid->target=TargetEncoder;
    Lpid->lasterror=0;Lpid->preverror=0;
    Rpid->lasterror=0;Rpid->preverror=0;
}

/**
 * @brief 计算pid
 * @param LR 区分左侧或右侧电机
 * @param target pid目标编码器数值
 */
int32_t pid_Cal(uint16_t LR,int32_t target){//pid计算
    int32_t error,ans;pid *tpid;
    if(LR==Left){
        LEncoder=__HAL_TIM_GET_COUNTER(&htim2);
        error=target-LEncoder;
        tpid=Lpid;
    }
    else{
        REncoder=__HAL_TIM_GET_COUNTER(&htim3);
        error=target-REncoder;
        tpid=Rpid;
    }
    ans=P_value*(error-tpid->lasterror)+I_value*error+D_value*(error-2*tpid->lasterror+tpid->preverror);
    tpid->preverror=tpid->lasterror;
    tpid->lasterror=error;
    return ans*return_value;
}

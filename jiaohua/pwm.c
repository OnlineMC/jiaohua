#include <STC15F2K60S2.H>
#include "typedef.h"

#define PWM_CYCLE 41536.0

sbit pwmpin = P0^0;

float high_t,low_t;

void Timer0Init(void)		//2000微秒@12.000MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	T2H = (65536 - (uint8_t)(PWM_CYCLE*high_t)) / 256;
	T2L = (65536 - (uint8_t)(PWM_CYCLE*high_t)) % 256;
	TF0 = 0;		//清除TF0标志
	
	ET0 = 1;
	EA = 1;
	TR0 = 1;		//定时器0开始计时
}


void pwm_write(float duty_cycle){
	
	pwmpin = 1;
	
	high_t = duty_cycle * 0.1;
	low_t = 1.0 - high_t;
	
	Timer0Init();
}

void Timer0Int() interrupt 1{
	
	if(pwmpin){
		pwmpin = 0;
		T2H = (65536 - (uint8_t)(PWM_CYCLE*low_t)) / 256;
		T2L = (65536 - (uint8_t)(PWM_CYCLE*low_t)) % 256;
	}else{
		//否则 填装高电平
		pwmpin = 1;
		T2H = (65536 - (uint8_t)(PWM_CYCLE*high_t)) / 256;
		T2L = (65536 - (uint8_t)(PWM_CYCLE*high_t)) % 256;
	}

}
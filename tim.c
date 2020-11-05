#include "STC15F2K60S2.H"
#include "tim.h"
#include "delay.h"

void Cls_Peripheral(void)
{
  P0 = 0xFF;
  P2 = P2 & 0x1F | 0x80;			// P27~P25清零，再定位Y4C
  P2 &= 0x1F;						// P27~P25清零
  P0 = 0;
  P2 = P2 & 0x1F | 0xA0;			// P27~P25清零，再定位Y5C
  P2 &= 0x1F;						// P27~P25清零
}

/*
void Timer1Init(void)		//1毫秒@12.000MHz
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x18;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时


	ET1 = 1;		//补：打开定时器1中断
	EA = 1;			//补：打开系统总中断

}
*/

//配置串口 波特率9600
/*
void Timer1Init()
{
	TMOD=0x20;			//定时器1确定工作方式2（8位自动重装）
	TH1=0xfd;			//装入初值，高八位低八位相同，根据波特率计算，此时为9600
	TL1=0xfd;
	TR1=1;
	
	SCON=0x50;			//确定工作方式1，并打开接收使能REN
	AUXR=0x00;			//12分频
	
	EA=1;
	ES=1;
	
}
*/

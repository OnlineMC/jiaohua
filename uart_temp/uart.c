#include <STC15F2K60S2.H>
#include "typedef.h"

void uart_init(void)		//9600bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	TL1 = 0xC7;		//设定定时初值
	TH1 = 0xFE;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	IE = 0x90;
	TR1 = 1;		//启动定时器1
}


void send_byte(unsigned char x){
	
	SBUF=x;
	while(TI==0);
	TI=0;
}

void send_string(char *s){
	
	while(*s){
		send_byte(*s++);
	}
	
}

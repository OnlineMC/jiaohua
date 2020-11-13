#include <STC15F2K60S2.H>
#include "typedef.h"

void uart_init(void)		//9600bps@12.000MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��1ʱ��ΪFosc,��1T
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ
	TL1 = 0xC7;		//�趨��ʱ��ֵ
	TH1 = 0xFE;		//�趨��ʱ��ֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	IE = 0x90;
	TR1 = 1;		//������ʱ��1
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

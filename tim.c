#include "STC15F2K60S2.H"
#include "tim.h"
#include "delay.h"

void Cls_Peripheral(void)
{
  P0 = 0xFF;
  P2 = P2 & 0x1F | 0x80;			// P27~P25���㣬�ٶ�λY4C
  P2 &= 0x1F;						// P27~P25����
  P0 = 0;
  P2 = P2 & 0x1F | 0xA0;			// P27~P25���㣬�ٶ�λY5C
  P2 &= 0x1F;						// P27~P25����
}

/*
void Timer1Init(void)		//1����@12.000MHz
{
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0x18;		//���ö�ʱ��ֵ
	TH1 = 0xFC;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ


	ET1 = 1;		//�����򿪶�ʱ��1�ж�
	EA = 1;			//������ϵͳ���ж�

}
*/

//���ô��� ������9600
/*
void Timer1Init()
{
	TMOD=0x20;			//��ʱ��1ȷ��������ʽ2��8λ�Զ���װ��
	TH1=0xfd;			//װ���ֵ���߰�λ�Ͱ�λ��ͬ�����ݲ����ʼ��㣬��ʱΪ9600
	TL1=0xfd;
	TR1=1;
	
	SCON=0x50;			//ȷ��������ʽ1�����򿪽���ʹ��REN
	AUXR=0x00;			//12��Ƶ
	
	EA=1;
	ES=1;
	
}
*/

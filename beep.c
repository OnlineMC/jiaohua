#include <STC15F2K60S2.H>
#include "boolean.h"
#include "hc138.h"
#include "delay.h"

sbit BEEP = P0^6;

//bb: �������ͣ�true�������죬flase��������
void set_beep(bool bb){
	
	//ѡ��Y5C�����Կ�����������Ӧ���ӵ���ULN2003������оƬ��������������
	chip_sel(BUFFER);
	P0 = 0x00;
	BEEP = bb;
	chip_sel(LED_BUS);
	P0 = 0xFF;
}
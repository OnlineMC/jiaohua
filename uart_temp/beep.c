#include <STC15F2K60S2.H>
#include "boolean.h"
#include "hc138.h"
#include "delay.h"

sbit BEEP = P0^6;
bool b_status;

//bb: 布尔类型，true蜂鸣器响，flase蜂鸣器关
void set_beep(bool bb){
	
	//选中Y5C引脚以控制锁存器对应连接到的ULN2003缓冲器芯片用于驱动蜂鸣器
	chip_sel(BUFFER);
	P0 = 0x00;
	BEEP = bb;
	b_status = bb;
	chip_sel(LED_BUS);
	P0 = 0xFF;
}

void togg_beep(){

	set_beep(!b_status);
}
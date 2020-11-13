#include <STC15F2K60S2.H>
#include "uart.h"
#include "typedef.h"
#include "delay.h"
#include "tim.h"
#include "hc138.h"
#include "seg.h"
#include "stdio.h"
#include "dkey.h"
#include "iic.h"
#include "onewire.h"
#include "beep.h"
#include "boolean.h"


uint8_t temp,last_temp;
uint8_t seg_data[9];
uint16_t currtime = 30000;
uint16_t beep_lasttime,t,bt,dis_beep_time;
bool en_beep = true;

void init(){
	
	Cls_Peripheral();
	uart_init();
	Timer0Init();
	//读ROM里保存的温度阈值数据
	EEPROM_READ(&temp, 0, 1);
	last_temp = temp;
	
}

void mode1(){
	
	uint8_t ctemp = rd_temperature()/16.0;
	
	//刷新数码管显示
	sprintf(seg_data, "%02dC  %02dC", (uint16_t)temp, (uint16_t)ctemp);
	//sprintf(seg_data, "%08u", (uint16_t)currtime);
	seg_display(seg_data);
	
	
	//处理按键
	if(s6_is_pressed()){
		if(++temp >= 99) temp = 99;
	}else if(s5_is_pressed()){
		if(temp-- <= 0) temp = 0;
	}else if(s4_is_pressed()){
		
		if(en_beep){
			en_beep = false;
			set_beep(false);
			dis_beep_time = currtime;
		}
		
	}
	
	
	//阈值温度被更新了
	if(temp != last_temp){
		
		//检查温度合法性
		if(temp >= 99){
			temp = 99;
		}
		
		if(temp <= 0){
			temp = 0;
		}
		
		//更新阈值温度值并写入ROM中
		last_temp = temp;
		EEPROM_WRITE(&temp, 0, 1);
	}
	

	
	//是否达到提醒温度
	if(ctemp < temp){
		t = currtime - beep_lasttime;
		if(t < 0)t = t + 65535;
		
		//蜂鸣器是否已经警用
		if(!en_beep){
			bt = currtime - dis_beep_time;
			if(bt < 0)bt = bt + 65535;
			//是否已经禁用超过5秒
			if(bt >= 5000){
				//启用蜂鸣器
				en_beep = true;
			}
		}
		
		if(t >= 500 && en_beep){
			beep_lasttime = currtime;
			togg_beep();
		}
	}else{
		set_beep(false);
	}

	
}

void main(){

	init();
	while(1){
		mode1();
	}

}

void uart_int() interrupt 4
{
		
    if(RI){
			temp = SBUF;
			RI = 0;			
		}
    
    if(TI){
			TI = 0;
    }

}

void timer0_int() interrupt 1{
	currtime++;
}
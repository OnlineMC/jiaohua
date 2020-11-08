#include "STC15F2K60S2.H"
#include "stdio.h"
#include "tim.h"
#include "delay.h"
#include "typedef.h"
#include "hc138.h"
#include "led.h"
#include "seg.h"
#include "iic.h"
#include "boolean.h"
#include "dkey.h"
#include "onewire.h"
#include "beep.h"


uint8_t s[9] = "-1- 0120";


//记录时间切换档位 默认：120秒（1档）
uint8_t sec_mode = 1;
//可以读取光敏电阻的数值了
uint8_t pr_can_proc = 1;

uint8_t led_flip_flag;
bool led_flag;

//模式一里的倒计时计数器
uint16_t sec,sec_count,pr_count,led_flip_count;

bool en_beep;

void init(){
	
	Cls_Peripheral();
	Timer1Init();
	//UARTInit();
	
	chip_sel(BUFFER);
	P0 = 0x00;
	chip_sel(LED_BUS);
	P0 = 0xFF;

}

/*
void SentByte(uint8_t x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}
*/

void mode1(){
	
	sec = 120;
	
	while(1){
		sprintf(s, "-1- 0%03d", sec);
		seg_display(s);
		
		if(led_flip_flag){
		
			led_flip_flag = 0;
			set_led1(led_flag);
			
		}
		
		//S4按键被按下，退出函数
		if(s4_is_pressed()){
			led_flag = false;
			seg_clean();
			set_beep(false);
			return;
		}
		
		//如果s5按键被按下，调整时间
		if(s5_is_pressed()){

			switch(sec_mode){
				case(0):
					sec_mode = 1;
					sec = 120;
					break;
				case(1):
					sec_mode = 2;
					sec = 240;
					break;
				default:
					sec_mode = 0;
					sec = 0;
			}

		}
	}

}

void mode2(){

	uint8_t pr_val;
	uint16_t temp;
	while(1){
		
		
		//如果读光敏电阻的标志=1 说明可以刷新数值了(顺便也可以把DS18B20的温度读了)
		if(pr_can_proc){
			pr_can_proc = 0;
			pr_val = PCF891_Adc();
			
			temp = (uint16_t)(rd_temperature()/16.0)+0.5;
			
		}
		

		
		//+0.5四舍五入 没毛病
		sprintf(s, "%03d  %02dC", (uint16_t)pr_val, temp);
		//sprintf(s, "FFFFFFFF");
		seg_display(s);
		
		if(led_flip_flag){
		
			led_flip_flag = 0;
			set_led2(led_flag);
		}
		
		
		//S4按键被按下，退出函数
		if(s4_is_pressed()){
			led_flag = false;
			seg_clean();
			set_beep(false);
			return;
		}
	}
	
	

}


void main(){
	
	init();
	P0 = 0xFF;
	
	while(1){
		//led_flow();
		
		
		mode2();
		mode1();
	
	}
	
}


void timer1_int() interrupt 3{
	
	if(++sec_count >= 1000){
		sec_count = 0;
		if(sec > 0){
			sec--;
		}
	}
	
	if(++pr_count >= 500){
		pr_count = 0;
		pr_can_proc = 1;
	}
	
	if(++led_flip_count >= 500){
		led_flag = !led_flag;
		led_flip_flag = 1;
		led_flip_count = 0;
	}

}

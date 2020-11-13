#include "STC15F2K60S2.H"
#include "delay.h"
#include "typedef.h"
#include "hc138.h"
#include "led.h"
#include "boolean.h"

sbit led1 = P0^0;
sbit led2 = P0^1;
sbit led3 = P0^2;

void led_flow(){

	uint8_t i;
	
	chip_sel(LED_BUS);
	for(i=0 ; i<8 ; i++){

		P0 = ~(0x01<<i);
		delayms(500);
	}
	
}

//led_bit: 要点亮的LED位，1~8
//status: true点亮led_bit位的LED，false直接关闭所有位的LED
void set_led1(bool status){

	chip_sel(LED_BUS);
	P0 = 0xFF;
	delayms(1);
	led1 = status;
}

void set_led2(bool status){

	chip_sel(LED_BUS);
	P0 = 0xFF;
	delayms(1);
	led2 = status;
}

void set_led3(bool status){

	chip_sel(LED_BUS);
	P0 = 0xFF;
	delayms(1);
	led3 = status;
}
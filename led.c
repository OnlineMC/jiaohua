#include "STC15F2K60S2.H"
#include "delay.h"
#include "typedef.h"
#include "hc138.h"

void led_flow(){

	uint8_t i;
	
	chip_sel(LED_BUS);
	for(i=0 ; i<8 ; i++){

		P0 = ~(0x01<<i);
		delayms(500);
	}
	
}
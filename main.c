#include "STC15F2K60S2.H"
#include "tim.h"
#include "delay.h"
#include "typedef.h"
#include "hc138.h"
#include "led.h"
#include "seg.h"
#include "key.h"


sbit LED = P0^0;
sbit S4 = P3^3;

uint8_t s[9] = "-1- 0120";
uint8_t key_value,mode,key_read_tim_count,key_read_flag;

void init(){
	
	Cls_Peripheral();
	//Timer1Init();
	reset_sel();

}

/*
void SentByte(uint8_t x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}
*/

void main(){
	
	init();
	P0 = 0xFF;
	
	while(1){
		seg_display(s);
	
		// °´ÏÂ°´¼ü
		/*
		if(!S4){
			mode++;
			SentByte(mode);
			
		}
		*/
	
	}
	
}

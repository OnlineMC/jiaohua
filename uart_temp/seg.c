#include <STC15F2K60S2.H>
#include "hc138.h"
#include "typedef.h"
#include "delay.h"

void seg_display(unsigned char *str){
	
	uint8_t i;
	
	//位选0（所有数码管都不亮）
	chip_sel(SEG_SEL);
	P0 = 0x00;

	for(i=0 ; i<8 ; i++){
		
		
		//写段码
		chip_sel(SEG_BUS);
		//清空数码管显示(消隐)
		P0 = 0xFF;
		switch(str[i])
		{
			case '0': P0 = 0xC0; break;
			case '1': P0 = 0xF9; break;			
			case '2': P0 = 0xA4; break;
			case '3': P0 = 0xB0; break;
			case '4': P0 = 0x99; break;
			case '5': P0 = 0x92; break;
			case '6': P0 = 0x82; break;
			case '7': P0 = 0xF8; break;	
			case '8': P0 = 0x80; break;			
			case '9': P0 = 0x90; break;
			
			case 'A': P0 = 0x88; break;	
			case 'B': P0 = 0x83; break;
			case 'C': P0 = 0xC6; break;	
			case 'D': P0 = 0xA1; break;			
			case 'E': P0 = 0x86; break;
			case 'F': P0 = 0x8E; break;				
		
			case 'H': P0 = 0x89; break;	
			case 'L': P0 = 0xC7; break;
			case 'N': P0 = 0xC8; break;	
			case 'P': P0 = 0x8C; break;			
			case 'U': P0 = 0xC1; break;
			case '-': P0 = 0xBF; break;		
			case ' ': P0 = 0xFF; break;
			default: P0 = 0xFF; break;						
		}
		
		//位选
		chip_sel(SEG_SEL);
		P0 = 0x01 << i;
		
		//显示该位1ms
		delayms(1);
		
		//写段码
		chip_sel(SEG_BUS);
		//清空数码管显示(消隐)
		P0 = 0xFF;
	}

}

void seg_clean(){
	chip_sel(SEG_BUS);
	P0 = 0xFF;
}
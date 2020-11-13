#include <STC15F2K60S2.H>
#include "typedef.h"
#include "hc138.h"

sbit LSA = P2^5;
sbit LSB = P2^6;
sbit LSC = P2^7;

//片选74HC138译码器的引脚
//selbit:选中的引脚位
void chip_sel(uint8_t selbit){

	LSA = selbit & 0x01;
	LSB = (selbit >> 1) & 0x01;
	LSC = (selbit >> 2) & 0x01;

}

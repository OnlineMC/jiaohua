#include <STC15F2K60S2.H>
#include "boolean.h"
#include "delay.h"

sbit S4 = P3^3;
sbit S5 = P3^2;

//s4 ���������£�
bool s4_is_pressed(){
	
		if(!S4){
			delayms(10);
			if(!S4){
				delayms(200);
				return true;
			}
		}
		
		return false;
}

//s5 ���������£�
bool s5_is_pressed(){
	
		if(!S5){
			delayms(10);
			if(!S5){
				delayms(200);
				return true;
			}
		}
		
		return false;
}
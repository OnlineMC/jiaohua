#include <STC15F2K60S2.H>
#include "boolean.h"
#include "delay.h"

sbit S4 = P3^3;
sbit S5 = P3^2;
sbit S6 = P3^1;

//s4 按键被按下？
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

//s5 按键被按下？
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

//s6 按键被按下？
bool s6_is_pressed(){
	
		if(!S6){
			delayms(10);
			if(!S6){
				delayms(200);
				return true;
			}
		}
		
		return false;
}
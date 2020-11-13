#include <STC15F2K60S2.H>
#include "boolean.h"
#include "delay.h"

sbit S4 = P3^3;
sbit S5 = P3^2;
sbit S6 = P3^1;
sbit S7 = P3^0;

//s4 按键被按下？
bool s4_is_pressed(){
	
		if(!S4){
			delayms(1);
			while(!S4);
			return true;
		}
		
		return false;
}

//s5 按键被按下？
bool s5_is_pressed(){
	
		if(!S5){
			delayms(1);
			while(!S5);
			return true;
		}
		
		return false;
}

bool s6_is_pressed(){
	
		if(!S6){
			delayms(1);
			while(!S6);
			return true;
		}
		
		return false;
}

bool s7_is_pressed(){
	
		if(!S7){
			delayms(1);
			while(!S7);
			return true;
		}
		
		return false;
}
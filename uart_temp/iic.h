#ifndef _IIC_H
#define _IIC_H
#include "STC15F2K60S2.h"

void IIC_Start(void); 
void IIC_Stop(void);  
bit IIC_WaitAck(void);  
void IIC_SendAck(bit ackbit); 
void IIC_SendByte(unsigned char byt); 
unsigned char IIC_RecByte(void); 

unsigned char PCF891_Adc(void);
unsigned char PCF891_Dac(unsigned char dat);
	
void EEPROM_READ(unsigned char *pucBuf, unsigned char addr, unsigned char num);
void EEPROM_WRITE(unsigned char *pucBuf, unsigned char addr, unsigned char num);

#endif
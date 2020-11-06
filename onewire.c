#include "onewire.h"

sbit DQ = P1^4;

////单总线延时函数
void Delay_OneWire(unsigned int t)  
{
	unsigned char i;
	while(t--){
		for(i=0;i<12;i++);
	}
}

void Delay_us(void)
{
	unsigned char i;

	i = 30;
	while (--i);
}

//通过单总线向DS18B20写一个字节
void Write_DS18B20(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		DQ = 0;
		DQ = dat&0x01;
		Delay_OneWire(5);
		DQ = 1;
		dat >>= 1;
	}
	Delay_OneWire(5);

}

//从DS18B20读取一个字节
unsigned char Read_DS18B20(void)
{
	unsigned char i;
	unsigned char dat;
//	unsigned char index = 0;
  	   	
	for(i=0;i<8;i++)
	{
		DQ = 0;
		dat >>= 1;
		DQ = 1; 
	   	Delay_us();

		if(DQ)  
		{
			dat |= 0x80;
		}	    
		Delay_OneWire(5);
	}
	return dat;
}

//DS18B20初始化
bit init_ds18b20(void)
{
  	bit initflag = 0;
  	
  	DQ = 1;
  	Delay_OneWire(12);
  	DQ = 0;

  	Delay_OneWire(80); // 延时大于480us
  	DQ = 1;
  	Delay_OneWire(10);  // 14
  	initflag = DQ;     // initflag等于1初始化失败
  	Delay_OneWire(5);
  
  	return initflag;
}

//DS18B20温度采集程序
unsigned int rd_temperature(void)
{
	unsigned char low,high;
	
	init_ds18b20();
	Write_DS18B20(0xCC);
	Write_DS18B20(0x44);	
  
	init_ds18b20();
	Write_DS18B20(0xCC);
	Write_DS18B20(0xBE);	
	
	low=Read_DS18B20();
	high=Read_DS18B20();

	return (high<<8)+low;
	
}


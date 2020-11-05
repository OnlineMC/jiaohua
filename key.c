#include "STC15F2K60S2.H"
#include "key.h"

unsigned char Key_Read(void)
{ 
	unsigned int Key_New;
	unsigned char Key_Val;

	P44 = 0; P42 = 1; P35 = 1; P34 = 1;   //ɨ���1�� 
	Key_New = (P3 & 0x0f);
	P44 = 1; P42 = 0; P35 = 1; P34 = 1;   //ɨ���2��
	Key_New = ((Key_New<<4) | (P3 & 0x0f));
	P44 = 1; P42 = 1; P35 = 0; P34 = 1;   //ɨ���3��
	Key_New = ((Key_New<<4) | (P3 & 0x0f));
	P44 = 1; P42 = 1; P35 = 1; P34 = 0;   //ɨ���4��
	Key_New = ((Key_New<<4) | (P3 & 0x0f));

	switch (~Key_New)
	{
		case 0x8000: Key_Val = 4; break;  //S*��Key_Valֵ���Ӧ
		case 0x4000: Key_Val = 5; break;  //S*��Key_Valֵ���Ӧ	
		case 0x2000: Key_Val = 6; break;  //S*��Key_Valֵ���Ӧ
		case 0x1000: Key_Val = 7; break;  //S*��Key_Valֵ���Ӧ	
		case 0x0800: Key_Val = 8; break;  //S*��Key_Valֵ���Ӧ
		case 0x0400: Key_Val = 9; break;  //S*��Key_Valֵ���Ӧ	
		case 0x0200: Key_Val = 10; break;  //S*��Key_Valֵ���Ӧ
		case 0x0100: Key_Val = 11; break;  //S*��Key_Valֵ���Ӧ	
		case 0x0080: Key_Val = 12; break;  //S*��Key_Valֵ���Ӧ
		case 0x0040: Key_Val = 13; break;  //S*��Key_Valֵ���Ӧ	
		case 0x0020: Key_Val = 14; break;  //S*��Key_Valֵ���Ӧ
		case 0x0010: Key_Val = 15; break;  //S*��Key_Valֵ���Ӧ	
		case 0x0008: Key_Val = 16; break;  //S*��Key_Valֵ���Ӧ
		case 0x0004: Key_Val = 17; break;  //S*��Key_Valֵ���Ӧ	
		case 0x0002: Key_Val = 18; break;  //S*��Key_Valֵ���Ӧ
		case 0x0001: Key_Val = 19; break;  //S*��Key_Valֵ���Ӧ	
		default : Key_Val = 0;	
	}
	return Key_Val;
}






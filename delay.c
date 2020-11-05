#include "delay.h"

void delayms(int b)
{
	int i;
	long a;
	for(i=b;i>0;i--)
		for(a=110;a>0;a--);
	
}


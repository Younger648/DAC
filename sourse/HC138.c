#include "head.h"



void HC138(unsigned char n)
{
	switch(n)
	{
		case 4:
			P2 = (P2 & 0x1f) | 0x80;
		break;
		
		case 5:
			P2 = (P2 & 0x1f) | 0xa0;
		break;
				
		case 6:
			P2 = (P2 & 0x1f) | 0xc0;
		break;
						
		case 7:
			P2 = (P2 & 0x1f) | 0xe0;
		break;
								
		case 0:
			P2 = (P2 & 0x1f) | 0x00;
		break;
	}
}


void SMG_config(unsigned char adr,unsigned dat)
{
	P0 = 0xff;
	HC138(6);
	P0 = adr;
	
	Delay_OneWire(1);
	HC138(7);
	P0 = dat;
}


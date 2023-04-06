#include "head.h"


unsigned P0_DAT = 0xff;

void LED_config(unsigned char led_adr,unsigned char led_dat)
{
	
	if(led_dat == 0)
	{
		P0_DAT |= 0x01 <<(led_adr - 1);
	}
	else
	{
		P0_DAT &= ~(0x01 <<(led_adr - 1));
	}
	
	P0 = P0_DAT;
}






void LED_temp()
{
	static unsigned char i = 0;
	static unsigned char i_flag = 0;
	
	HC138(4);
	if(temper > refer*10)
	{
	i ++;
	if(i == 100)
	{
		i = 0;
		i_flag = ~i_flag;
		if(i_flag)
		{
			LED_config(1,0);
		}
		else
		{
			LED_config(1,1);
		}
	}

	}
		else
		LED_config(1,0);
		
		HC138(0);//∑¿÷πledª“∞µ

}













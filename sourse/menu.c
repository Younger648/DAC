#include "head.h"


unsigned char Scon = 1;



void Delay5ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 59;
	j = 90;
	do
	{
		while (--j);
	} while (--i);
}


void menu()//主菜单界面
{
	if(Scon == 1)
	ds18b20_show();
	else if(Scon == 2)
	ds1302_show();
	else if(Scon == 3)
	refer_show();
}






void menu_key()//主菜单按键
{
	key(1);
	if(C4 == 0)
	{
		Delay5ms();
		if(C4 == 0)
		{
			Scon ++;
			if(Scon == 4)
				{
					Scon = 1;
				}
		}
		while(C4 == 0);
	}
		
}







void refer_key()//参数按键增加和减少
{
	key(3);
	if(C4 == 0)
	{
		Delay5ms();
		if(C4 == 0)
		{
			refer ++;
		}
		while(C4 == 0);
	}
	
	
	
	key(4);
	if(C4 == 0)
	{
		Delay5ms();
		if(C4 == 0)
		{
			refer --;
		}
		while(C4 == 0);
	}
	
	
	
	
	
	
/*******参数限制*******/	
	if(refer >= 99)
	{
		refer = 99;
	}
	
	
	if(refer <= 9)
	{
		refer = 9;
	}
}







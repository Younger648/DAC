#include "head.h"




void Timer0Init()		//1毫秒@12.000MHz
{

	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	
	
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	
	TF0 = 0;		//清除TF0标志
	
	EA = 1;
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	
	
}



void ServiceTimer0() interrupt 1
{
	
	
	
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	
	ds1302_show();
	
//  P0 = 0xff;//一定要给关闭led放在138之前
//	LED_temp();
//	menu();
//	jidianqi_a();

}


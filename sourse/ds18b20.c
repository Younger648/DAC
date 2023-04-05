#include "head.h"

unsigned int temper;//±ÿ–Î”√int–Õ


void ds18b20_config()
{
	unsigned char LSB,HSB;
	
	EA = 0;
	init_ds18b20();
	EA = 1;
	
	Write_DS18B20(0xcc);
	Write_DS18B20(0x44);
	
	Delay_OneWire(10000);
	
	EA = 0;
	init_ds18b20();
	EA = 1;
	
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);
	
	LSB = Read_DS18B20();
	HSB = Read_DS18B20();
	
	
	temper = HSB;
	temper = (temper << 8) | LSB;
	
	if((temper & 0xF800) ==0x0000)
	{
		temper >>= 4;
		temper = temper * 10;
		temper = temper + (LSB & 0x0f) * 0.625;
	
	}

}
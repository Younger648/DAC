#include "head.h"

/****************此处数组是变量值，不可以加code**********************/
unsigned char write_adr[7] = {0x80,0x82,0x84,0x86,0x88,0x8a,0x8c};
unsigned char read_adr[7] = {0x81,0x83,0x85,0x87,0x89,0x8b,0x8d};
unsigned char Time[7] = {0x29,0x01,0x15,0x01,0x01,0x01,0x22};



void Write_ds1302_config()
{
	static unsigned char i;
	Write_Ds1302_Byte(0x8e,0x00);
	
	for(i=0;i<7;i++)
	{
		Write_Ds1302_Byte(write_adr[i],Time[i]);
	}
	Write_Ds1302_Byte(0x8e,0x80);
}



void Read_ds1302_config()
{
	static unsigned char i;
	
	for(i=0;i<7;i++)
	{
		Time[i] = Read_Ds1302_Byte (read_adr[i]);
	}

}
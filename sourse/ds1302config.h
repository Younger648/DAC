#ifndef __DS1302CONFIG_H_
#define __DS1302CONFIG_H_


extern unsigned char write_adr[7];
extern unsigned char read_adr[7];
extern unsigned char Time[7];


void Write_ds1302_config();
void Read_ds1302_config();


#endif
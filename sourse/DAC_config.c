#include "head.h"



//void DAC_output(unsigned char dat)
//{
//	I2CStart();
//	
//	I2CSendByte(0x90);
//	I2CWaitAck();
//	
//	I2CSendByte(0x43);
//	I2CWaitAck();
//	
//	I2CSendByte(dat);
//	I2CWaitAck();
//	
//	I2CStop();
//}







unsigned int read_8951()
{
	unsigned char channel_1,channel_3;
	
	I2CStart();
	I2CSendByte(0x90);
	I2CWaitAck();
	
	I2CSendByte(0x04);
	I2CWaitAck();
	
	I2CStart();
	I2CSendByte(0x91);
	I2CWaitAck();
	
	channel_1 = I2CReceiveByte();
	I2CSendAck(0);
	
	I2CReceiveByte();
	I2CSendAck(0);
	
	channel_3 = I2CReceiveByte();
	I2CSendAck(0);
	
	I2CReceiveByte();
	
	I2CStop();
	
	return channel_1 << 8 | channel_3;
	
}




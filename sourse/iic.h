#ifndef __IIC_H_
#define __IIC_H_


static void I2C_Delay(unsigned char n);
void I2CStart(void);
void I2CStop(void);
void I2CSendByte(unsigned char byt);
void I2CSendAck(unsigned char ackbit);

extern unsigned char I2CReceiveByte(void);
extern unsigned char I2CWaitAck(void);

#endif
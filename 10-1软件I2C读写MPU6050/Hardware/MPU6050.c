#include "stm32f10x.h"                  // Device header
#include "MyI2C.h"
void MPU6050_Init()
{
	MyI2C_Init();
	
}
#define address1 0xD0
void MPU6050_write(uint8_t address2 ,uint8_t value)
{
	MyI2C_Start();
	MyI2C_SendBite(address1);
	MyI2C_ReceiveACK();
	MyI2C_SendBite(address2);
	MyI2C_ReceiveACK();
	MyI2C_SendBite(value);
	MyI2C_ReceiveACK();
	MyI2C_Stop();
	
}
uint8_t MPU6050_read(uint8_t address2)
{
	uint8_t value;
	MyI2C_Start();
	MyI2C_SendBite(address1);
	MyI2C_ReceiveACK();
	MyI2C_SendBite(address2);
	MyI2C_ReceiveACK();
	MyI2C_Start();
	MyI2C_SendBite(address1 | 0x01); 
	MyI2C_ReceiveACK();
	value = MyI2C_ReceiveBite();
	MyI2C_SendACK(1);
	MyI2C_Stop();
	return value;
}


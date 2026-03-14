#include "stm32f10x.h"                  // Device header
void MPU6050_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_10 | GPIO_Pin_11);
	I2C_InitTypeDef I2C_InitStructure;
	I2C_InitStructure.I2C_Mode=I2C_Mode_I2C;
	I2C_InitStructure.I2C_Ack=I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed=500000;
	I2C_InitStructure.I2C_DutyCycle=I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1=0x00;
	I2C_Init(I2C2,&I2C_InitStructure);
}
void MPU6050_WaitEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT)
{
	while(I2C_CheckEvent(I2Cx,I2C_EVENT)!=SUCCESS)
	{
		uint32_t TimeOut;
		TimeOut = 10000;
		TimeOut--;
		if(TimeOut==0)
		{
			break;
			
		}
	}
	
}
#define address1 0xD0
void MPU6050_write(uint8_t address2 ,uint8_t value)
{
	I2C_GenerateSTART(I2C2,ENABLE);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT);
	I2C_Send7bitAddress(I2C2,address1,I2C_Direction_Transmitter);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED);
	I2C_SendData(I2C2,address2);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTING);
	I2C_SendData(I2C2,value);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTED);
	I2C_GenerateSTOP(I2C2,ENABLE);
}
uint8_t MPU6050_read(uint8_t address2)
{
	I2C_GenerateSTART(I2C2,ENABLE);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT);
	I2C_Send7bitAddress(I2C2,address1,I2C_Direction_Transmitter);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED);
	I2C_SendData(I2C2,address2);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTING);
	I2C_GenerateSTART(I2C2,ENABLE);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT);
	I2C_Send7bitAddress(I2C2,address1,I2C_Direction_Receiver);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_RECEIVED);
	I2C_AcknowledgeConfig(I2C2,DISABLE);
	I2C_GenerateSTOP(I2C2,ENABLE);
	uint8_t Data;
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_RECEIVED);
	Data=I2C_ReceiveData(I2C2);
	return Data;
}


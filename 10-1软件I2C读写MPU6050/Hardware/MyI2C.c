#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void MyI2C_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, GPIO_Pin_10 | GPIO_Pin_11);
}
void MyI2C_W_SCL(uint8_t value)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)value);

}
void MyI2C_W_SDA(uint8_t value)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)value);

}
uint8_t MyI2C_R_SDA()
{
	uint8_t value;
	value=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
	
	return value;
}
void MyI2C_Start()
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}
void MyI2C_Stop()
{
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);
}
void MyI2C_SendBite(uint8_t value)
{
	uint8_t i;
	uint8_t Byte;
	for(i=0;i<8;i++)
	{
		Byte=value & (0x80>>i);
		MyI2C_W_SDA(Byte);
		MyI2C_W_SCL(1);
		MyI2C_W_SCL(0);
	}
}
uint8_t MyI2C_ReceiveBite()
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	uint8_t i;
	uint8_t Byte = 0x00;
	for(i=0;i<8;i++)
	{
		if(MyI2C_R_SDA()==1)
		{
			Byte |= (0x80>>i);
		}
		MyI2C_W_SCL(0);
	}
	return Byte;
}
void MyI2C_SendACK(uint8_t Byte)
{
	MyI2C_W_SDA(Byte);
	MyI2C_W_SCL(1);
	MyI2C_W_SCL(0);
}
uint8_t MyI2C_ReceiveACK()
{
	uint8_t Byte;
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	Byte = MyI2C_R_SDA();
	MyI2C_W_SCL(0);
	return Byte;
}

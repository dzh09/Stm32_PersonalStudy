#include "stm32f10x.h"                  // Device header
void MYSPI_W_CS(uint8_t Bit)
{
	 GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)Bit);
}
void MYSPI_W_CLK(uint8_t Bit)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)Bit);
}
void MYSPI_W_MISO(uint8_t Bit)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)Bit);
}
uint8_t MYSPI_R_MISO()
{
	 return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
}
void MYSPI_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	MYSPI_W_CS(1);
	MYSPI_W_CLK(0);
	
}
void MYSPI_Start()
{
	MYSPI_W_CS(0);
	
}
void MYSPI_Stop()
{
	
	MYSPI_W_CS(1);
}
uint8_t MYSPI_Swap(uint8_t ByteSend)
{
	uint8_t i;
	uint8_t ByteReceive = 0x00;
	
	for(i=0;i<8;i++)
	{
		 MYSPI_W_MISO(ByteSend&(0x80>>i));
		MYSPI_W_CLK(1);
		if(MYSPI_R_MISO()==1)
		{
			ByteReceive|=(0x80>>i);
		}
		MYSPI_W_CLK(0);
	}
	return ByteReceive;
}

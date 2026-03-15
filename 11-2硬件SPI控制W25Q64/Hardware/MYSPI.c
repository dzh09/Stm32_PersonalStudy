#include "stm32f10x.h"                  // Device header
void MYSPI_W_CS(uint8_t Bit)
{
	 GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)Bit);
}
void MYSPI_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	SPI_InitTypeDef SPI_InitStructure;
	SPI_InitStructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_128;
	SPI_InitStructure.SPI_CPHA=SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_CPOL=SPI_CPOL_Low;
	SPI_InitStructure.SPI_CRCPolynomial=7;
	SPI_InitStructure.SPI_DataSize=SPI_DataSize_8b;
	SPI_InitStructure.SPI_FirstBit=SPI_FirstBit_LSB;
	SPI_InitStructure.SPI_Mode=SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS=SPI_NSS_Soft;
	MYSPI_W_CS(1);
	
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
	while(SPI_I2S_GetITStatus(SPI1,SPI_I2S_IT_TXE)!=SET);
	SPI_I2S_SendData(SPI1,ByteSend);
	while(SPI_I2S_GetITStatus(SPI1,SPI_I2S_IT_RXNE)!=SET);
	SPI_I2S_ReceiveData(SPI1);
	
}

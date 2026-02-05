#include "stm32f10x.h"                  // Device header

void Init_Serial(void)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate=9600;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Tx;
	USART_InitStructure.USART_Parity= USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
}

uint16_t Serial_SendBite(uint16_t data)
{
	USART_SendData(USART1,data);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}
void Serial_SendArray(uint8_t *Array,uint8_t length)
{
	for(int i = 0;i < length;i++)
	{
		 Serial_SendBite(Array[i]);
		
	}
}
void Serial_SendString(char *String)
{
	for(int i = 0;String[i]!='\0';i++)
	{
		Serial_SendBite(String[i]);
		
	}
}

uint32_t Serial_Pow(uint16_t X,uint16_t Y)
{
	uint32_t result=1;
	while(Y--)
	{
		result*=X;
	}
	return result;
}
void serial_SendNum(uint32_t number ,uint16_t length)
{
	for(uint8_t i = 0;i<length;i++)
	{
		Serial_SendBite(number/Serial_Pow(10,length-i-1)%10);
	}
	
}

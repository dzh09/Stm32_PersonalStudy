#include "stm32f10x.h"                  // Device header
uint8_t RXFlag;
uint8_t RXTDATA[4];
uint8_t TXTDATA[4];
void Init_Serial(void)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate=9600;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStructure.USART_Parity= USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
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
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)
	{
		uint8_t RXData = USART_ReceiveData(USART1);
		static uint8_t Status;
		uint8_t PRXData;
		if(Status == 0)
		{
			if(RXData == 0xFF)
			{
				Status=1;
				PRXData=0;
			}
			
		}
		else if(Status == 1)
		{
			RXTDATA[PRXData]=RXData;
			PRXData++;
			if(PRXData > 4)
			{
				Status = 2;
				
			}
		}
		else if(Status == 2)
		{
			if(RXData==0xFE)
			{
				Status=0;
				RXFlag=1;
			}
			
		}
		
	}
	
}

uint8_t Serial_RXFlag()
{
	if(RXFlag==1)
	{
		RXFlag=0;
		return 1;
	}
	return 0;
}
void Serial_SendHEX(void)
{
	Serial_SendBite(0xFF);
	Serial_SendArray(TXTDATA,4);
	Serial_SendBite(0xFE);
	
}
void Serial_ReadHEX(void)
{
	
	
}
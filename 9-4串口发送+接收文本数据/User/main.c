#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "SERIAL.h"
#include "LED.h"
#include "string.h"
uint8_t data;

int main(void)
{
	OLED_Init();
	Init_Serial();
	LED_Init();
	
	
	while(1)
	{
		if(Serial_RXFlag()==1)
		{
			OLED_ShowString(4,1,"RXDATA[]");
			
		if(strcmp(RXTDATA,"LED1_ON")==0)
		{
			OLED_ShowString(2,1,"RXDATA[]");
			Serial_SendString("LED_ON_OK\r\n");
		}
		else if(strcmp(RXTDATA,"LED1_OFF")==1)
		{
			OLED_ShowString(2,1,"RXDATA[]");
			Serial_SendString("LED_OFF_OK\r\n");
		}
		else 
		{
			OLED_ShowString(2,1,"ERRO");
			Serial_SendString("ERRO\r\n");
			
		}
		}
	}
 	
}



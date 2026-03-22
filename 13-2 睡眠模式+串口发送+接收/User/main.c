#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "SERIAL.h"
uint8_t data;
int main(void)
{
	OLED_Init();
	Init_Serial();
	//uint8_t MyArray[]={0x41,0x42,0x43,0x44};
	//Serial_SendBite(0x41);
	//Serial_SendArray(MyArray,4);
	//Serial_SendString("helloworld!\r\n");
	//serial_SendNum(14456,5);
	OLED_ShowString(1,1,"RXdata");
	while(1)
	{
		if(Serial_RXFlag()==1)
		{
			data = Serial_RXDATA();
			Serial_SendBite(data);
			OLED_ShowHexNum(1,1,data,8);
			
		}
			OLED_ShowString(2,1,"Running");
			Delay_ms(100);
			OLED_ShowString(2,1,"       ");
			Delay_ms(100);
			__WFI();
	}
 	
}



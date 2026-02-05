#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "SERIAL.h"
int main(void)
{
	OLED_Init();
	Init_Serial();
	//uint8_t MyArray[]={0x41,0x42,0x43,0x44};
	//Serial_SendBite(0x41);
	//Serial_SendArray(MyArray,4);
	//Serial_SendString("helloworld!\r\n");
	serial_SendNum(14456,5);
	while(1)
	{
		
	}
 	
}




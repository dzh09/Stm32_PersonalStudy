#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "SERIAL.h"
#include "Key.h"
uint8_t data;
uint8_t KeyNum;
int main(void)
{
	OLED_Init();
	Init_Serial();
	Key_Init();
	//uint8_t MyArray[]={0x41,0x42,0x43,0x44};
	//Serial_SendBite(0x41);
	//Serial_SendArray(MyArray,4);
	//Serial_SendString("helloworld!\r\n");
	//serial_SendNum(14456,5);
	TXTDATA[0]=0x01;
	TXTDATA[1]=0x02;
	TXTDATA[2]=0x03;
	TXTDATA[3]=0x04;
	Serial_SendHEX();
	KeyNum=Key_GetNum();
	while(1)
	{
		if(Key_GetNum()==1)
		{
		TXTDATA[0]++;
		TXTDATA[1]++;
		TXTDATA[2]++;
		TXTDATA[3]++;
		Serial_SendHEX();
			
		}
		if(Serial_RXFlag()==1)
		{
			OLED_ShowHexNum(1,1,RXTDATA[0],2);
			OLED_ShowHexNum(1,4,RXTDATA[1],2);
			OLED_ShowHexNum(1,7,RXTDATA[2],2);
			OLED_ShowHexNum(1,10,RXTDATA[3],2);
		}
	}
 	
}



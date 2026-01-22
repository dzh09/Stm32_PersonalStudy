#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "ENCODER.h"
uint8_t i;
int main(void)
{
	OLED_Init();
	
	
	
	while(1)
	{
		OLED_ShowString(1,1,"Encoder:");
		OLED_ShowNum(1,9,Encoder_Get(),5);
	
	}
	
}




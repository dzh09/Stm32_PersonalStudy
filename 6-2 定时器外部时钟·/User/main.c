#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
uint16_t Num;
int main(void)
{
	OLED_Init();
	Timer_Init();
	
	OLED_ShowString(2,1,"Num:");
	OLED_ShowString(3,1,"CAT:");
	
	while(1)
	{
		OLED_ShowNum(2,5,Num,4);
		OLED_ShowNum(3,5,Timer_GetCounter(),5);
	
	
	}
	
}




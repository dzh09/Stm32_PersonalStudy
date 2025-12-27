#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
int16_t Num;
int main(void)
{
	OLED_Init();
	OLED_ShowString(1,1,"helloworld");
	while(1)
	{
		Num+=Get_Num();
		OLED_ShowSignedNum(2,1,Get_Num(),4);
	}
	
}




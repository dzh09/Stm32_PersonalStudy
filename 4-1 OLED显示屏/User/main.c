#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
int main(void)
{
	OLED_Init();
	OLED_ShowChar(1,1,'a');
	OLED_ShowString(2,1,"Helloworld");
	OLED_ShowNum(1,3,12345,5);
	OLED_ShowBinNum(4,1,0xAA,16);
	OLED_ShowHexNum(3,1,0xAA,2);
	OLED_ShowSignedNum(2,13,-66,2);
	while(1)
	{
		
	}
	
}




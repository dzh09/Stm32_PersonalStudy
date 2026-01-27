#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
int main(void)
{
	uint16_t ADC_Value;
	OLED_Init();
    AD_Init();
	OLED_ShowString(1,1,"ADC:");
	
	while(1)
	{
		ADC_Value=Get_ADCValue();
		OLED_ShowNum(1,5,ADC_Value,4);
	}
	
}




#include "stm32f10x.h" // Device header
#include "OLED.h"
#include "CountSensor.h"
#include "Delay.h"
int main(void)
{
	OLED_Init();
	 Count_Sensor_Init();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	OLED_ShowString(2,1,"Count:");
	while(1)
	{
		OLED_ShowNum(2,7,Get_Count(),4);
		OLED_ShowString(3,1,"Running");
		Delay_ms(100);
		OLED_ShowString(3,1,"       ");
		Delay_ms(100);
		PWR_EnterSTOPMode(PWR_Regulator_ON,PWR_STOPEntry_WFI);
		SystemInit();
	}
	
}





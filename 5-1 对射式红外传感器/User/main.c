#include "stm32f10x.h" // Device header
#include "OLED.h"
#include "CountSensor.h"
int main(void)
{
	OLED_Init();
	 Count_Sensor_Init();
	
	OLED_ShowString(2,1,"Count:");
	while(1)
	{
		OLED_ShowNum(2,7,Get_Count(),4);
	}
	
}





#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "MYRTC.h"
int main(void)
{
	OLED_Init();
	MYRTC_Init();
	OLED_ShowString(1,1,"Date:XXXX-XX-XX");
	OLED_ShowString(2,1,"Time:XX:XX:XX");
	OLED_ShowString(3,1,"CNT:");
	
	while(1)
	{
		MYRTC_ReadTime();
		OLED_ShowNum(1,6,MYRTC_Time[0],4);
		OLED_ShowNum(1,11,MYRTC_Time[1],2);
		OLED_ShowNum(1,14,MYRTC_Time[2],2);
		OLED_ShowNum(2,6,MYRTC_Time[3],2);
		OLED_ShowNum(2,9,MYRTC_Time[4],2);
		OLED_ShowNum(2,12,MYRTC_Time[5],2);
		OLED_ShowNum(3,6,RTC_GetCounter(),10);
	}
	
}




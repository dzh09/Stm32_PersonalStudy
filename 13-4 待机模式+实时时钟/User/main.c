#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "MYRTC.h"
int main(void)
{
	OLED_Init();
	MYRTC_Init();
	OLED_ShowString(1,1,"CNT:");
	OLED_ShowString(2,1,"ALR");
	OLED_ShowString(3,1,"ALFR:");
	uint32_t Alarm = RTC_GetCounter();
	RTC_SetAlarm(Alarm);
	OLED_ShowHexNum(2,6,Alarm,10);
	PWR_WakeUpPinCmd(ENABLE);
	while(1)
	{
		MYRTC_ReadTime();
		
		OLED_ShowNum(1,6,RTC_GetCounter(),10);
		OLED_ShowNum(3,6,RTC_GetFlagStatus(RTC_FLAG_ALR),10);
		
		OLED_ShowString(4,1,"Running");
		Delay_ms(100);
		OLED_ShowString(4,1,"       ");
		Delay_ms(100);
		OLED_ShowString(4,9,"STANDBY");
		Delay_ms(100);
		OLED_ShowString(4,9,"       ");
		Delay_ms(100);
		
		OLED_Clear();
		PWR_EnterSTANDBYMode();
	}
	
}




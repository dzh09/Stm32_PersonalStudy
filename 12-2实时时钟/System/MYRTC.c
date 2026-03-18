#include "stm32f10x.h"                  // Device header
#include "time.h"
uint16_t MYRTC_Time[]={2026, 3, 18, 20, 32, 10};
void MYRTC_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	PWR_BackupAccessCmd(ENABLE);
	RCC_LSEConfig(RCC_LSE_ON);
	RTC_GetITStatus(RCC_FLAG_LSERDY);
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	RCC_RTCCLKCmd(ENABLE);
	RTC_WaitForSynchro();
	RTC_WaitForLastTask();
	
	RTC_SetPrescaler(32768 - 1);
	RTC_WaitForLastTask();
	RTC_SetCounter(1773832330);
	RTC_WaitForLastTask();
	
}
void MYRTC_SetTime(void)
{
	time_t time_cnt;
	struct tm time_date;
	time_date.tm_year=MYRTC_Time[0]-1900;
	time_date.tm_mon=MYRTC_Time[1]-1;
	time_date.tm_yday=MYRTC_Time[2];
	time_date.tm_hour=MYRTC_Time[3];
	time_date.tm_min=MYRTC_Time[4];
	time_date.tm_sec=MYRTC_Time[5];
	time_cnt = mktime(&time_date);
	RTC_SetCounter(time_cnt);

}
void MYRTC_ReadTime(void)
{
	time_t time_cnt;
	struct tm time_date;
	time_cnt = RTC_GetCounter();
	time_date = *localtime(&time_cnt);
	MYRTC_Time[0] = time_date.tm_year+1900;
	MYRTC_Time[1] = time_date.tm_mon+1;
	MYRTC_Time[2]=time_date.tm_yday;
	MYRTC_Time[3]=time_date.tm_hour;
	MYRTC_Time[4]=time_date.tm_min;
	MYRTC_Time[5]=time_date.tm_sec;
	
	
}

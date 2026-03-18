#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "Key.h"
uint16_t writeArray[]={0x1234,0x5678};
uint16_t readArray[2];
int main()
{
	
	OLED_Init();
	Key_Init();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	PWR_BackupAccessCmd(ENABLE);
	OLED_ShowString(1,1,"W:");
	OLED_ShowString(2,1,"R:");
	
	while(1)
	{
		uint8_t KeyNum = Key_GetNum();
		if(KeyNum==1)
		{
			BKP_WriteBackupRegister(BKP_DR1,writeArray[0]);
			BKP_WriteBackupRegister(BKP_DR2,writeArray[1]);
			OLED_ShowHexNum(1,4,writeArray[0],4);
			OLED_ShowHexNum(1,9,writeArray[1],4);
			writeArray[0]++;
			writeArray[1]++;
		}
			readArray[0]=BKP_ReadBackupRegister(BKP_DR1);
			readArray[1]=BKP_ReadBackupRegister(BKP_DR2);
			OLED_ShowHexNum(2,4,readArray[0],4);
			OLED_ShowHexNum(2,9,readArray[1],4);
	}
}




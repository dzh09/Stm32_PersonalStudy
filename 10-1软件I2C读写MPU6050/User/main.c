#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
int main()
{
	OLED_Init();
	MPU6050_Init();
	MPU6050_write(0x6B,0x00);
	MPU6050_write(0x19,0xAA);
	uint8_t ID = MPU6050_read(0x19);
	OLED_ShowNum(1,1,ID,2);
}




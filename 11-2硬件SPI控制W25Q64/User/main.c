#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "W25Q64.h"
#include "MYSPI.h"
uint8_t MID;
uint16_t DID;
uint8_t WriteDataArray[]={0x01,0x02,0x03,0x04};
uint8_t ReadDataArray[4];
int main()
{
	W25Q64_Init();
	OLED_Init();
	OLED_ShowString(1,1,"MID:");
	OLED_ShowString(1,8,"DID:");
	OLED_ShowString(2,1,"W:");
	OLED_ShowString(2,1,"R:");
	W25Q64_ReadID(&MID,&DID);
	OLED_ShowHexNum(1,5,MID,2);
	OLED_ShowHexNum(1,12,DID,4);
	W25Q64_SectorErase(0x00000000);
	W25Q64_PageProgram(0x00000000,WriteDataArray,4);
	W25Q64_ReadData(0x000000000,ReadDataArray,4);
	OLED_ShowHexNum(2,3,WriteDataArray[0],2);
	OLED_ShowHexNum(2,6,WriteDataArray[0],2);
	OLED_ShowHexNum(2,9,WriteDataArray[0],2);
	OLED_ShowHexNum(2,12,WriteDataArray[0],2);
	OLED_ShowHexNum(3,3,ReadDataArray[0],2);
	OLED_ShowHexNum(3,6,ReadDataArray[0],2);
	OLED_ShowHexNum(3,9,ReadDataArray[0],2);
	OLED_ShowHexNum(3,12,ReadDataArray[0],2);
	
	while(1)
	{
		
	}
}




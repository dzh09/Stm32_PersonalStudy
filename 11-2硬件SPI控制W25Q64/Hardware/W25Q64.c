#include "stm32f10x.h"                  // Device header
#include "MYSPI.h"
#include "W25Q64_Ins.h"
void W25Q64_Init(void)
{
	MYSPI_Init();
	
}
void W25Q64_ReadID(uint8_t *MID ,uint16_t *DID)
{
	MYSPI_Start();
	MYSPI_Swap(W25Q64_JEDEC_ID);
	*MID=MYSPI_Swap(W25Q64_DUMMY_BYTE);
	*DID=MYSPI_Swap(W25Q64_DUMMY_BYTE);
	*DID <<= 8;
	*DID |= MYSPI_Swap(W25Q64_DUMMY_BYTE);
	MYSPI_Stop();
	
}
void W25Q64_WriteEnable(void)
{
	MYSPI_Start();
	MYSPI_Swap(W25Q64_WRITE_ENABLE);
}
void W25Q64_WaitBusy()
{
	uint32_t Timeout = 100000;
	MYSPI_Start();
	MYSPI_Swap(W25Q64_READ_STATUS_REGISTER_1);
	while((MYSPI_Swap(W25Q64_DUMMY_BYTE)&0x01)==0x01)
	{
		Timeout--;
		if(Timeout==0)
		{
			break;
		}
		
	}
	MYSPI_Stop();
	
}
void W25Q64_PageProgram(uint32_t Address,uint8_t *WriteDataArray,uint8_t Count)
{
	W25Q64_WriteEnable();
	uint8_t i;
	MYSPI_Start();
	MYSPI_Swap(W25Q64_PAGE_PROGRAM);
	MYSPI_Swap(Address>>16);
	MYSPI_Swap(Address>>8);
	MYSPI_Swap(Address);
	for(i=0;i<Count;i++)
	{
		MYSPI_Swap(WriteDataArray[i]);
	}
	MYSPI_Stop();
	W25Q64_WaitBusy();
}
void W25Q64_SectorErase(uint32_t Address)
{
	W25Q64_WriteEnable();
	MYSPI_Start();
	MYSPI_Swap(W25Q64_SECTOR_ERASE_4KB);
	MYSPI_Swap(Address>>16);
	MYSPI_Swap(Address>>8);
	MYSPI_Swap(Address);
	MYSPI_Stop();
	W25Q64_WaitBusy();
}
void W25Q64_ReadData(uint32_t Address,uint8_t *ReadDataArray,uint32_t Count)
{
	uint32_t i;
	MYSPI_Start();
	MYSPI_Swap(W25Q64_READ_DATA);
	MYSPI_Swap(Address>>16);
	MYSPI_Swap(Address>>8);
	MYSPI_Swap(Address);
	for(i=0;i<Count;i++)
	{
		ReadDataArray[i]=MYSPI_Swap(W25Q64_DUMMY_BYTE);
	}
	MYSPI_Stop();
}

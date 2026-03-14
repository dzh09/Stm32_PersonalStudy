#ifndef __MYSPI_H
#define __MYSPI_H
void MYSPI_W_CS(uint8_t Bit);
void MYSPI_W_CLK(uint8_t Bit);
void MYSPI_W_MISO(uint8_t Bit);
uint8_t MYSPI_R_MISO();
void MYSPI_Init();
void MYSPI_Start();
void MYSPI_Stop();
uint8_t MYSPI_Swap(uint8_t ByteSend);
#endif

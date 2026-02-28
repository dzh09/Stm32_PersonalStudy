#ifndef __MYI2C_H
#define __MYI2C_H
void MyI2C_Init();
void MyI2C_W_SCL(uint8_t value);
void MyI2C_W_SDA(uint8_t value);
uint8_t MyI2C_R_SDA();
void MyI2C_Start();
void MyI2C_Stop();
void MyI2C_SendBite(uint8_t value);
uint8_t MyI2C_ReceiveBite();
void MyI2C_SendACK(uint8_t Byte);
uint8_t MyI2C_ReceiveACK();

#endif

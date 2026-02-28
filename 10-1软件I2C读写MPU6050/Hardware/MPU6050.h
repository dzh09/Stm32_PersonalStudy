#ifndef __MPU6050_H
#define __MPU6050_H
void MPU6050_Init();
#define address1 0xD0;
void MPU6050_write(uint8_t address2 ,uint8_t value);
uint8_t MPU6050_read(uint8_t address2);
#endif

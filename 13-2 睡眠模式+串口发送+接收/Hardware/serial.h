#ifndef __SERIAL_H
#define __SERIAL_H
uint16_t Serial_SendBite(uint16_t data);
void Init_Serial(void);
void Serial_SendArray(uint8_t *Array,uint8_t length);
void Serial_SendString(char *String);
uint32_t Serial_Pow(uint16_t X,uint16_t Y);
void serial_SendNum(uint32_t number ,uint16_t length);
void USART1_IRQHandler(void);
uint8_t Serial_RXDATA();
uint8_t Serial_RXFlag();
#endif

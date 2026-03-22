#ifndef __MYRTC_H
#define __MYRTC_H
void MYRTC_SetTime(void);
void MYRTC_ReadTime(void);
extern uint16_t MYRTC_Time[];
void MYRTC_Init();
#endif

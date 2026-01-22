#include "stm32f10x.h"                  // Device header

void Init_Encoder(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInit_Structure;
	TIM_TimeBaseInit_Structure.TIM_ClockDivision=0;
	TIM_TimeBaseInit_Structure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit_Structure.TIM_Period=65535 - 1;
	TIM_TimeBaseInit_Structure.TIM_Prescaler= 1 -1 ;
	TIM_TimeBaseInit_Structure.TIM_RepetitionCounter=100;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInit_Structure);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter=0xF;
	TIM_ICInitStructure.TIM_ICPolarity= TIM_ICPolarity_Rising;
	
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter=0xF;
	TIM_ICInitStructure.TIM_ICPolarity= TIM_ICPolarity_Rising;
	
	TIM_ICInit(TIM3,&TIM_ICInitStructure);
	TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
	TIM_Cmd(TIM3,ENABLE);
	
	
}

uint16_t Encoder_Get()
{
	return TIM_GetCounter(TIM3);
}
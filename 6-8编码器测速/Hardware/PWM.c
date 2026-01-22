#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInit_Structure;
	TIM_TimeBaseInit_Structure.TIM_ClockDivision=0;
	TIM_TimeBaseInit_Structure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit_Structure.TIM_Period=100 - 1;
	TIM_TimeBaseInit_Structure.TIM_Prescaler=720 -1 ;
	TIM_TimeBaseInit_Structure.TIM_RepetitionCounter=100;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInit_Structure);
	
	
	TIM_Cmd(TIM2,ENABLE);
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=0;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	
}
void PWM_SetCompare1(uint16_t compare)
{
	TIM_SetCompare1(TIM2,compare);
	
}
void PWM_SetPrescaler(uint16_t prescaler)
{
	TIM_PrescalerConfig(TIM2,prescaler,TIM_PSCReloadMode_Immediate);
}


***PWM 脉冲宽度调制***

![image-20260102210730910](C:\Users\Dzh19\AppData\Roaming\Typora\typora-user-images\image-20260102210730910.png)

![](../../Pictures/Screenshots/屏幕截图 2026-01-15 153841.png)

占空比 = Ton/Ts

- PWM的结构

  - 时基结构
    - PSC 预分频器
    - CNT 计数器
    - ARR 自动重装器

  - 四个输出比较单元
    - CRR 捕获/比较器

- PWM的运行模式

  - 输入捕获

    > 输入引脚→边沿检测→检测到边沿立即记录CNT的值→把CNT的值赋给CCR→读取CCR的值
    >
    > 这样相邻两侧边沿出发之间的时间就等于相邻两次记录到的CCR的值的差

  - 输出比较

    > CNT从0计数&CCR设定给定值→CNT与CCR比较
    >
    > 当CNT<CCR时 输出高电平
    >
    > 当CNT>CCR时 输出低电平
    >
    > 占空比=CCR/ARR

    输入捕获和输出比较两种模式 共用一个捕获/比较器 所以两种模式不可以同时使用
  
- PWM模块代码 初始化配置

  ```C
  //配置GPIO
  RCC_APB2PeriphClockcmd(RCC_APB2Periph_GPIOA,ENABLE);
  //时钟使能GPIO
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed=50HZ;
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
  GPIO_Init(GPIOA,&GPIO_InitStructure);
  //结构体初始化GPIO
  
  //配置timebase
  RCC_APB1PeriphClockcmd(RCC_APB1Periph_TimeBase,ENABLE);
  //时钟使能timebase
  TimeBase_InitTeypedef TimeBase_InitStructure;
  TimeBase_InitStructure.TIM_Period=1000;
  //自动重装值ARR，即周期
  TimeBase_InitStructure.TIM_prescaler=500;
  //预分频器值PSC
  TimeBase_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
  //时钟分割
  TimeBase_InitStructure.TIM_CounterMode=TIM_Counter_up;
  //计数模式
  TimeBase_Init(TIM3,&TimeBase_InitStructure);
  
  //PWM输出通道配置
  TIM_OCInitTypeDef TIM_OCInitStructure;
  TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse=500;
  TIM_OCInitStructure.TIM_OCPlority=TIM_OCPlority_High;
  TIM_OC1Init(TIM3,& TIM_OCInitStructure);
  
  TIM_OCPreloadConfig(TIM3,TIM_OCPreloadConfig_ENABLE);
  //通道使能预装载
  TIM_ARRPreloadConfig(TIM3,TIM_ARRPreloadConfig_ENABLE);
  //ARR使能预装载
  TIM_Cmd(TIM3,ENABLE);
  //定时器使能
  
  ```

  


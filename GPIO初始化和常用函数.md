***GPIO初始化和常用函数***

1. 写入函数

   ```c
   GPIO_SetBits(GPIOA,GPIO_Pin_0);
   // 单个引脚设置高电平
   GPIO_ResetBits(GPIOA,GPIO_Pin_0);
   //单个引脚设置低电平
   GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
   //单个引脚写入高电平
   GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
   //单个引脚写入低电平
   GPIO_Write(GPIOA);
   //整个端口整体写入
   ```

2. 读取函数

   ```c
   GPIO_ReadOutputData(GPIOA);
   //读取整个端口的输出数据
   GPIO_ReadInputData(GPIOA);
   //读取整个端口的输入数据
   GPIO_ReadOutputDateBit(GPIOA,GPIO_Pin_0);
   //读取单个引脚的输出数据
   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
   //读取单个引脚的输入数据
   ```

3. 其他函数

   ```c
   GPIO_PinLockConfig(GPIOA,GPIO_Pin_0);
   //锁定引脚配置，防止意外更改
   GPIO_PinAFConfig();
   //复用功能配置
   ```

4. 初始化

   ```c
   RCC_APB2PeriphClockcmd(RCC_APB2Periph_GPIOA,ENABLE);
   //时钟使能
   GPIO_InitTypeDef GPIO_InitStructure;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Speed=50HZ;
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
   GPIO_Init(GPIOA,&GPIO_InitStructure);
   //结构体初始化GPIO
   
   
   模式：
   GPIO_Mode_Out_PP 推挽输出
   GPIO_Mode_Out_OD 开漏输出
   GPIO_Mode_IN_FLOATING 浮空输入
   GPIO_Mode_IPU 上拉输入
   GPIO_Mode_IPD 下拉输入
   ```

   
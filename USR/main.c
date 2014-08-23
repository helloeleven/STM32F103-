#include "pbdata.h"
#include "led.h"
#include "key.h"
#include "misc.h"
#include "stm32f10x_exti.h"

void RCC_Configration(void)
{
	 SystemInit();
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	  //设置管脚为中断并使能(功能复用IO时钟)**************************
}

void GPIO_Configration(void)
{
	GPIO_LED_Configration();
	GPIO_KEY_Configration();
}

/*
  *中断配置*
            */
void EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
		 
    EXTI_ClearITPendingBit(EXTI_Line0);	 //清空中断线
	EXTI_ClearITPendingBit(EXTI_Line1);
	EXTI_ClearITPendingBit(EXTI_Line2);
	EXTI_ClearITPendingBit(EXTI_Line3);
	EXTI_ClearITPendingBit(EXTI_Line4);
	EXTI_ClearITPendingBit(EXTI_Line5);
	EXTI_ClearITPendingBit(EXTI_Line6);
	EXTI_ClearITPendingBit(EXTI_Line7);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource2);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource3);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource4);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource7);
		
	EXTI_InitStructure.EXTI_Line=EXTI_Line0 | EXTI_Line1 | EXTI_Line2 | EXTI_Line3 | EXTI_Line4 | EXTI_Line5 | EXTI_Line6 | EXTI_Line7;	   //选中中断线

	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;		   //设置中断模式
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;	   //下降沿触发方式
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;						//使能

	EXTI_Init(&EXTI_InitStructure);
}

void NVIC_Configuration0(void)		 //设置优先级
{
   	NVIC_InitTypeDef NVIC_InitStructure; 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 
													 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; 	  //使能指定的IRQ通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //指定成员NVIC_IRQChannel的抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //指定成员NVIC_IRQChannel的从优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //初始化外设NVIC寄存器
}

void NVIC_Configuration1(void)		 //设置优先级
{
   	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 
													 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn; 	  //使能指定的IRQ通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //指定成员NVIC_IRQChannel的抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //指定成员NVIC_IRQChannel的从优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //初始化外设NVIC寄存器
}

void NVIC_Configuration2(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn; 	  //使能指定的IRQ通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //指定成员NVIC_IRQChannel的抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //指定成员NVIC_IRQChannel的从优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //初始化外设NVIC寄存器
}

void NVIC_Configuration3(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn; 	  //使能指定的IRQ通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;  //指定成员NVIC_IRQChannel的抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //指定成员NVIC_IRQChannel的从优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //初始化外设NVIC寄存器
}

void NVIC_Configuration4(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn; 	  //使能指定的IRQ通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;  //指定成员NVIC_IRQChannel的抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //指定成员NVIC_IRQChannel的从优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //初始化外设NVIC寄存器
}

void NVIC_Configuration5(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn; 	  //使能指定的IRQ通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;  //指定成员NVIC_IRQChannel的抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //指定成员NVIC_IRQChannel的从优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //初始化外设NVIC寄存器
}
   
int main(void)
{
		RCC_Configration();
		GPIO_Configration();
		EXTI_Configuration();
		NVIC_Configuration0();
		NVIC_Configuration1();
		NVIC_Configuration2();
		NVIC_Configuration3();
		NVIC_Configuration4();
		NVIC_Configuration5();
		while(1);
}

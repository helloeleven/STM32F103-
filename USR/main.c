#include "pbdata.h"
#include "led.h"
#include "key.h"
#include "misc.h"
#include "stm32f10x_exti.h"

void RCC_Configration(void)
{
	 SystemInit();
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	  //���ùܽ�Ϊ�жϲ�ʹ��(���ܸ���IOʱ��)**************************
}

void GPIO_Configration(void)
{
	GPIO_LED_Configration();
	GPIO_KEY_Configration();
}

/*
  *�ж�����*
            */
void EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
		 
    EXTI_ClearITPendingBit(EXTI_Line0);	 //����ж���
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
		
	EXTI_InitStructure.EXTI_Line=EXTI_Line0 | EXTI_Line1 | EXTI_Line2 | EXTI_Line3 | EXTI_Line4 | EXTI_Line5 | EXTI_Line6 | EXTI_Line7;	   //ѡ���ж���

	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;		   //�����ж�ģʽ
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;	   //�½��ش�����ʽ
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;						//ʹ��

	EXTI_Init(&EXTI_InitStructure);
}

void NVIC_Configuration0(void)		 //�������ȼ�
{
   	NVIC_InitTypeDef NVIC_InitStructure; 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 
													 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; 	  //ʹ��ָ����IRQͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //ָ����ԱNVIC_IRQChannel����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //ָ����ԱNVIC_IRQChannel�Ĵ����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //��ʼ������NVIC�Ĵ���
}

void NVIC_Configuration1(void)		 //�������ȼ�
{
   	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 
													 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn; 	  //ʹ��ָ����IRQͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //ָ����ԱNVIC_IRQChannel����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //ָ����ԱNVIC_IRQChannel�Ĵ����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //��ʼ������NVIC�Ĵ���
}

void NVIC_Configuration2(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn; 	  //ʹ��ָ����IRQͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //ָ����ԱNVIC_IRQChannel����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //ָ����ԱNVIC_IRQChannel�Ĵ����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //��ʼ������NVIC�Ĵ���
}

void NVIC_Configuration3(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn; 	  //ʹ��ָ����IRQͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;  //ָ����ԱNVIC_IRQChannel����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //ָ����ԱNVIC_IRQChannel�Ĵ����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //��ʼ������NVIC�Ĵ���
}

void NVIC_Configuration4(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn; 	  //ʹ��ָ����IRQͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;  //ָ����ԱNVIC_IRQChannel����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //ָ����ԱNVIC_IRQChannel�Ĵ����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //��ʼ������NVIC�Ĵ���
}

void NVIC_Configuration5(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3); 

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn; 	  //ʹ��ָ����IRQͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;  //ָ����ԱNVIC_IRQChannel����ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 		   //ָ����ԱNVIC_IRQChannel�Ĵ����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);	   //��ʼ������NVIC�Ĵ���
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

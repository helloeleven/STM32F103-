/**
  ******************************************************************************
  * @file GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version  V3.0.0
  * @date  04/06/2009
  * @brief  Main Interrupt Service Routines.
  *         This file provides template for all exceptions handler and 
  *         peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"	 
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include "pbdata.h"

void NMI_Handler(void)
{
}

void USART1_IRQHandler(void){
   while(1);
}


/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval : None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval : None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval : None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval : None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval : None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval : None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval : None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval : None
  */
void SysTick_Handler(void)
{
}

/****************************************************************************
* 名    称：void EXTI9_5_IRQHandler(void)
* 功    能：EXTI9-5中断处理程序
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
void EXTI9_5_IRQHandler(void)
{
   if(EXTI_GetITStatus(EXTI_Line5)==SET)
  {
   	EXTI_ClearITPendingBit(EXTI_Line5);

	delay_ms(10);

	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==Bit_RESET)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_13)==Bit_RESET)
		{
			//LED 熄灭
		   GPIO_SetBits(GPIOB,GPIO_Pin_13);	
		}
		else
		{
		   //LED 发光
			GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		}
	}
  }	 
}

/****************************************************************************
* 名    称：void EXTI0_IRQHandler(void)
* 功    能：EXTI0中断处理程序
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
void EXTI0_IRQHandler(void)
{
   if(EXTI_GetITStatus(EXTI_Line0)==SET)
  {
   	EXTI_ClearITPendingBit(EXTI_Line0);

	delay_ms(10);

	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==Bit_RESET)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_8)==Bit_RESET)
		{
			//LED 熄灭
		   GPIO_SetBits(GPIOB,GPIO_Pin_8);	
		}
		else
		{
		   //LED 发光
			GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		}
	}
  }	 
}

/****************************************************************************
* 名    称：void EXTI1_IRQHandler(void)
* 功    能：EXTI2中断处理程序
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
void EXTI1_IRQHandler(void)
{
   if(EXTI_GetITStatus(EXTI_Line1)==SET)
  {
   	EXTI_ClearITPendingBit(EXTI_Line1);

	delay_ms(10);

	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==Bit_RESET)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_9)==Bit_RESET)
		{
			//LED 熄灭
		   GPIO_SetBits(GPIOB,GPIO_Pin_9);	
		}
		else
		{
		   //LED 发光
			GPIO_ResetBits(GPIOB,GPIO_Pin_9);
		}
	}
  }	  
}

/****************************************************************************
* 名    称：void EXTI2_IRQHandler(void)
* 功    能：EXTI2中断处理程序
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
void EXTI2_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line2)==SET)
  {
   	EXTI_ClearITPendingBit(EXTI_Line2);

	delay_ms(10);

	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)==Bit_RESET)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_10)==Bit_RESET)
		{
			//LED 熄灭
		   GPIO_SetBits(GPIOB,GPIO_Pin_10);	
		}
		else
		{
		   //LED 发光
			GPIO_ResetBits(GPIOB,GPIO_Pin_10);
		}
	}
  }	 
}

/****************************************************************************
* 名    称：void EXTI3_IRQHandler(void)
* 功    能：EXTI3中断处理程序
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
void EXTI3_IRQHandler(void)
{
   	if(EXTI_GetITStatus(EXTI_Line3)==SET)
  {
   	EXTI_ClearITPendingBit(EXTI_Line3);

	delay_ms(10);

	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)==Bit_RESET)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_11)==Bit_RESET)
		{
			//LED 熄灭
		   GPIO_SetBits(GPIOB,GPIO_Pin_11);	
		}
		else
		{
		   //LED 发光
			GPIO_ResetBits(GPIOB,GPIO_Pin_11);
		}
	}
  }	 
}

/****************************************************************************
* 名    称：void EXTI4_IRQHandler(void)
* 功    能：EXTI4中断处理程序
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
void EXTI4_IRQHandler(void)
{
   if(EXTI_GetITStatus(EXTI_Line4)==SET)
  {
   	EXTI_ClearITPendingBit(EXTI_Line4);

	delay_ms(10);

	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)==Bit_RESET)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==Bit_RESET)
		{
			//LED 熄灭
		   GPIO_SetBits(GPIOB,GPIO_Pin_12);	
		}
		else
		{
		   //LED 发光
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		}
	}
  }	 
}

#include "pbdata.h"

void delay(u32 nCount)
{
	for(;nCount != 0;nCount--);
}

void delay_us(u32 us)
{
	   u32 tmp;
	   SysTick->LOAD = 9 * us;	  //�Զ����ؼĴ���
	   SysTick->VAL = 0x00;		   //��ǰֵ�Ĵ���
	   SysTick->CTRL = 0X01;	   //ʱ��Դѡ��HCLK/8  0/1/2/16λ����

	   do
	   {
	   		tmp = SysTick->VAL;
	   }while(tmp&0x01 && (!tmp&(1 < 16)));
}

void delay_ms(u32 ms)
{
	   u32 tmp;
	   SysTick->LOAD = 9000 * ms;	  //�Զ����ؼĴ���
	   SysTick->VAL = 0x00;		   //��ǰֵ�Ĵ���
	   SysTick->CTRL = 0X01;	   //ʱ��Դѡ��HCLK/8  0/1/2/16λ����

	   do
	   {
	   		tmp = SysTick->VAL;
	   }while(tmp&0x01 && !(tmp&(1 < 16)));
}

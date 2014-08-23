#include "key.h"


void GPIO_KEY_Configration()
{
	GPIO_InitTypeDef GPIO_InitStructrue;
	GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_y;
	GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIO_KEY,&GPIO_InitStructrue);
}

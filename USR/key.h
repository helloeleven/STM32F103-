#ifndef _KEY_H
#define _KEY_H

#include "stm32f10x.h"

#define GPIO_Pin_y GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7
#define GPIO_KEY GPIOB

void GPIO_KEY_Configration(void);

#endif

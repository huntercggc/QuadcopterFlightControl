#include "QuadCopterConfig.h"

void LED_Config(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct = {
		/* LED_R PC13 */  /* LED_G PC14 */  /* LED_B PC15 */
		.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15,
		.GPIO_Mode = GPIO_Mode_OUT,
		.GPIO_OType = GPIO_OType_PP,
		.GPIO_Speed = GPIO_Speed_50MHz,
		.GPIO_PuPd = GPIO_PuPd_NOPULL
	};

	GPIO_Init(GPIOC, &GPIO_InitStruct);

	LED_G = 1;
	LED_R = 1;
	LED_B = 1;
}

void KEY_Config(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct = {
		/* KEY PB2 */
		.GPIO_Pin = GPIO_Pin_2,
		.GPIO_Mode = GPIO_Mode_IN,
		.GPIO_PuPd = GPIO_PuPd_NOPULL
	};

	GPIO_Init(GPIOB, &GPIO_InitStruct);
}

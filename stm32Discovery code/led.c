#include "stm32f4xx.h"                  // Device header
#include "stdbool.h"
#include "led.h"
#include "gpio.h"

#define TARRIF_1 				GPIO_PIN13
#define TARRIF_2 				GPIO_PIN14
#define TARRIF_1_ON 		true
#define TARRIF_1_OFF		false
#define TARRIF_2_ON 		true
#define TARRIF_2_OFF		false



void LED_Init(void)
{
	GPIO_Output_Init(GPIOD, GPIO_PIN13_GEN_PUR_OUTPUT | GPIO_PIN14_GEN_PUR_OUTPUT);
}

void TARRIF_1_On(void)
{
	GPIO_Output_Write(GPIOD, TARRIF_1, TARRIF_1_ON);
}

void TARRIF_1_Off(void)
{
	GPIO_Output_Write(GPIOD, TARRIF_1, TARRIF_1_OFF);
}

void TARRIF_2_On(void)
{
	GPIO_Output_Write(GPIOD, TARRIF_2, TARRIF_2_ON);
}

void TARRIF_2_Off(void)
{
	GPIO_Output_Write(GPIOD, TARRIF_2, TARRIF_2_OFF);
}

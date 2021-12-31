#include <stdbool.h>
#include <stdint.h>
#include "system.h"
#include "HC12.h"
#include "button.h"
#include "states.h"
#include "led.h"

//uint8_t bluePillData[5] = {0};
Button_t button1 = {BUTTON_PIN1, BUTTON_NOT_PRESSED, false};
Button_t button2 = {BUTTON_PIN2, BUTTON_NOT_PRESSED, false};

void handle_State_Nil(void);
void handle_Tariff_1(void);
void handle_Tariff_2(void);


void (*pStateFunction[3])(void) = {
	handle_State_Nil,
	handle_Tariff_1,
	handle_Tariff_2
};

int main(void)
{
	System_Init();
	Button_Init();
	LED_Init();
	HC12_Init();
	
	
	while(1)
	{
		uint8_t currentState = getState();
		Poll(&button1);
		Poll(&button2);
		
		pStateFunction[currentState]();
		
	}
}


void handle_State_Nil(void)
{
	TARRIF_1_Off();
	TARRIF_2_Off();
	Button_and_StateTransition(&button2, STATE_TARIFF_1);
}

void handle_Tariff_1(void)
{
	TARRIF_1_On();
	TARRIF_2_Off();
	HC12_TransmitBytes("Hello", 5);
	Button_and_StateTransition(&button1, STATE_TARIFF_2);
}

void handle_Tariff_2(void)
{
	TARRIF_1_Off();
	TARRIF_2_On();
	HC12_TransmitBytes("Mikun", 5);
	Button_and_StateTransition(&button2, STATE_TARIFF_1);
}




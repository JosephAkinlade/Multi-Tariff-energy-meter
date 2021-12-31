#include "stm32f4xx.h"                  // Device header
#include "stdbool.h"
#include "system.h"
#include "gpio.h"
#include "button.h"
#include "states.h"


void Button_Init(void)
{
	GPIO_Input_Init(GPIOA, GPIO_PIN0, false);
	GPIO_Input_Init(GPIOA, GPIO_PIN5, false);

}

static bool Debounce(Button_t* pButton)
{
	pButton->state = GPIO_Input_Read(GPIOA, pButton->pin);
	if(pButton->state == BUTTON_PRESSED)
	{
		System_Timer_DelayMs(10);
		if(pButton->state == BUTTON_PRESSED)
		{
			return true;
		}
	}
	return false;
}

void Poll(Button_t* pButton)
{
	
	pButton->isDebounced = Debounce(pButton);
	
}


void Button_and_StateTransition(Button_t* pButton, uint8_t state){
  /*
    This function allows a state transition from the appropriate
    button press. It also ensures this happens when the button
    has been de-bounced.
  */
  if (pButton->isDebounced && !pButton->prevPressed){
    setState(state);
    pButton->prevPressed = true;
  }
  else if (!pButton->isDebounced && pButton->prevPressed){
    pButton->prevPressed = false;
  }
}




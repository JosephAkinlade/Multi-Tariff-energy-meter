#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON_PIN1 		0
#define BUTTON_PIN2			5

#define BUTTON_PRESSED 				1
#define BUTTON_NOT_PRESSED 		0

typedef struct
{
	uint8_t pin;
	bool state;
	bool prevPressed;
	bool isDebounced;
}Button_t;

extern void Button_Init(void);
extern void Poll(Button_t* pButton);
void Button_and_StateTransition(Button_t* pButton, uint8_t state);

#endif /* BUTTON_H */

#ifndef STATES_H
#define STATES_H


enum STATES
{
	STATE_NIL,
	STATE_TARIFF_1,
	STATE_TARIFF_2
};

//returns the current state of the FSM (Finite State Machine)
extern uint8_t  getState(void);
//sets the current state of the FSM (FInite State Machine) to the state passed as an argument to the function
extern void setState(uint8_t STATE);

#endif /* STATES_H */

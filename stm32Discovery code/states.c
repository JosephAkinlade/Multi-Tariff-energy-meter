#include <stdint.h>
#include "states.h"

static uint8_t state = STATE_NIL;

uint8_t getState(void){
  return state;
}

void setState(uint8_t STATE){
  state = STATE;
}


/*
 * KEYPAD.h
 *  Author: afifi
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "std_macros.h"

#define INIT_KEYPAD_PIN 	                   \
							DDRB = 0b11110000; \
							PORTB = 0b1111;
#define K0 READBIT(PINB,0)
#define K1 READBIT(PINB,1)
#define K2 READBIT(PINB,2)
#define K3 READBIT(PINB,3)
#define K4(x) if(x == 1) SETBIT(PORTB,4); else CLRBIT(PORTB,4);
#define K5(x) if(x == 1) SETBIT(PORTB,5); else CLRBIT(PORTB,5);
#define K6(x) if(x == 1) SETBIT(PORTB,6); else CLRBIT(PORTB,6);
#define K7(x) if(x == 1) SETBIT(PORTB,7); else CLRBIT(PORTB,7);

void KEYPAD_init(void);
uint8_t KEYPAD_read(void);



#endif /* KEYPAD_H_ */
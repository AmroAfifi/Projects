/*
 * SEVEN_SEG.h
 *  Author: afifi
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"

#define INIT_SEVEN_SEG_PINS DDRC = 0xff; DDRD = 0xff;
#define PORT_WRITE PORTC
#define PORT_DISABLE_ALL_SS  PORTD = 0xff;

#define EN0 CLRBIT(PORTD,0);
#define EN1 CLRBIT(PORTD,1);
#define EN2 CLRBIT(PORTD,2);
#define EN3 CLRBIT(PORTD,3);
#define EN4 CLRBIT(PORTD,4);
#define EN5 CLRBIT(PORTD,5);

void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t data, uint8_t num);


#endif /* SEVEN_SEG_H_ */
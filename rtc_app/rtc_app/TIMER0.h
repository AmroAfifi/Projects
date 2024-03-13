/*
 * TIMER0.h
 *  Author: afifi
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_macros.h"
extern void (*timer0_ovf_isr)(void);
extern void (*timer0_ctc_isr)(void);

void TIMER0_normaMode_init(void);
void TIMER0_CTC_init(uint8_t);


#endif /* TIMER0_H_ */
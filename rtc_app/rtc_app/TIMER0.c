/*
 * TIMER0.c
 *  Author: afifi
 */ 
#include "TIMER0.h"

void (*timer0_ovf_isr)(void);
void (*timer0_ctc_isr)(void);

/*****************************************************************************
* Function Name: TIMER0_normaMode_init
* Purpose      : init timer in normal mode with no prescaler
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIMER0_normaMode_init(void){
	SETBIT(TCCR0,CS00); // NO PRESCALER
	SETBIT(TCCR0,FOC0);
	
	SETBIT(TIMSK,TOIE0); // enable timer ov interrupt
	SETBIT(SREG, 7); // enable global interrupt

}

/*****************************************************************************
* Function Name: TIMER0_CTC_init
* Purpose      : init timer in CTC with no prescaler
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIMER0_CTC_init(uint8_t oc){
	SETBIT(TCCR0,CS00); // PRESCALER 1024 
	SETBIT(TCCR0,CS01); // PRESCALER
	SETBIT(TCCR0,FOC0);
	SETBIT(TCCR0,WGM01); // CTC
	OCR0 = oc;
	SETBIT(TIMSK,OCIE0); // enable timer ctc interrupt
	SETBIT(SREG, 7); // enable global interrupt	
}


/*****************************************************************************
* Function Name: TIMER0_freqGen_init
* Purpose      : init timer to generate freq
* Parameters   : void
* Return value : void
*****************************************************************************/
/*
if oc = 99 ===> T= 12.5usec

*/
void TIMER0_freqGen_init(uint8_t oc){
	SETBIT(DDRB, 3); // set OC0 as output
	SETBIT(TCCR0,CS00); // no PRESCALER
	SETBIT(TCCR0,FOC0);
	SETBIT(TCCR0,WGM01); // CTC
	SETBIT(TCCR0,COM00); // tog oc0 
	OCR0 = oc;
}

ISR(TIMER0_OVF_vect){
	timer0_ovf_isr();
}

ISR(TIMER0_COMP_vect){
	timer0_ctc_isr();
}
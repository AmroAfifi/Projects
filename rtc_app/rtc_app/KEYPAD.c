/*
 * KEYPAD.c
 *  Author: afifi
 */ 
#include "KEYPAD.h"
const uint8_t keypad_matrix[] = 
{'7', '8', '9', '\\',
 '4', '5', '6', '*',
 '1', '2', '3', '-',
 'c', '0', '=', '+'
};
// PD0 to PD3 input pull up, PD4 to PD7 output
void KEYPAD_init(void){
	INIT_KEYPAD_PIN;
  
}
uint8_t KEYPAD_read(void){
	K4(0); K5(1); K6(1); K7(1);
	if(K0 == 0) return keypad_matrix[0];
	if(K1 == 0) return keypad_matrix[4];
	if(K2 == 0) return keypad_matrix[8];
	if(K3 == 0) return keypad_matrix[12];
	_delay_ms(1);
	
	K4(1); K5(0); K6(1); K7(1);
	if(K0 == 0) return keypad_matrix[1];
	if(K1 == 0) return keypad_matrix[5];
	if(K2 == 0) return keypad_matrix[9];
	if(K3 == 0) return keypad_matrix[13];
	_delay_ms(1);
	
	K4(1); K5(1); K6(0); K7(1);
	if(K0 == 0) return keypad_matrix[2];
	if(K1 == 0) return keypad_matrix[6];
	if(K2 == 0) return keypad_matrix[10];
	if(K3 == 0) return keypad_matrix[14];
	_delay_ms(1);
	
	K4(1); K5(1); K6(1); K7(0);
	if(K0 == 0) return keypad_matrix[3];
	if(K1 == 0) return keypad_matrix[7];
	if(K2 == 0) return keypad_matrix[11];
	if(K3 == 0) return keypad_matrix[15];
	_delay_ms(1);
	
	
	return 0;
}
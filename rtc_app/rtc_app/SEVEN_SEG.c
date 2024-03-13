/*
 * SEVEN_SEG.c
 *  Author: afifi
 */ 
#include "SEVEN_SEG.h"
const unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};

void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS;
}
void SEVEN_SEG_write(uint8_t data, uint8_t sg_num){ // 0 to 99
	PORT_DISABLE_ALL_SS;
	switch(sg_num){
		case 1:  EN0; break;
		case 2:  EN1; break;
		case 3:  EN2; break;
		case 4:  EN3; break;
		case 5:  EN4; break;
		case 6:  EN5; break;
	}// 0b00111111 = 0x3f
	PORT_WRITE = arr[data];
	//_delay_ms(5);
}

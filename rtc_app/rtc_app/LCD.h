/*
 * LCD.h
 *  Author: afifi
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "std_macros.h"

#define INIT_LCD_PIN  DDRA |= 0b11111100; // PA4 to PB7 & PB2,PB3 output

#define EN(x) if(x == 1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define RS(x) if(x == 1) SETBIT(PORTA,3); else CLRBIT(PORTA,3);
#define D7(x) if(x == 1) SETBIT(PORTA,7); else CLRBIT(PORTA,7);
#define D6(x) if(x == 1) SETBIT(PORTA,6); else CLRBIT(PORTA,6);
#define D5(x) if(x == 1) SETBIT(PORTA,5); else CLRBIT(PORTA,5);
#define D4(x) if(x == 1) SETBIT(PORTA,4); else CLRBIT(PORTA,4);

void LCD_init(void);
void LCD_write_command(uint8_t data);
void LCD_write_data(uint8_t data);
void LCD_write_string(uint8_t *data);
void LCD_write_num(uint32_t data);


#endif /* LCD_H_ */
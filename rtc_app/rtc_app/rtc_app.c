/*
 * rtc_app.c
 *  Author: afifi
 */ 


#include "SEVEN_SEG.h"
#include "TIMER0.h"
#include "LCD.h"

void timer0_ctc();
volatile uint8_t flag = 0; seconds = 0, minutes = 0, hours = 0;
void lcd_update();
void check_keypad_for_new_settings();
int main(void)
{
	uint8_t old_seconds;
	timer0_ctc_isr = timer0_ctc;
	SEVEN_SEG_init();
	LCD_init();
	KEYPAD_init();
	TIMER0_CTC_init(249);// overflow = 250/16 * 64 = 1msec * 1000 = 1sec
	old_seconds = seconds;
    while(1)
    {	
		check_keypad_for_new_settings();
		if(old_seconds != seconds){// To print on lcd just in case a new value of seconds detected
			lcd_update();
			old_seconds = seconds;
		}		

		if(seconds == 60){
			minutes++;
			seconds = 0;
		}
		if (minutes == 60)
		{
			hours++;
			minutes = 0;
		}
    }
}
void lcd_update(){
	LCD_write_command(0x1);
	LCD_write_num(hours);
	LCD_write_data(':');
	LCD_write_num(minutes);
	LCD_write_data(':');
	LCD_write_num(seconds);
}

void timer0_ctc(){ // generated every 1ms
	static uint16_t count0 = 0;
	static uint8_t count1 = 0;
	if(flag == 0){
		count0++;
		if(count0 == 1000){
			seconds++;
			count0 = 0;
		}
	}	
	switch (count1){
		case 0: SEVEN_SEG_write(seconds / 10,1); count1++;   break;
		case 1:	SEVEN_SEG_write(seconds % 10,2); count1++;   break;
		case 2:	SEVEN_SEG_write(minutes / 10,3); count1++;   break;
    	case 3:	SEVEN_SEG_write(minutes % 10,4); count1++;   break;
		case 4:	SEVEN_SEG_write(hours / 10,5);	 count1++;   break;
		case 5:	SEVEN_SEG_write(hours % 10,6);   count1 = 0; break;
	}
}		
void check_keypad_for_new_settings(){
	uint8_t key = KEYPAD_read();
	if(key == 'c'){
		flag = 1;
		while(KEYPAD_read() == 'c');
		while(KEYPAD_read() == 0);
		key = KEYPAD_read();
		while(key != 'c'){
			if(key == '8'){
				if(minutes == 59) minutes = 0;
				else minutes++;
					
				lcd_update();
				while(KEYPAD_read() == '8');
			}
			else if(key == '5'){
				if(minutes == 0) minutes = 59;
				else minutes--;
					
				lcd_update();
				while(KEYPAD_read() == '5');
			}
			key = KEYPAD_read();
		}
		while(KEYPAD_read() == 'c');
		while(KEYPAD_read() == 0);
		key = KEYPAD_read();
		while(key != 'c'){
			if(key == '8'){
				if(hours == 23) hours = 0;
				else hours++;
				lcd_update();
				while(KEYPAD_read() == '8');
			}
			else if(key == '5'){
				if(hours == 0) hours = 23;
				else hours--;
				lcd_update();
				while(KEYPAD_read() == '5');
			}
			key = KEYPAD_read();
		}
		flag = 0;
		while(KEYPAD_read() == 'c');
	}	
}
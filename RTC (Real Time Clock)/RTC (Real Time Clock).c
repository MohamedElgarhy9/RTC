/*
 * RTC__Real_Time_Clock_.c
 *
 * Created: 4/15/2022 2:18:16 PM
 *  Author: Mohamed Maged 
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include <avr/io.h>
#include "std_macros.h"
#include "LCD.h"
#include "7_SEG.h"
#include "Timer.h"
#include "Keypad.h"

volatile unsigned char secounds_counter = 0;
unsigned char minutes_counter = 0;
unsigned char hours_counter = 0;
unsigned char pressed_value, first_digit, second_digit; 

int main(void)
{
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	LCD_vInit();
	SEVEN_SEG_vInit('A');
	Keypad_vInit();
	timer2_overflow_init_interrupt();
	LCD_vSend_String("Press 1 to:");
	LCD_vMoveCursor(2,1);
	LCD_vSend_String("Setup the clock");
	
    while(1)
    {
		pressed_value = keypad_u8CheckPress();
		if(pressed_value != NOTPRESSED)
		{
			if(pressed_value == '1')
			{
				LCD_vClearScreen();
				LCD_vSend_String("hours=--");
				LCD_vMoveCursor(1,7);
				_delay_ms(500);
				do 
				{
					first_digit = keypad_u8CheckPress();
				} while (first_digit == NOTPRESSED);
				LCD_vSend_Char(first_digit);
				_delay_ms(300);
				do 
				{
					second_digit = keypad_u8CheckPress();
				} while (second_digit == NOTPRESSED);
				LCD_vSend_Char(second_digit);
				_delay_ms(300);
				hours_counter = (first_digit-48)*10 + (second_digit-48);
				LCD_vClearScreen();
				LCD_vSend_String("Minutes=--");
				LCD_vMoveCursor(1,9);
				_delay_ms(500);
				do 
				{
					first_digit = keypad_u8CheckPress();
				} while (first_digit == NOTPRESSED);
				LCD_vSend_Char(first_digit);
				_delay_ms(300);
				do 
				{
					second_digit = keypad_u8CheckPress();
				} while (second_digit == NOTPRESSED);
				LCD_vSend_Char(second_digit);
				_delay_ms(300);
				minutes_counter = (first_digit-48)*10 + (second_digit-48);
				LCD_vClearScreen();
				LCD_vSend_String("Seconds=--");
				LCD_vMoveCursor(1,9);
				_delay_ms(500);
				do 
				{
					first_digit = keypad_u8CheckPress();
				} while (first_digit == NOTPRESSED);
				LCD_vSend_Char(first_digit);
				_delay_ms(300);
				do 
				{
					second_digit = keypad_u8CheckPress();
				} while (second_digit == NOTPRESSED);
				LCD_vSend_Char(second_digit);
				_delay_ms(300);
				secounds_counter = (first_digit-48)*10 + (second_digit-48);
				LCD_vClearScreen();
				LCD_vSend_String("Press 1 to:");
				LCD_vMoveCursor(2,1);
				LCD_vSend_String("Setup the clock");
			}
			else
			{
				LCD_vClearScreen();
				LCD_vSend_String("Yaa 3aam doos 1");
				_delay_ms(1000);
				LCD_vClearScreen();
				LCD_vSend_String("Press 1 to:");
				LCD_vMoveCursor(2,1);
				LCD_vSend_String("Setup the clock");
			}
		}
		CLR_BIT(PORTC,0);
		SEVEN_SEG_vWrite('A',secounds_counter%10);
		_delay_ms(3);
		SET_BIT(PORTC,0);
		CLR_BIT(PORTC,1);
		SEVEN_SEG_vWrite('A',secounds_counter/10);
		_delay_ms(3);
		SET_BIT(PORTC,1);
		CLR_BIT(PORTC,2);
		SEVEN_SEG_vWrite('A',minutes_counter%10);
		_delay_ms(3);
		SET_BIT(PORTC,2);
		CLR_BIT(PORTC,3);
		SEVEN_SEG_vWrite('A',minutes_counter/10);
		_delay_ms(3);
		SET_BIT(PORTC,3);
		CLR_BIT(PORTC,4);
		SEVEN_SEG_vWrite('A',hours_counter%10);
		_delay_ms(3);
		SET_BIT(PORTC,4);
		CLR_BIT(PORTC,5);
		SEVEN_SEG_vWrite('A',hours_counter/10);
		_delay_ms(3);
		SET_BIT(PORTC,5);
		if(secounds_counter == 60)
		{
			secounds_counter = 0;
			minutes_counter++;
		}			
		if(minutes_counter == 60)
		{
			minutes_counter = 0;
			hours_counter++;
		}
		if(hours_counter == 24)
		{
			hours_counter = 0; 
		}			
        			 
    }
}

ISR(TIMER2_OVF_vect)
{
	secounds_counter++;
}
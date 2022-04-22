/*
 * Timer.c
 *
 * Created: 4/15/2022 2:23:13 PM
 *  Author: Mohamed Maged
 */ 

#include "Timer.h"
#include <avr/interrupt.h>

void timer2_overflow_init_interrupt(void)
{
	/*** As overflow mode is the default one, we don't have to configure WGM bits ***/
	// select timer clock 
	SET_BIT(ASSR,AS2);
	// select timer pre scalar --> 128
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	// Enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE2);
}

/*
 * Timer.h
 *
 * Created: 4/15/2022 2:41:21 PM
 *  Author: Mohamed Maged
 */ 

#include "std_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef TIMER_H_
#define TIMER_H_

void timer2_overflow_init_interrupt(void);

#endif /* TIMER_H_ */
/*
 * _7_SEG.h
 *
 * Created: 10/20/2021 2:27:49 AM
 *  Author: 20155
 */ 


#ifndef _7_SEG_H_
#define _7_SEG_H_


void SEVEN_SEG_vInit(unsigned char portname);// Initialize all bins of a port connected to the 7 Segment as output
void SEVEN_SEG_vWrite(unsigned char portname, unsigned char number);//Writing a number on 7 Segment connected to a given port
void SEVEN_SEG_vBCDInit(unsigned char portname);// Initialize the first four bins of a given port which connected to BCD as output
void SEVEN_SEG_vWriteLowNibbleBCD(unsigned char portname, unsigned char number);//Write first four bits of a given number on the least four bins of a given port which connected to BCD 

#endif /* _7_SEG_H_ */
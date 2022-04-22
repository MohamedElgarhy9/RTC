/*
 * _7_SEG.c
 *
 * Created: 10/20/2021 2:27:13 AM
 *  Author: 20155
 */ 


#define cc
#include "DIO.h"

void SEVEN_SEG_vInit(unsigned char portname)// Initialize all bins of a port connected to the 7 Segment as output
{
	DIO_vsetPORTDIR(portname,0xff);
}
void SEVEN_SEG_vWrite(unsigned char portname, unsigned char number)//Writing a number on 7 Segment connected to a given port
{
	unsigned char arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	#if defined cc //If the 7 Segment is common cathode
	DIO_vwritePORT(portname,arr[number]);
	#elif defined ca // If the 7 Segment is common anode
	DIO_vwritePORT(portname,~arr[number]);
	#endif
}
void SEVEN_SEG_vBCDInit(unsigned char portname)// Initialize the first four bins of a given port which connected to BCD as output
{
	DIO_vsetPINDIR(portname,0,1);
	DIO_vsetPINDIR(portname,1,1);
	DIO_vsetPINDIR(portname,2,1);
	DIO_vsetPINDIR(portname,3,1);
}
void SEVEN_SEG_vWriteLowNibbleBCD(unsigned char portname, unsigned char number)//Write first four bits of a given number on the least four bins of a given port which connected to BCD 
{
	DIO_vWriteLowNibble(portname,number);
}

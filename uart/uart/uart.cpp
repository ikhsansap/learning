#include "uart.h"

void UART::init(unsigned int baud, Parity p){
	// set baud rate in UBRR
	ubrr = F_CPU/16/baud-1;
	UBRR0L = (uint8_t)(ubrr & 0xFF);
	UBRR0H = (uint8_t)(ubrr >> 8);
	
	// enable the transmitter and receiver
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	
	// set frame format
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
	switch(p){
		case odd:
			UCSR0C |= (1 << UPM01) | (1 << UPM00);
		break;
		case even:
			UCSR0C |= (1 << UPM01);
		break;
		case none:
		break;
	}
	
}

void UART::sendChar(char c){
	while (!(UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer */
	UDR0 = c; /* Put data into buffer, sends the data */
}

void UART::sendText(const char* s){
	while(*s!=0){
		UART::sendChar(*s++);
	}
}
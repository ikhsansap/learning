#ifndef uart_h
#define uart_h
#include <avr/io.h>

#ifndef F_CPU
/* prevent compiler error by supplying a default */
#warning "F_CPU not defined for uart.h"
#define F_CPU 16000000UL
#endif

enum Parity{even,odd,none};

class UART{
	private:
	uint16_t ubrr;

	public:
	void init(unsigned int baud=9600, Parity p=none);
	void sendChar(char c);
	void sendText(const char* c);
};

#endif
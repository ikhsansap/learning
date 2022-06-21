#define F_CPU 16000000

#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>


int main() {
	UART uart;
	
	uart.init(38400);
	while (1){
		uart.sendText("HAHAHAHA ");
		uart.sendText("\n");
		_delay_ms(300);
	}
}
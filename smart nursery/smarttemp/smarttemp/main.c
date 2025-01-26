#include <avr/io.h>
#include "adc.h"
int main(void){
	DDRC=0xff;
	DDRA=0;
	PORTC=0;
	adc_init();
    while (1) {
		int tempread = adc_read(0);
		if (tempread>30){
			PORTC=0b00000001;
		}else if (tempread<10){
			PORTC=0b00000010;
		}else{
			PORTC=0;
		}
    }
}


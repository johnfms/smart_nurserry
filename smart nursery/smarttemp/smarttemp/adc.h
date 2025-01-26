#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>        // Include AVR input/output library for I/O operations
#include <util/delay.h>    // Include delay utility for timing functions
void adc_init(){
	ADMUX&=~(1<<REFS1);//---AVCC with external
	ADMUX|=(1<<REFS0);// ---capacitor at AREF pin
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);//div factor =128 law the freq  of conversation
	ADCSRA|=(1<<ADEN);//Enable
}
int adc_read(char ch){
	ch&=0b00000111; //check channel 0->7
	ADMUX&=0b11111000;//clear old channel
	ADMUX|=ch;//set new channel
	ADCSRA|=1<<ADSC;//start new conversation
	while(ADCSRA&(1<<ADSC));//wait till the reading is finish
	return (ADCL|(ADCH<<8));//return 10 bit in int max= 1023
}
#endif /* ADC_H_ */
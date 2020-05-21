#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#define LED_PIN 1

void blink(void){
  PORTD ^= (1 << LED_PIN); // Toggle LED
  _delay_ms(500);         // Hold for 500 ms
}

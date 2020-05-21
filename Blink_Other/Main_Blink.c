#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "Blink.h"

#define LED_PIN 1

int main(void){
  DDRB |= (1 << LED_PIN); // Set pin as output

  while(1){
    blink();
  }

  return 0;
}

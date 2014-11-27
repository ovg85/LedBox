#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


//время задержки старта
#define START_DELAY 500

//время задержки иницилизации
#define INIT_DELAY 10

  void main(void)
  {
    DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
 
	_delay_ms(START_DELAY);
	 
	while (1) {
		ledOn(0);
		_delay_ms(INIT_DELAY);
		ledOn(1);
		_delay_ms(INIT_DELAY);
		ledOn(2);
		_delay_ms(INIT_DELAY);
		ledOn(3);
		_delay_ms(INIT_DELAY);
		ledOn(4);
		_delay_ms(INIT_DELAY);
		ledOn(5);
		_delay_ms(INIT_DELAY);
		ledOn(6);
		_delay_ms(INIT_DELAY);
		ledOn(7);
		_delay_ms(INIT_DELAY);
		ledOn(8);
		_delay_ms(INIT_DELAY);
		ledOn(9);
		_delay_ms(INIT_DELAY);
		ledOn(10);
		_delay_ms(INIT_DELAY);
		
		ledOff(0);
		_delay_ms(INIT_DELAY);
		ledOff(1);
		_delay_ms(INIT_DELAY);
		ledOff(2);
		_delay_ms(INIT_DELAY);
		ledOff(3);
		_delay_ms(INIT_DELAY);
		ledOff(4);
		_delay_ms(INIT_DELAY);
		ledOff(5);
		_delay_ms(INIT_DELAY);
		ledOff(6);
		_delay_ms(INIT_DELAY);
		ledOff(7);
		_delay_ms(INIT_DELAY);
		ledOff(8);
		_delay_ms(INIT_DELAY);
		ledOff(9);
		_delay_ms(INIT_DELAY);
		ledOff(10);
		_delay_ms(INIT_DELAY);
	}
	
  }
  
  void ledOn(int led)
  {
	switch (led)
	{
		case 0:
			PORTB |= _BV(5);
		break;
		case 1:
			PORTB |= _BV(4);
		break;
		case 2:
			PORTB |= _BV(3);
		break;
		case 3:
			PORTB |= _BV(2);
		break;
		case 4:
			PORTB |= _BV(1);
		break;
		case 5:
			PORTB |= _BV(0);
		break;
		case 6:
			PORTD |= _BV(7);
		break;
		case 7:
			PORTD |= _BV(6);
		break;
		case 8:
			PORTD |= _BV(5);
		break;
		case 9:
			PORTB |= _BV(7);
		break;
		case 10:
			PORTB |= _BV(6);
		break;
		
	}
  }

  void ledOff(int led)
  {
	switch (led)
	{
		case 0:
			PORTB &= ~(_BV(5));
		break;
		case 1:
			PORTB &= ~(_BV(4));
		break;
		case 2:
			PORTB &= ~(_BV(3));
		break;
		case 3:
			PORTB &= ~(_BV(2));
		break;
		case 4:
			PORTB &= ~(_BV(1));
		break;
		case 5:
			PORTB &= ~(_BV(0));
		break;
		case 6:
			PORTD &= ~(_BV(7));
		break;
		case 7:
			PORTD &= ~(_BV(6));
		break;
		case 8:
			PORTD &= ~(_BV(5));
		break;
		case 9:
			PORTB &= ~(_BV(7));
		break;
		case 10:
			PORTB &= ~(_BV(6));
		break;
	}
  }
  
  void ledPairOn(int index)
  {
	switch (index)
	{
		case 0:
			ledOn(21);
		break;
		case 12:
			ledOn(10);
		break;
		default:
			ledOn(index);
			ledOn(index + 10);
		break;
	}
  }
  
  void ledPairOff(int index)
  {
	switch (index)
	{
		case 0:
			ledOff(21);
		break;
		case 12:
			ledOff(10);
		break;
		default:
			ledOff(index);
			ledOff(index + 10);
		break;
		
	}
  }
  

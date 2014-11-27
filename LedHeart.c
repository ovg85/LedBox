#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


//время задержки старта
#define START_DELAY 500

//время задержки иницилизации
#define INIT_DELAY 10

//время задержки между эффектами
#define EFFECT_DELAY 30

  void main(void)
  {
    DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
 
	_delay_ms(START_DELAY);
	 
	SequencePairOn(INIT_DELAY);
	 
	_delay_ms(EFFECT_DELAY);
	 
	while (1) {
		
		SequencePairOff(INIT_DELAY);
		_delay_ms(EFFECT_DELAY);
		SequencePairOn(INIT_DELAY);
		_delay_ms(EFFECT_DELAY);
		for(int i=0; i<5; i++)
		{
			ledAllOff();
			_delay_ms(EFFECT_DELAY);
			ledAllOn();
			_delay_ms(EFFECT_DELAY);
		}
	}
	
  }
  
  //Switch on led
  void ledOn(int led)
  {
	switch (led)
	{
		//left side
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
		
		//Right side
		case 11:
			PORTD |= _BV(4);
		break;
		case 12:
			PORTD |= _BV(3);
		break;
		case 13:
			PORTD |= _BV(2);
		break;
		case 14:
			PORTD |= _BV(1);
		break;
		case 15:
			PORTD |= _BV(0);
		break;
		case 16:
			PORTC |= _BV(5);
		break;
		case 17:
			PORTC |= _BV(4);
		break;
		case 18:
			PORTC |= _BV(3);
		break;
		case 19:
			PORTC |= _BV(2);
		break;
		case 20:
			PORTC |= _BV(1);
		break;
		case 21:
			PORTC |= _BV(0);
		break;
	}
  }

  //Switch off led
  void ledOff(int led)
  {
	switch (led)
	{
		//left side
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
		
		
		//Right side
		case 11:
			PORTD &= ~(_BV(4));
		break;
		case 12:
			PORTD &= ~(_BV(3));
		break;
		case 13:
			PORTD &= ~(_BV(2));
		break;
		case 14:
			PORTD &= ~(_BV(1));
		break;
		case 15:
			PORTD &= ~(_BV(0));
		break;
		case 16:
			PORTC &= ~(_BV(5));
		break;
		case 17:
			PORTC &= ~(_BV(4));
		break;
		case 18:
			PORTC &= ~(_BV(3));
		break;
		case 19:
			PORTC &= ~(_BV(2));
		break;
		case 20:
			PORTC &= ~(_BV(1));
		break;
		case 21:
			PORTC &= ~(_BV(0));
		break;
		
	}
  }
  
  //Switch on a pair of leds
  //index: from 0 (bottom) to 11 (top)
  void ledPairOn(int index)
  {
	switch (index)
	{
		case 0:
			ledOn(21);
		break;
		case 11:
			ledOn(10);
		break;
		default:
			ledOn(index - 1);
			ledOn(21- index);
		break;
	}
  }
  
  //Switch off a pair of leds
  //index: from 0 (bottom) to 11 (top)
  void ledPairOff(int index)
  {
	switch (index)
	{
		case 0:
			ledOff(21);
		break;
		case 11:
			ledOff(10);
		break;
		default:
			ledOff(index - 1);
			ledOff(21 - index);
		break;
		
	}
  }
  
	//Switch on all leds pair by pair from bottom to top
	//delay: delay between pairs
	void SequencePairOn(int delay)
	{
		ledPairOn(0);
		_delay_ms(delay);
		ledPairOn(1);
		_delay_ms(delay);
		ledPairOn(2);
		_delay_ms(delay);
		ledPairOn(3);
		_delay_ms(delay);
		ledPairOn(4);
		_delay_ms(delay);
		ledPairOn(5);
		_delay_ms(delay);
		ledPairOn(6);
		_delay_ms(delay);
		ledPairOn(7);
		_delay_ms(delay);
		ledPairOn(8);
		_delay_ms(delay);
		ledPairOn(9);
		_delay_ms(delay);
		ledPairOn(10);
		_delay_ms(delay);
		ledPairOn(11);
	}
	
	//Switch off all leds pair by pair from bottom to top
	//delay: delay between pairs
	void SequencePairOff(int delay)
	{
		ledPairOff(0);
		_delay_ms(delay);
		ledPairOff(1);
		_delay_ms(delay);
		ledPairOff(2);
		_delay_ms(delay);
		ledPairOff(3);
		_delay_ms(delay);
		ledPairOff(4);
		_delay_ms(delay);
		ledPairOff(5);
		_delay_ms(delay);
		ledPairOff(6);
		_delay_ms(delay);
		ledPairOff(7);
		_delay_ms(delay);
		ledPairOff(8);
		_delay_ms(delay);
		ledPairOff(9);
		_delay_ms(delay);
		ledPairOff(10);
		_delay_ms(delay);
		ledPairOff(11);
		_delay_ms(delay);
	}
	
	//Switch on all leds
	void ledAllOn()
	{
		for(int i=0;i<22;i++)
		{
			ledOn(i);
		}
	}
	
	//Switch off all leds
	void ledAllOff()
	{
	
		for(int i=0;i<22;i++)
		{
			ledOff(i);
		}
	}
	
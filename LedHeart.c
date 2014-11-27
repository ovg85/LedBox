#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


//Delay at start
#define START_DELAY 250

//Delay at initial switching leds on 
#define INIT_DELAY 10

//Delay between effects
#define EFFECT_DELAY 30

//Delay for falling leds
#define FALL_DALAY 5

//Total diodes count
#define DIODES_COUNT 22

//Diodes count at one sile (left or right)
#define DIODES_SIDE_COUNT 11

//Count of diodes pair
#define DIODES_PAIR_COUNT 12


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
	 
	ledAllOff();
	 
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
		
		for(int i=0;i<10;i++)
		{
			oddAllOn();
			_delay_ms(EFFECT_DELAY);
			oddAllOff();
			evenAllOn();
			_delay_ms(EFFECT_DELAY);
			evenAllOff();			
		}
		
		_delay_ms(EFFECT_DELAY);
		
		for(int i=0;i<5;i++)
		{
			makeHeartByPairFall(FALL_DALAY);
			_delay_ms(FALL_DALAY);
			breakHeartByPairFall(FALL_DALAY);
		}
		_delay_ms(EFFECT_DELAY);
		
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
			ledOn(DIODES_COUNT - 1);
		break;
		case 11:
			ledOn(DIODES_SIDE_COUNT - 1);
		break;
		default:
			ledOn(index - 1);
			ledOn(DIODES_COUNT - 1 - index);
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
			ledOff(DIODES_COUNT - 1);
		break;
		case 11:
			ledOff(DIODES_SIDE_COUNT - 1);
		break;
		default:
			ledOff(index - 1);
			ledOff(DIODES_COUNT - 1 - index);
		break;
		
	}
  }
  
	//Switch on all leds pair by pair from bottom to top
	//delay: delay between pairs
	void SequencePairOn(int delay)
	{
		for(int i=0;i<DIODES_PAIR_COUNT;i++)
		{
			ledPairOn(i);
			_delay_ms(delay);
		}
	}
	
	//Switch off all leds pair by pair from bottom to top
	//delay: delay between pairs
	void SequencePairOff(int delay)
	{
		for(int i=0;i<DIODES_PAIR_COUNT;i++)
		{
			ledPairOff(i);
			_delay_ms(delay);
		}
	}
	
	//Switch on all leds
	void ledAllOn()
	{
		for(int i=0;i<DIODES_COUNT;i++)
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
	
	//Switch on all odd leds
	void oddAllOn()
	{
		for(int i = 1; i < DIODES_COUNT; i = i + 2)
		{
			ledOn(i);
		}
	}
	
	//Switch off all odd leds
	void oddAllOff()
	{
		for(int i = 1; i < DIODES_COUNT; i = i + 2)
		{
			ledOff(i);
		}
	}
	
	//Switch on all even leds
	void evenAllOn()
	{
		for(int i = 0; i < DIODES_COUNT; i = i + 2)
		{
			ledOn(i);
		}
	}
	
	//Switch off all even leds
	void evenAllOff()
	{
		for(int i = 0; i < DIODES_COUNT; i = i + 2)
		{
			ledOff(i);
		}
	}
	
	//Creating heart by falling leds from top to bottom, like stack.
	//delay: delay between leg switching.
	void makeHeartByPairFall(int delay)
	{
		for(int i = 1; i <= DIODES_PAIR_COUNT; i++)
		{
			for(int j=DIODES_PAIR_COUNT; j >= i; j--)
			{
				if(j < DIODES_PAIR_COUNT)
				{
					ledPairOff(j);
				}
				ledPairOn(j - 1);
				_delay_ms(delay);
			}
		}
	}
	
	//Breaking heart by falling leds from top to bottom.
	//delay: delay between leg switching.
	void breakHeartByPairFall(int delay)
	{
		for(int i = 0; i < DIODES_PAIR_COUNT; i++)
		{
			for(int j=i; j >= 0; j--)
			{
				ledPairOff(j);
				if(j > 0)
				{				
					ledPairOn(j - 1);
				}
				_delay_ms(delay);
			}
		}
	}
	
	
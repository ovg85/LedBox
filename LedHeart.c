#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/stdlib.h>

#define SetPortBit(port, bit) port |= (1<<bit)
//PORTB |= _BV(5);
#define ClearPortBit(port, bit) port &= ~(1<<bit)
//PORTB &= ~(_BV(5));

//Delay at start
#define START_DELAY 250

//Delay at initial switching leds on 
#define INIT_DELAY 10

//Delay between effects
#define EFFECT_DELAY 30

//Delay for falling leds
#define FALL_DELAY 15

#define EVEN_ODD_DELAY 30

//Total diodes count
#define DIODES_COUNT 22

//Diodes count at one sile (left or right)
#define DIODES_SIDE_COUNT 11

//Count of diodes pair
#define DIODES_PAIR_COUNT 12

#define SNAKE_DELAY 10

  int main(void)
  {
    DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
 
	/*int ledRandNum[DIODES_COUNT]=
	{16,1,13,8,4,5,18,7,3,14,10,17,
	21,2,9,15,0,19,6,11,20,12};*/
	
	int ledRandNum[DIODES_COUNT]=
	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
	
	_delay_ms(START_DELAY);
	 
	SequencePairOn(INIT_DELAY);
	
	_delay_ms(EFFECT_DELAY);
	 
	while (1) {
	
		randomLedOn(EFFECT_DELAY, ledRandNum, DIODES_COUNT);
	
		ledBlinking(EFFECT_DELAY, 5);
		_delay_ms(EFFECT_DELAY);
		
		evenOddOnOff(EVEN_ODD_DELAY, 10);
		_delay_ms(EFFECT_DELAY);
		
		for(int i=0;i<3;i++)
		{
			makeHeartByPairFall(FALL_DELAY);
			_delay_ms(FALL_DELAY);
			breakHeartByPairFall(FALL_DELAY);
		}
		_delay_ms(EFFECT_DELAY);
		
		SequencePairOn(INIT_DELAY);
		_delay_ms(EFFECT_DELAY);
		
		SequencePairOff(INIT_DELAY);
		_delay_ms(EFFECT_DELAY);
		
		for(int i=0;i<3;i++)
		{
			snakeLedClockWise(SNAKE_DELAY, 3, 1);
			snakeLedAnticlockWise(SNAKE_DELAY, 3, 1);
		}
		_delay_ms(EFFECT_DELAY);
		
		for(int i=0;i<3;i++)
		{
			snakeTwoUp(SNAKE_DELAY, 3, 1);
			snakeTwoDown(SNAKE_DELAY, 3, 1);
		}
		_delay_ms(EFFECT_DELAY);
	}
	return 0;
  }
  
  //Switch on led
  void ledOn(int led)
  {
	switch (led)
	{
		//left side
		case 0:
			SetPortBit(PORTB, 5);
			//PORTB |= _BV(5);
		break;
		case 1:
			SetPortBit(PORTB, 4);
		break;
		case 2:
			SetPortBit(PORTB, 3);
		break;
		case 3:
			SetPortBit(PORTB, 2);
		break;
		case 4:
			SetPortBit(PORTB, 1);
		break;
		case 5:
			SetPortBit(PORTB, 0);
		break;
		case 6:
			SetPortBit(PORTD, 7);
		break;
		case 7:
			SetPortBit(PORTD, 6);
		break;
		case 8:
			SetPortBit(PORTD, 5);
		break;
		case 9:
			SetPortBit(PORTB, 7);
		break;
		case 10:
			SetPortBit(PORTB, 6);
		break;
		
		//Right side
		case 11:
			SetPortBit(PORTD, 4);
		break;
		case 12:
			SetPortBit(PORTD, 3);
		break;
		case 13:
			SetPortBit(PORTD, 2);
		break;
		case 14:
			SetPortBit(PORTD, 1);
		break;
		case 15:
			SetPortBit(PORTD, 0);
		break;
		case 16:
			SetPortBit(PORTC, 5);
		break;
		case 17:
			SetPortBit(PORTC, 4);
		break;
		case 18:
			SetPortBit(PORTC, 3);
		break;
		case 19:
			SetPortBit(PORTC, 2);
		break;
		case 20:
			SetPortBit(PORTC, 1);
		break;
		case 21:
			SetPortBit(PORTC, 0);
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
			ClearPortBit(PORTB, 5);
			//PORTB &= ~(_BV(5));
		break;
		case 1:
			ClearPortBit(PORTB, 4);
		break;
		case 2:
			ClearPortBit(PORTB, 3);
		break;
		case 3:
			ClearPortBit(PORTB, 2);
		break;
		case 4:
			ClearPortBit(PORTB, 1);
		break;
		case 5:
			ClearPortBit(PORTB, 0);
		break;
		case 6:
			ClearPortBit(PORTD, 7);
		break;
		case 7:
			ClearPortBit(PORTD, 6);
		break;
		case 8:
			ClearPortBit(PORTD, 5);
		break;
		case 9:
			ClearPortBit(PORTB, 7);
		break;
		case 10:
			ClearPortBit(PORTB, 6);
		break;
		
		
		//Right side
		case 11:
			ClearPortBit(PORTD, 4);
		break;
		case 12:
			ClearPortBit(PORTD, 3);
		break;
		case 13:
			ClearPortBit(PORTD, 2);
		break;
		case 14:
			ClearPortBit(PORTD, 1);
		break;
		case 15:
			ClearPortBit(PORTD, 0);
		break;
		case 16:
			ClearPortBit(PORTC, 5);
		break;
		case 17:
			ClearPortBit(PORTC, 4);
		break;
		case 18:
			ClearPortBit(PORTC, 3);
		break;
		case 19:
			ClearPortBit(PORTC, 2);
		break;
		case 20:
			ClearPortBit(PORTC, 1);
		break;
		case 21:
			ClearPortBit(PORTC, 0);
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
		PORTB = 0xFF;
		PORTC = 0xFF;
		PORTD = 0xFF;
	}
	
	//Switch off all leds
	void ledAllOff()
	{
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
	}
	
	//Switch on all odd leds
	void oddAllOn()
	{
		PORTB |= 0b10010101;
		PORTC |= 0b00010101;
		PORTD |= 0b01010101;
	}
	
	//Switch off all odd leds
	void oddAllOff()
	{
		PORTB &= 0b01101010;
		PORTC &= 0b00101010;
		PORTD &= 0b10101010;
	}
	
	//Switch on all even leds
	void evenAllOn()
	{
		PORTB |= 0b01101010;
		PORTC |= 0b00101010;
		PORTD |= 0b10101010;
	}
	
	//Switch off all even leds
	void evenAllOff()
	{
		PORTB &= 0b10010101;
		PORTC &= 0b00010101;
		PORTD &= 0b01010101;
	}
	
	
	
	//leds Blinking 
	//delay: delay between led switching.
	//rotationCount: Count of switching 
	void ledBlinking(int delay, int rotationCount)
	{
		ledAllOn();
		_delay_ms(delay);
		for(int i=0;i<rotationCount - 1;i++)
		{
			ledAllOff();
			_delay_ms(delay);
			ledAllOn();
			_delay_ms(delay);
		}
		ledAllOff();
	}
	
	//sequential switching odd and even leds
	//delay: delay between led switching.
	//rotationCount: Count of switching 
	void evenOddOnOff(int delay, int rotationCount)
	{
		ledAllOff();
		for(int i=0;i<rotationCount;i++)
		{	
			oddAllOn();
			_delay_ms(delay);
			ledAllOff();
			evenAllOn();
			_delay_ms(delay);
			ledAllOff();
		}
	}
	
	//Creating heart by falling leds from top to bottom, like stack.
	//delay: delay between led switching.
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
	//delay: delay between led switching.
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
	
	//ClockWise snake
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeLedClockWise(int delay, int length, int rotationCount)
	{
		for(int i=0;i<rotationCount;i++)
		{
			for(int j=0;j<DIODES_COUNT;j++)
			{
				ledOn(j);
				if(j >= length)
				{
					ledOff(j - length);
				}
				else
				{
					ledOff(DIODES_COUNT - length + j);
				}	
			_delay_ms(delay);			
			}
		}
		for(int i=DIODES_COUNT - length - 1;i<DIODES_COUNT;i++)
		{
			ledOff(i);
			_delay_ms(delay);	
		}
	}
	
	//AnticlockWise snake
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeLedAnticlockWise(int delay, int length, int rotationCount)
	{
		for(int i=0;i<rotationCount;i++)
		{
			for(int j=0;j<DIODES_COUNT;j++)
			{
				ledOn(DIODES_COUNT - 1 - j);
				if(j > length - 1)
				{
					ledOff(DIODES_COUNT + length - j - 1);
				}
				else
				{
					ledOff(length - j - 1);
				}
			_delay_ms(delay);
			}
		}
		for(int i=length - 1;i>=0;i--)
		{
			ledOff(i);
			_delay_ms(delay);	
		}
	}
	
	//2 snakes moving up
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeTwoUp(int delay, int length, int rotationCount)
	{
		for(int i=0;i<rotationCount;i++)
		{
			for(int j=0;j<DIODES_PAIR_COUNT+length;j++)
			{
				if(j < DIODES_PAIR_COUNT)
				{
					ledPairOn(j);
				}
				if(j >= length)
				{
					ledPairOff(j - length);
				}
				_delay_ms(delay);
			}
		}
	}
	
	//2 snakes moving down
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeTwoDown(int delay, int length, int rotationCount)
	{
		for(int i=0;i<rotationCount;i++)
		{
			for(int j=DIODES_PAIR_COUNT-1;j>=-length;j--)
			{
				if(j>=0)
				{
					ledPairOn(j);
				}
				if(j+length<DIODES_PAIR_COUNT)
				{
					ledPairOff(j+length);
				}
				_delay_ms(delay);
			}
		}
	}
	
	//Switching leds On at random sequence
	//delay: delay between led switching. 
	//ledRandNum: array of previuously showed sequence
	//count: diodes count
	void randomLedOn(int delay, int ledRandNum[], int count)
	{
		for(int i=0;i<count;i++)
		{
			int firstIndex=rand()%count;
			int secondIndex=rand()%count;
		
			int third=ledRandNum[firstIndex];
			ledRandNum[firstIndex]=ledRandNum[secondIndex];
			ledRandNum[secondIndex]=third;
		}
	
		ledAllOff();
		for(int i=0;i<count;i++)
		{
			ledOn(ledRandNum[i]);
			_delay_ms(delay);
		}
	}
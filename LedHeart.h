
#define SetPortBit(port, bit) port |= (1<<bit)
//PORTB |= _BV(5);
#define ClearPortBit(port, bit) port &= ~(1<<bit)
//PORTB &= ~(_BV(5));

//Delay at start
#define START_DELAY 250

//Delay at initial switching leds on 
#define INIT_DELAY 5

//Delay between effects
#define EFFECT_DELAY 30

//Delay for falling leds
#define FALL_DELAY 3

#define EVEN_ODD_DELAY 30

//Total diodes count
#define DIODES_COUNT 22

//Diodes count at one sile (left or right)
#define DIODES_SIDE_COUNT 11

//Count of diodes pair
#define DIODES_PAIR_COUNT 12

#define SEQUENCE_PAIR_ON_DELAY 5

#define SNAKE_DELAY 5

int ledRandNum[DIODES_COUNT]=
	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};

  int main(void);
  void performEffects(void);
  
  //Switch on led
  void ledOn(int led);

  //Switch off led
  void ledOff(int led);
  
  //Switch on a pair of leds
  //index: from 0 (bottom) to 11 (top)
  void ledPairOn(int index);
  
  //Switch off a pair of leds
  //index: from 0 (bottom) to 11 (top)
  void ledPairOff(int index);
  
	//Switch on all leds pair by pair from bottom to top
	//delay: delay between pairs
	void SequencePairOn(int delay);
	
	//Switch off all leds pair by pair from bottom to top
	//delay: delay between pairs
	void SequencePairOff(int delay);
	
	//Switch on all leds
	void ledAllOn(void);
	
	//Switch off all leds
	void ledAllOff(void);
	
	//Switch on all odd leds
	void oddAllOn(void);
	
	//Switch off all odd leds
	void oddAllOff(void);
	
	//Switch on all even leds
	void evenAllOn(void);
	
	//Switch off all even leds
	void evenAllOff(void);
		
	//leds Blinking 
	//delay: delay between led switching.
	//rotationCount: Count of switching 
	void ledBlinking(int delay, int rotationCount);
	
	//sequential switching odd and even leds
	//delay: delay between led switching.
	//rotationCount: Count of switching 
	void evenOddOnOff(int delay, int rotationCount);
	
	//Creating heart by falling leds from top to bottom, like stack.
	//delay: delay between led switching.
	void makeHeartByPairFall(int delay);
	
	//Breaking heart by falling leds from top to bottom.
	//delay: delay between led switching.
	void breakHeartByPairFall(int delay);
	
	//ClockWise snake
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeLedClockWise(int delay, int length, int rotationCount);
	
	//AnticlockWise snake
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeLedAnticlockWise(int delay, int length, int rotationCount);
	
	//2 snakes moving up
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeTwoUp(int delay, int length, int rotationCount);
	
	//2 snakes moving down
	//delay: delay between led switching. 
	//length: snake length
	//rotationCount: Count of snake rotation 
	void snakeTwoDown(int delay, int length, int rotationCount);
	
	//Switching leds On at random sequence
	//delay: delay between led switching. 
	//ledRandNum: array of previuously showed sequence
	//count: diodes count
	void randomLedOn(int delay, int ledRandNum[], int count);
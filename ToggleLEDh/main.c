/*Toggling LEDs using special function registers by their names defined in the
compiler header files */
#include "../TM4C123GH6PM.h"

int num;

void delayMs(int n);
int main(void)
{
  SYSCTL->RCGCGPIO |= 0x20;
	num=0;
  GPIOF->DIR |= 0x0E;
  GPIOF->DEN |=0x0E;
  while(1){
		GPIOF->DATA = 0x0E;
		delayMs(500);
		GPIOF->DATA = 0;
		delayMs(500);
	}
}

/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
  int i, j;
  for(i = 0 ; i < n; i++)
	  for(j=0; j < 3180; j++);
}

/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/*coprocessor Grant access*/
/* This is required since TM4C123G has a floating point coprocessor */
	SCB->CPACR |= 0x00F00000;
}

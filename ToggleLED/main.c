/* p2_1.c Toggling LEDs in C using registers by addresses */
/* This program toggles all three LEDs for 0.5 second ON and 0.5 second OFF.*/
/*PF1 - red LED
? PF2 - blue LED
? PF3 - green LED
? They are high active (a '1' turns ON the LED).*/


/* PORTF data register */
#define PORTFDAT (*((volatile unsigned int*)0x400253FC))
/* PORTF data direction register */
#define PORTFDIR (*((volatile unsigned int*)0x40025400))
/* PORTF digital enable register */
#define PORTFDEN (*((volatile unsigned int*)0x4002551C))
/* run mode clock gating register */
#define RCGCGPIO (*((volatile unsigned int*)0x400FE608))
/* coprocessor access control register */
#define SCB_CPAC (*((volatile unsigned int*)0xE000ED88))
void delayMs(int n);/* function prototype for delay */
int num;
int main(void)
{
	RCGCGPIO |= 0x20;
	num=0;
	PORTFDIR |= 0x0E;
	PORTFDEN |= 0x0E;
	while(1)
	{
		PORTFDAT = 0x0E;
		delayMs(500);
		PORTFDAT = 0;
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
	SCB_CPAC |= 0x00F00000;
}



#include <16f628.h>

#fuses NOMCLR, INTRC_IO, NOWDT

#use delay(clock = 4000000)

#define isPressed FALSE //button is pressed
#define isUnPressed TRUE //button is unpressed
#define US PIN_B1 //up speed
#define DS PIN_B2 //down speed
#define limit 8 //adjusted by trial and error

/*STEPPER MOTOR SPEED CONTROL*/

void main()
{
	int8 c1 = 0; //counter 1
	int8 c2 = 0; //counter 2 	
	int8 delay = 5; //controls the speed of motor (the amount of a phase is high)
	int8 d1 = 0; 
	int8 flage = 0;

	Port_b_pullups(TRUE);
	output_low(PIN_B4);
	output_low(PIN_B5);
	output_low(PIN_B6);
	output_low(PIN_B7);

	while (TRUE)
	{
		
		//for down speed button
		if (input(DS) == isUnPressed)
		{
			if (c1 < limit) //keep incrementing c1 untill it equals limit, thus the button is really unpressed
				c1++;
		}
		else
		{
			if (c1 == limit)
			{
				if (delay < 10)  
					delay++;
			}
			c1 = 0;
		}

		//for up speed button
		if (input(US) == isUnPressed)
		{
			if (c2 < limit)  
				c2++;
		}
		else
		{
			if (c2 == limit)
			{
				if (delay > 2)   
					delay--;
			}
			c2 = 0;
		}

		output_high(PIN_B4);
		delay_ms(delay);
		{
			
		}
		output_low(PIN_B4);

		output_high(PIN_B5);
		delay_ms(delay);
		output_low(PIN_B5);

		output_high(PIN_B6);
		delay_ms(delay);
		output_low(PIN_B6);

		output_high(PIN_B7);
		delay_ms(delay);
		output_low(PIN_B7);
	}
}



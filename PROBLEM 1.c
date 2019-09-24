#include <16f628.h>

#fuses NOMCLR, INTRC_IO, NOWDT

#use delay(clock = 4000000)

#define isPressed FALSE //button is pressed
#define isUnPressed TRUE //button is unpressed
#define US PIN_B1 //up speed
#define DS PIN_B2 //down speed
#define limit 8 //adjusted by trial and error

/* DC MOTOR SPEED CONTROL */

void main()
{
	int8 c1 = 0; //counter 1
	int8 c2 = 0; //counter 2 	
	int8 delay = 5; //controls the speed of motor (the amount of a phase is high)
	int8 flageU = 0; //flageU = 1 if we press up button while delay
	int8 flageD = 0; //flage = 1 if we press down button while delay
	int8 count = 0;	

	Port_b_pullups(TRUE);
	output_low(PIN_B4);
	output_low(PIN_B5);
	output_low(PIN_B6);
	output_low(PIN_B7);

	while (TRUE)
	{
		
		//for down speed button
		if (input(DS) == isUnPressed && flageD == 0)
		{
			if (c1 < limit) //keep incrementing c1 untill it equals limit, thus the button is really unpressed
				c1++;
		}
		else
		{
			if (c1 == limit)
			{
				flageD = 0;
				if (delay < 10)  
					delay++;
			}
			c1 = 0;
		}

		//for up speed button
		if (input(US) == isUnPressed && flageU == 0)
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
			while(count < delay)
			{
				delay_ms(1);
				
				if(input(DS) == isPressed)
					flageD = 1;
				
				if(input(US) == isPressed)
					flageU = 1;
				
				count = count + 1;	
			}
			output_low(PIN_B4);
			count = 0;

			output_high(PIN_B5);
			while(count < delay)
			{
				delay_ms(1);
				
				if(input(DS) == isPressed)
					flageD = 1;
				
				if(input(US) == isPressed)
					flageU = 1;
				
				count = count + 1;	
			}
			output_low(PIN_B5);
			count = 0;

			output_high(PIN_B6);
			while(count < delay)
			{
				delay_ms(1);
				
				if(input(DS) == isPressed)
					flageD = 1;
				
				if(input(US) == isPressed)
					flageU = 1;
				
				count = count + 1;	
			}
			output_low(PIN_B6);
			count = 0;

			output_high(PIN_B7);
			while(count < delay)
			{
				delay_ms(1);
				
				if(input(DS) == isPressed)
					flageD = 1;
				
				if(input(US) == isPressed)
					flageU = 1;
				
				count = count + 1;	
			}
			output_low(PIN_B7);	
			count = 0;
		
	}
}



#include <16f628.h>

#fuses NOMCLR,INTRC_IO,NOWDT

#use delay(clock=4000000)

#define isPressed FALSE
#define isUnPressed TRUE
#define US PIN_B1
#define DS PIN_B2
#define limit 8

/*STEPPER MOTOR DIRECTION CONTROL*/

void main()
{
	int8 c1 = 0;
	int8 c2 = 0;
	int8 delay = 5;
	signed char Direction = 1;
	signed char start = 1;

	Port_b_pullups(TRUE);

	output_low(PIN_B4);
	output_low(PIN_B5);
	output_low(PIN_B6);
	output_low(PIN_B7);

	while (TRUE)
	{

		if (input(DS) == isUnPressed)
		{
			if (c1 < limit) c1++;
		}
		else
		{
			//ACTION
			if (c1 == limit)
			{
				Direction = -Direction;
			}
			c1 = 0;
		}

		if (input(US) == isUnPressed)
		{
			if (c2 < limit)  c2++;
		}
		else
		{
			//ACTION
			if (c2 == limit)
			{
				start = -start;
			}
			c2 = 0;
		}
		if (start == 1)
		{
			//ACTION
			if (Direction == 1)
			{
				output_high(PIN_B4);
				delay_ms(delay / 2);
				output_low(PIN_B7);
				delay_ms(delay / 2);
				output_high(PIN_B5);
				delay_ms(delay / 2);
				output_low(PIN_B4);
				delay_ms(delay / 2);
				output_high(PIN_B6);
				delay_ms(delay / 2);
				output_low(PIN_B5);
				delay_ms(delay / 2);
				output_high(PIN_B7);
				delay_ms(delay / 2);
				output_low(PIN_B6);
				delay_ms(delay / 2);


			}
			//ACTION
			if (Direction == -1)
			{
				output_high(PIN_B7);
				delay_ms(delay / 2);
				output_low(PIN_B4);
				delay_ms(delay / 2);
				output_high(PIN_B6);
				delay_ms(delay / 2);
				output_low(PIN_B7);
				delay_ms(delay / 2);
				output_high(PIN_B5);
				delay_ms(delay / 2);
				output_low(PIN_B6);
				delay_ms(delay / 2);
				output_high(PIN_B4);
				delay_ms(delay / 2);
				output_low(PIN_B5);
				delay_ms(delay / 2);

			}
		}
		else
		{
			output_low(PIN_B4);
			output_low(PIN_B5);
			output_low(PIN_B6);
			output_low(PIN_B7);
			delay_ms(delay);
		}

	}
}



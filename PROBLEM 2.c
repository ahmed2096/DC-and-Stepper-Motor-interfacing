#include <16f628.h>
#fuses NOMCLR, INTRC_IO, NOWDT
#use delay(clock = 4000000)
#define isPressed FALSE
#define isUnPressed TRUE
#define US PIN_B1
#define DS PIN_B2
#define REVERSE PIN_B0
#define limit 8

/*DIRECTION AND SPEED CONTROL OF DC MOTOR*/

void main()
{
	int8 c1 = 0;
	int8 c2 = 0;
	int8 duty = 90;

	Port_b_pullups(TRUE);
	output_high(PIN_B4);


	setup_timer_2(T2_DIV_BY_16, 100, 2);
	setup_ccp1(CCP_PWM);

	set_pwm1_duty(duty);
	while (TRUE)
	{

		if (input(DS) == isUnPressed)
		{
			if (c1 < limit) c1++;
		}
		else
		{
			if (c1 == limit)
			{
				if (duty < 100)
				{
					duty = duty + 10;
					set_pwm1_duty(duty);
				}
			}
			c1 = 0;
		}

		if (input(US) == isUnPressed)
		{
			if (c2 < limit)  c2++;
		}
		else
		{
			if (c2 == limit)
			{
				if (duty > 0)
				{
					duty = duty - 10;
					set_pwm1_duty(duty);
				}
			}
			c2 = 0;
		}

		if (input(REVERSE) == isUnPressed)
		{
			if (c1 < limit) c1++;
		}
		else
		{
			if (c1 == limit)
			{
				if (Direction == 1)
				{
					Direction = -1;
					output_low(PIN_B4);
					output_high(PIN_B5);
				}
				else
				{
					Direction = 1;
					output_low(PIN_B5);
					output_high(PIN_B4);
				}
			}
			c1 = 0;
		}
		delay_ms(1);
	}
}



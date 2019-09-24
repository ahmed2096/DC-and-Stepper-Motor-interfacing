#include <16f628.h>
#fuses NOMCLR, INTRC_IO, NOWDT
#use delay(clock = 4000000)
#define isPressed FALSE
#define isUnPressed TRUE
#define US PIN_B1
#define DS PIN_B2
#define limit 8


/*Gradually increase or decrease motor speed using PWM*/

void main()
{
	int8 c1 = 0;
	int8 c2 = 0;
	int8 duty = 0;

	Port_b_pullups(TRUE);



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
				while (duty != 100)
				{
					duty = duty + 2;
					set_pwm1_duty(duty);
					delay_ms(1);
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
				while (duty != 0)
				{
					duty = duty - 2;
					set_pwm1_duty(duty);
					delay_ms(1);
				}
			}
			c2 = 0;
		}
		delay_ms(1);
	}
}



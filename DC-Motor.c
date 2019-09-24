#include <16f628.h>

#fuses NOMCLR,INTRC_IO,NOWDT

#use delay(clock=4000000)

#define isPressed FALSE
#define isUnPressed TRUE
#define US PIN_B1
#define DS PIN_B2
#define limit 8

void main()
{
	int8 c1 = 0;
	int8 c2 = 0;
	int8 duty = 10;


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
				if (duty < 100) {
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
				if (duty > 0) {
					duty = duty - 10;
					set_pwm1_duty(duty);
				}
			}
			c2 = 0;
		}
		delay_ms(1);
	}
}



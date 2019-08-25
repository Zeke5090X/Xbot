#include "main.h"
if (state==0)
{
	if (master.get_digital_new_press(DIGITAL_R1))
	{
		state = 1;
	}
	if (master.get_digital_new_press(DIGITAL_R2))
	{
		state = -1;
	}
	ri_mtr.move_velocity(0);
	li_mtr.move_velocity(0);
}
else if(state==1)
{
	if (master.get_digital_new_press(DIGITAL_R1))
	{
		state = 0;
	}
	if (master.get_digital_new_press(DIGITAL_R2))
	{
		state = -1;
	}
	ri_mtr.move_velocity(200);
	li_mtr.move_velocity(200);
}
else
{
	if (master.get_digital_new_press(DIGITAL_R1))
	{
		state = 1;
	}
	if (master.get_digital_new_press(DIGITAL_R2))
	{
		state = 0;
	}
	ri_mtr.move_velocity(-200);
	li_mtr.move_velocity(-200);
}

#include "main.h"
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {

	int state;
	state = 0;
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
    lf_mtr.move(master.get_analog(ANALOG_LEFT_Y));
		lb_mtr.move(master.get_analog(ANALOG_LEFT_Y));
		rf_mtr.move(master.get_analog(ANALOG_RIGHT_Y));
		rf_mtr.move(master.get_analog(ANALOG_RIGHT_Y));
		//drive train code
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
//deactivated intake
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
//active intake
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
//reversed intake
if (master.get_digital(DIGITAL_L1))
{
	t_mtr.move_velocity(50);
}
else if(master.get_digital(DIGITAL_L2))
{
	t_mtr.move_velocity(-50);
}
else
{
	t_mtr.move_velocity(0);
}
//temporary tray tilter controlls
//will eventually be moved to partner controller as a backup
if (master.get_digital(DIGITAL_UP))
{
	a_mtr.move_velocity(-50);
}
else if(master.get_digital(DIGITAL_DOWN))
{
	a_mtr.move_velocity(50);
}
else
{
	a_mtr.move_velocity(0);
pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_HOLD);
}
		pros::delay(20);
	}
}

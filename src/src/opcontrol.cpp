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
    lfmtr.move(master.get_analog(ANALOG_LEFT_Y));
		lbmtr.move(master.get_analog(ANALOG_LEFT_Y));
		rfmtr.move(master.get_analog(ANALOG_RIGHT_Y));
		rbmtr.move(master.get_analog(ANALOG_RIGHT_Y));
		//drive train code
		if(master.get_digital_new_press(DIGITAL_R1))
		{
			state = 1;
		}
		if(master.get_digital_new_press(DIGITAL_R2))
		{
			state = -1;
		}
		if(master.get_digital_new_press(DIGITAL_L1))
		{
			state = 0;
		}
		if(master.get_digital_new_press(DIGITAL_L2))
		{
			state = -2;
		}
		if(state==0)
		{
			limtr.move(0);
			rimtr.move(0);
		}
		else if(state==1)
		{
				limtr.move(127);
				rimtr.move(-127);
		}
		else if(state==-1)
		{
			limtr.move(-127);
			rimtr.move(127);
		}
		else
		{
			{
				limtr.move_velocity(-20);
				rimtr.move_velocity(20);
			}

		}

if (slave.get_digital(DIGITAL_L1))
{
	tmtr.move_velocity(50);
}
else if(slave.get_digital(DIGITAL_L2))
{
	tmtr.move_velocity(-50);
}
else
{
	tmtr.move_velocity(0);
}
//temporary tray tilter controlls
//will eventually be moved to partner controller as a backup
if (slave.get_digital(DIGITAL_UP))
{
	amtr.move_velocity(50);
}
else if(slave.get_digital(DIGITAL_DOWN))
{
	amtr.move_velocity(-50);
}
else
{
	amtr.move_velocity(0);
pros::c::motor_set_brake_mode(14, MOTOR_BRAKE_HOLD);
}

pros::lcd::print(0, "Left Front Wheel: %lf\n", pros::c::motor_get_temperature(1));
pros::lcd::print(1, "Left Back Wheel: %lf\n", pros::c::motor_get_temperature(2));
pros::lcd::print(2, "Right Front Wheel: %lf\n", pros::c::motor_get_temperature(3));
pros::lcd::print(3, "Right Back Wheel: %lf\n", pros::c::motor_get_temperature(4));
pros::lcd::print(4, "Left Intake: %lf\n", pros::c::motor_get_temperature(11));
pros::lcd::print(5, "Right Intake: %lf\n", pros::c::motor_get_temperature(12));
pros::lcd::print(6, "Arm: %lf\n", pros::c::motor_get_temperature(13));
pros::lcd::print(7, "Trey Tilter: %lf\n", pros::c::motor_get_temperature(14));

		pros::delay(30);
	}
}

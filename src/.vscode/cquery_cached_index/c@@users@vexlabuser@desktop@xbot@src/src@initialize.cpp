#include "main.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();


	pros::lcd::register_btn1_cb(on_center_button);
	pros::c::motor_set_brake_mode(1,MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(2,MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(3,MOTOR_BRAKE_COAST);
  pros::c::motor_set_brake_mode(4,MOTOR_BRAKE_COAST);
	pros::c::motor_set_brake_mode(11,MOTOR_BRAKE_HOLD);
	pros::c::motor_set_brake_mode(13,MOTOR_BRAKE_HOLD);
  
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
if (pot.get_value()<1)
{
	pros::lcd::print(1,"hey it works!");
}
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize(){}
/*lv_obj_t * myButton;
lv_obj_t * myButtonLabel;
lv_obj_t * myLabel;

lv_style_t myButtonStyleREL; //released style
lv_style_t myButtonStylePR; //pressed style

static lv_res_t LV_BTN_ACTION_CLICK(lv_obj_t * btn)
{
}
*/

#include "main.h"
pros::Controller master (pros::E_CONTROLLER_MASTER);
pros::Controller slave (pros::E_CONTROLLER_PARTNER);
pros::Motor lf_mtr(1);
pros::Motor lb_mtr(2);
pros::Motor rf_mtr(3, true);
pros::Motor rb_mtr(4, true);
pros::Motor li_mtr(11);
pros::Motor ri_mtr(12,true);
pros::Motor a_mtr(14,36);
pros::Motor t_mtr(13, 36);

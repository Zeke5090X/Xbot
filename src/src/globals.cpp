#include "main.h"

pros::Controller master (pros::E_CONTROLLER_MASTER);
pros::Controller slave (pros::E_CONTROLLER_PARTNER);
pros::Motor lfmtr(1);
pros::Motor lbmtr(2);
pros::Motor rfmtr(3, true);
pros::Motor rbmtr(4, true);
pros::Motor limtr(11,36);
pros::Motor rimtr(12,36);
pros::Motor amtr(14,36);
pros::Motor tmtr(13, 36);
pros::ADIAnalogIn pot(1);

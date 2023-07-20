#include "globals.hpp"
#include "main.h"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"

/*

This file of code names each system component called in other files of code. It
will be included in the initial declaration of each associated file of code.

The first statement names the controller - when it's called in a file of code, it 
will be under pros::E_CONTROLLER_MASTER.

The following lines name each motor and port called in the code after the
declaration of pros::Motor. This is followed by the the port number each motor or port
is connected to on the V5 brain as well as its direction type.
*/

//This line defines the controller
pros::Controller master(CONTROLLER_MASTER);

//These lines define the drivetrain motors
pros::Motor driveFL(1); 
pros::Motor driveFR(2); 
pros::Motor driveBL(3); 
pros::Motor driveBR(4);  
pros::Motor intakeL(6); 
pros::Motor intakeR(7); 

//These lines define the sensors
pros::Imu inertial(5);
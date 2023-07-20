#pragma once
#include "globals.hpp"
#include "main.h"
#include "pros/motors.hpp"

/*
These commands tell the code that the following devices will be included in other
external files.
*/

extern pros::Controller master;
extern pros::Motor driveFL; 
extern pros::Motor driveFR; 
extern pros::Motor driveBL; 
extern pros::Motor driveBR;  
extern pros::Motor intakeL; 
extern pros::Motor intakeR; 
extern pros::Imu inertial;
#pragma once
#include "globals.hpp"

/*
These commands tell the code that the following functions will be included in other
external files.
*/

extern void drive(int position, int velocity);
extern void left_turn(double setpoint, int speed);
extern void right_turn(double setpoint, int speed);
extern void drive_turn(int position, int velocity);
extern void intake(int position, int velocity);
extern void outtake(int position, int velocity);
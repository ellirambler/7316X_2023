#include "functions.hpp"
#include "globals.hpp"

/*
This function states that when it is called, the condition of a unit of velocity
will set motors driveFL, driveBL, driveFR, and driveBR to the same unit of velocity.

This means that when this function is called, the entire drivetrain will run for 
the given amount of units in the given direction at the given speed.
*/

	void drive(int position, int velocity) {
		driveFL.move_relative(position, velocity);
		driveBL.move_relative(position, velocity);
		driveFR.move_relative(position, velocity);
		driveBR.move_relative(position, velocity);	
	}

/*
This function states that when it is called, the condition of a unit of velocity will 
set motors driveFL and driveBL to the same unit of velocity and set motors driveFR and 
driveBR to the additive inverse of the same unit of velocity. This causes the entire 
drivetrain to turn to the right for the given amount of time.

It also sets a while loop that says while the motors are set to this unit of velocity,
the gyroscope in the inertial sensor gets the yaw angle, which redirects the robot to an 
angle less than the given setpoint. After a delay, all motors called are set back to 0.
*/

	void left_turn(double setpoint, int speed) {
		driveFL.move_velocity(speed*-1);
		driveBL.move_velocity(speed*1);
		driveFR.move_velocity(speed*-1);
		driveBR.move_velocity(speed*1);

		while ((inertial.get_yaw()<setpoint))
			pros::delay(10);
		
		driveFL.move_velocity(0);
		driveBL.move_velocity(0);
		driveFR.move_velocity(0);
		driveBR.move_velocity(0);
	}

/*
This function states that when it is called, the condition of a unit of velocity will 
set motors driveFL and driveBL to the same unit of velocity and set motors driveFR and 
driveBR to the additive inverse of the same unit of velocity. This causes the entire 
drivetrain to turn to the left for the given amount of time.

It also sets a while loop that says while the motors are set to this unit of velocity,
the gyroscope in the inertial sensor gets the yaw angle, which redirects the robot to an 
angle less than the given setpoint. After a delay, all motors called are set back to 0.
*/

	void right_turn(double setpoint, int speed) {
		driveFL.move_velocity(speed*1);
		driveBL.move_velocity(speed*-1);
		driveFR.move_velocity(speed*1);
		driveBR.move_velocity(speed*-1);

		while ((inertial.get_yaw()<setpoint))
			pros::delay(10);
		
		driveFL.move_velocity(0);
		driveBL.move_velocity(0);
		driveFR.move_velocity(0);
		driveBR.move_velocity(0);
		}

/*
This function states that when it is called, the condition of a unit of velocity will 
set motors driveFL and driveBL to the same unit of velocity and set motors driveFR and 
driveBR to the additive inverse of the same unit of velocity.

This means that when this function is called, the left side of the drivetrain will 
run for the given amount of units in the given direction at the given speed while
the right side of the drivetrain will run for the same amount of units at the same
speed but in the opposite direction, making the whole drivetrain turn.
*/

		void drive_turn(int position, int velocity) {
		driveFL.move_relative(-position, -velocity);
		driveBL.move_relative(position, velocity);
		driveFR.move_relative(-position, -velocity);
		driveBR.move_relative(position, velocity);
		}

/*
This function states that when it is called, the condition of a unit of velocity and
a unit of time will set the motors intakeL and intakeR to equal and opposite velocities 
and the delay to the unit of time.

This means that when this function is called, the motors intakeL and intakeR will run for the 
given amount of units in the given opposites direction at the given speed, making the intake
mechanism rotate inward.
*/

void intake(int position, int velocity) {
		intakeL.move_relative(-position, -velocity);
		intakeR.move_relative(position, velocity);
	}

/*
This function states that when it is called, the condition of a unit of velocity and
a unit of time will set the motors intakeL and intakeR to equal and opposite velocities 
and the delay to the unit of time.

This means that when this function is called, the motors intakeL and intakeR will run for the 
given amount of units in the given opposites direction at the given speed, making the intake
mechanism rotate outward.
*/

void outtake(int position, int velocity) {
		intakeL.move_relative(position, velocity);
		intakeR.move_relative(-position, -velocity);
	}
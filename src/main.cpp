#include "functions.hpp"
#include "globals.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"


/*
The value autonSlct is used under the autonomous function to set the auton 
selector to 0 so it can run separate codes when set to separate values.
*/

int autonSlct = 0;

/*
A callback function for LLEMU's center button. When this function is enacted, it 
will toggle between the left side autonomous, right side autonomous, and skills 
autonomous when the selector is set to 1, 2, or 3 respectively before a function 
under void autonomous.
*/

void on_center_button() {
	int AutonMax = 9;
	char AutonNames [10] [10] = {"empty", "empty", "empty", "empty", 
	"empty", "empty", "empty", "empty", "empty", "empty"};
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		autonSlct ++;
		pros::lcd::set_text(1,AutonNames[autonSlct]);
	}
	if (autonSlct == AutonMax){
		autonSlct = 0;
	}
}

/*
Runs initialization code. This occurs as soon as the program is started.
All other competition modes are blocked by initialize; it is recommended
to keep execution time for this mode under a few seconds.
*/

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Stay silly :)");

	pros::lcd::register_btn1_cb(on_center_button);
}


void disabled() {}

/*
Runs after initialize(), and before autonomous when connected to the Field
Management System or the VEX Competition Switch. This is intended for
competition-specific initialization routines, such as an autonomous selector
on the LCD.

This task will exit when the robot is enabled and autonomous or opcontrol
starts.
*/

void competition_initialize() {}

/*
Runs the user autonomous code. This function will be started in its own task
with the default priority and stack size whenever the robot is enabled via
the Field Management System or the VEX Competition Switch in the autonomous
mode. Alternatively, this function may be called in initialize or opcontrol
for non-competition testing purposes.

If the robot is disabled or communications is lost, the autonomous task will 
be stopped. Re-enabling the robot will restart the task, not re-start it from 
where it left off.
*/

void autonomous() {

/*
This statement sets the initial value of the auton selector as equal to 0,
meaning when it is pressed following this statement, it will the value
will increase and switch between each set of code assigned to that value.
*/

	autonSlct = 0;

}

/*
Runs the operator control code. This function will be started in its own task
with the default priority and stack size whenever the robot is enabled via
the Field Management System or the VEX Competition Switch in the operator
control mode.
 
If no competition control is connected, this function will run immediately
following initialize().
 
If the robot is disabled or communications is lost, the operator control task 
will be stopped. Re-enabling the robot will restart the task, not resume it 
from where it left off.
*/

void opcontrol() {
	
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 0,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 2);
 
/*
These statements set the variable left as being enacted by the analog left axis
and the variable right as being enacted by the analog right axis.
*/
		int left = master.get_analog(ANALOG_LEFT_Y); 
		int right = master.get_analog(ANALOG_RIGHT_Y);

/*
These statements set the motors driveFL and driveBL as being enacted forward 
by the analog left axis being moved forward and the motors driveFr and driveBR 
as being enacted forwarded by the analog right axis.
*/

		driveFL.move(left);
		driveBL.move(left);

		driveFR.move(right);
		driveBR.move(right);

/*
This if-else statement tells the controller that when the digital L1 button is
engaged, the motor intakeL will run with a voltage of -12000 millivolts and the 
motor intakeR will run with a voltage of 12000 millivolts

In the condition of the L2 button being engaged, the motor intakeL will run with 
a voltage of 12000 millivolts and the motor intakeR will run with a voltage of -12000 
millivolts

If neither L2 or L1 are engaged, the motor intakeRoller will run with a voltage of 0 
millivolts.

This means that when L1 is pressed, the intake mech will run inward, when L2 is pressed, 
the intake mech will run outward, and when neither are pressed neither will run.
*/

if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intakeL.move_voltage(-12000);
		intakeR.move_voltage(12000);
    } 

else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		intakeL.move_voltage(12000);
		intakeR.move_voltage(-12000);
	}

else {
    intakeL.move_voltage(0);
		intakeR.move_voltage(0);
    }
		
/*
This statement tells the robot that when the gyroscope in the inertial sensor
is getting the yaw angle, it should print the stated information on the brain's
screen before setting the sensor to a delay.
*/

	(
		printf("IMU yaw: %f\n", inertial.get_yaw()));
		pros::delay(20);
	}

	pros::delay(20);
}
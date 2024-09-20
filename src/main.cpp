/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Nyx                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "constants.h"
#include "functions.hpp"
#include "autons.hpp"
#include "odom.hpp"

using namespace vex;

competition Competition;
thread odom(Odometer::Odometry); // Runs a thread for the odometry system


/// @brief Pre-Autonomous setup code 
void pre_auton(void) {
  vexcodeInit();

  // Prints a warning to the screen if the robot battery is below 20% on start
  if (Brain.Battery.capacity() < kLowBattery) {
    joystick.Screen.print("BATTERY LOW - PLEASE CHANGE IT");
    joystick.rumble("...---...");
  }

  // Resets the encoders and calibrates the inertial sensor
  xDis.resetRotation();
  yDis.resetRotation();

  bool isCalibrated = false; // Boolean value for if the IMU is calibrated

  intake.setVelocity(100, percentUnits::pct); // Sets the velocity of the intake
  goalLock.set(false); // Makes sure the goal lock is open at the beginning of the match 
  

  // Clibrates the Inertial sensor if it hasn't been already 
  if (!isCalibrated) {
    imu.calibrate();
    waitUntil(!imu.isCalibrating());
    isCalibrated = true;
    joystick.rumble(rumbleShort);
  }
}


/// @brief Autonomous task
void autonomous(void) {
  timer t;   // Timer used for autonomous practice
  t.clear(); // Clears the timer to set the current value to 0

  switch (kAutoSelected) {
    case 1:
      auto1();
      break;
    case 99:
      calibratePID(kCalibrateMode);
      break;
    default:
      calibratePID(kCalibrateMode);
      break;
  }

  printf("Autonomous Runtime: %fs\n\n", t.time(timeUnits::sec)); // Prints the runtime of the autonomous to the console
}


/// @brief Driver control task
void usercontrol(void) {
  thread drive(driveThread); // Runs a thread for the drive system
  timer t; // Timer for user control 

  clearTerminal();

  t.reset();

  while (true) {
    // Generic toggles for the drive 
    kDriveFrontToggle.pressed([] () { isFrontReversed = !isFrontReversed; });
    kDriveTypeToggle.pressed([] () { isExponentialDrive = !isExponentialDrive; });


    // Goal lock toggle 
    kGoalLockToggle.pressed([] () { 
      goalLock.set(!goalLock.value()); 
      printf("Goal lock current value: %s\n", goalLock.value() ? "true" : "false");
    });


    // Lift Macro 
    kLiftMacroButton.pressed(liftMacro);


    // Runs the intake given controller input 
    if (kIntakeInButton.pressing()) {
      intake.spin(directionType::fwd);
    } else if (kIntakeOutButton.pressing()) {
      intake.spin(directionType::rev);
    } else {
      intake.stop(brakeType::brake);
    }

    // Time warning for the last 20 seconds of the match 
    if (t.time(timeUnits::sec) >= 70) {
      joystick.rumble(rumbleLong);
    }

    
    wait(20, msec);
  }
}



int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
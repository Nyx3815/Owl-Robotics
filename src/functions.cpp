#include "functions.hpp"
#include "constants.h"

double conversion = kDegToInch * kGearRatio; 
bool isExponentialDrive = true;
bool isFrontReversed = false;
bool isLiftMacroRunning = false;


/// @brief Moves the robot forwards a certain amount 
/// @param distance Distance to move in inches 
/// @param pause Whether or not the system waits to move on
void fd(double distance, bool pause) {
  driveLeft.spinFor(directionType::fwd, distance * conversion, rotationUnits::deg);
  driveRight.spinFor(directionType::fwd, distance * conversion, rotationUnits::deg);
}


/// @brief Moves the robot backwards a certain amount
/// @param distance Distance to move in inches  
/// @param pause Whether or not the system waits to move on
void bd(double distance, bool pause) {
  driveLeft.spinFor(directionType::rev, distance * conversion, rotationUnits::deg);
  driveRight.spinFor(directionType::rev, distance * conversion, rotationUnits::deg);
}


/// @brief Turns the robot to the right 
/// @param distance Amount for the wheels to move
/// @param pause Whether or not the system waits to move on 
void rt(double distance, bool pause) {
  driveLeft.spinFor(directionType::fwd, distance * conversion, rotationUnits::deg);
  driveRight.spinFor(directionType::rev, distance * conversion, rotationUnits::deg);
}


/// @brief Turns the robot to the left
/// @param distance Amount for the wheels to move 
/// @param pause Whether or not the system waits to move on
void lt(double distance, bool pause) {
  driveLeft.spinFor(directionType::rev, distance * conversion, rotationUnits::deg);
  driveRight.spinFor(directionType::fwd, distance * conversion, rotationUnits::deg);
}


/// @brief Moves the drive based on controller input 
/// @param move Value for the movement controller axis
/// @param turn Value for the turning controller axis 
void controllerSpeed(int move, int turn) {
  driveLeft.spin(directionType::fwd, move + turn, percentUnits::pct);
  driveRight.spin(directionType::fwd, move - turn, percentUnits::pct);
}


/// @brief Sets the velocity of the drive motors
/// @param speed Speed percentage of the drive
void driveSpeed(int speed) {
  driveLeft.setVelocity(speed, percentUnits::pct);
  driveRight.setVelocity(speed, percentUnits::pct);
}


/// @brief Sets the brake type of the drive motors
/// @param x Brake type 
void setDriveBrakeType(brakeType x) {
  driveLeft.setStopping(x);
  driveRight.setStopping(x);
}


/// @brief Gets the value of the drive using an exponential system 
/// @param n Drive value
/// @param e Exponent
/// @return The drive speed value
int getExponential(int n, int e) {
  e = e < 1 ? 1 : e;
  int speed = e % 2 == 0 ? n < 0 ? (-1 * pow(n, e)) / (pow(100, (e - 1))) : pow(n, e) / (pow(100, (e - 1))) : pow(n, e) / (pow(100, (e - 1)));

  return speed;
}


/// @brief Acts as a drive thread 
int driveThread() {
  double moveSpd;
  double turnSpd;

  while (true) {
    // Controller input speeds
    moveSpd = abs(kMoveSpeedAxis.position()) > kDeadband ? kMoveSpeedAxis.position() : 0;
    turnSpd = abs(kTurnSpeedAxis.position()) > kDeadband ? kTurnSpeedAxis.position() : 0;

    // Converts the Y-Speed variable depending on the front direction 
    moveSpd *= isFrontReversed ? -1 : 1;

    // Checks if the robot drive should be scaled 
    if (isExponentialDrive) {
      moveSpd = getExponential(moveSpd, kDriveExponent);
      turnSpd = getExponential(turnSpd, kDriveExponent);
    }

    // Motor Spin Functions
    controllerSpeed(moveSpd, turnSpd);

    // Pauses the thread as to not overload the brain 
    this_thread::sleep_for(20);
  }

  return 1;
}


/// @brief Runs a macro to move the lift system to climb one ladder
void liftMacro() {
  /* 
  Lift code requirements:
    - Be able to tell when the hooks are set 
    - Be able to tell when the robot is fully hung 
  */

  if (!isLiftMacroRunning) {
    
  } else {
    joystick.rumble(rumbleShort);
  }
}


/// @brief Sends a warning to the controller if the battery is below a certain percentage 
void batteryWarning() {
  if (Brain.Battery.capacity() <= kLowBattery) {
    joystick.rumble("...---...");
  }
}


/// @brief Resets the heading of the IMU 
void resetRobotHeading() {
  imu.resetHeading();
}


/// @brief Clears the terminal of any previous output
void clearTerminal() {
  printf("\033[H\033[2J");
}
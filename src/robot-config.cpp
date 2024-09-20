#include "vex.h"
#include "constants.h"

using namespace vex;

// Brain and Controller 

brain Brain;
controller joystick(controllerType::primary);

// Drive Motors 

motor frontL(kFrontLeftPort);
motor midL(kMiddleLeftPort);
motor backL(kBackLeftPort);

motor frontR(kFrontRightPort);
motor midR(kMiddleRightPort);
motor backR(kBackRightPort);

motor_group driveLeft(frontL, midL, backL);
motor_group driveRight(frontR, midR, backR);


// Sensors 

encoder xDis(kEncoderPortX);
encoder yDis(kEncoderPortY);
inertial imu(kInertialPort);

distance leftDistance(kLeftDistancePort);
distance rightDistance(kRightDistancePort);


// Effector motors & pneumatics

motor liftMotor1(kLiftMotor1Port, ratio36_1, false);
motor liftMotor2(kLiftMotor2Port, ratio36_1, false);

pneumatics goalLock(kGoalLockPort);

motor intake(kIntakeMotorPort, ratio18_1, false);


// VEX Code stuff 

void vexcodeInit(void) {
  // Nothing to initialize
}
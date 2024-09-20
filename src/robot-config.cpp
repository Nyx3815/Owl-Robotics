#include "vex.h"
#include "constants.h"

using namespace vex;

// Brain and Controller 

brain Brain;
controller joystick(controllerType::primary);

// Drive Motors 

motor frontL(kFrontLeftPort, kDriveRatio, false);
motor midL1(kMiddle1LeftPort, kDriveRatio, false);
motor midL2(kMiddle2LeftPort, kDriveRatio, false);
motor backL(kBackLeftPort, kDriveRatio, false);

motor frontR(kFrontRightPort, kDriveRatio, false);
motor midR1(kMiddle1RightPort, kDriveRatio, false);
motor midR2(kMiddle2RightPort, kDriveRatio, false);
motor backR(kBackRightPort, kDriveRatio, false);

motor_group driveLeft(frontL, midL1, midL2, backL);
motor_group driveRight(frontR, midR1, midR2, backR);


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
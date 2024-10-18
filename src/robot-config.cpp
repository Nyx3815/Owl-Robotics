#include "vex.h"
#include "constants.h"

using namespace vex;

// Brain and Controller 

brain Brain;
controller joystick(controllerType::primary);

// Drive Motors 

motor frontL(kFrontLeftPort, kDriveRatio, true);
motor midL1(kMiddle1LeftPort, kDriveRatio, true);
motor midL2(kMiddle2LeftPort, kDriveRatio, false);
motor backL(kBackLeftPort, kDriveRatio, true);

motor frontR(kFrontRightPort, kDriveRatio, true);
motor midR1(kMiddle1RightPort, kDriveRatio, true);
motor midR2(kMiddle2RightPort, kDriveRatio, true);
motor backR(kBackRightPort, kDriveRatio, true);

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
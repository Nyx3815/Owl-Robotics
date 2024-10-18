#include "robot-config.h"

// Drivebase constants

#define kWheelDiameterInches     4
#define kEncoderOffsetX          0 // Distance between sensors and edge of robot in the X direction 
#define kEncoderOffsetY          0 // Distance between sensors and edge of robot in the Y direction 
#define kGearRatio               (23.0 / 33.0) // Drive gear ratio  
#define kDriveRatio              ratio18_1


// Device Ports

#define kFrontLeftPort          PORT20
#define kMiddle1LeftPort        PORT19
#define kMiddle2LeftPort        PORT18
#define kBackLeftPort           PORT17

#define kFrontRightPort         PORT11
#define kMiddle1RightPort       PORT15
#define kMiddle2RightPort       PORT13
#define kBackRightPort          PORT16

#define kInertialPort           PORT16
#define kEncoderPortX           Brain.ThreeWirePort.B
#define kEncoderPortY           Brain.ThreeWirePort.C

#define kLeftDistancePort       PORT10
#define kRightDistancePort      PORT11

#define kLiftMotor1Port         PORT12
#define kLiftMotor2Port         PORT13

#define kIntakeMotorPort        PORT14

#define kGoalLockPort           Brain.ThreeWirePort.A



// IO Constants

#define kDeadband               10 // Minimum value for joystick input, which reduces drift 
#define kDriveExponent          2

#define kMoveSpeedAxis          joystick.Axis4 // Left side X-axis
#define kTurnSpeedAxis          joystick.Axis3 // Left side Y-axis

#define kDriveTypeToggle        joystick.ButtonA // Button for drive type toggle
#define kDriveFrontToggle       joystick.ButtonX // Button for drive front toggle 

#define kLiftMacroButton        joystick.ButtonL1 // Button for the lift macro 

#define kIntakeInButton         joystick.ButtonR2 // Button for intake 
#define kIntakeOutButton        joystick.ButtonR1 // Button for output

#define kGoalLockToggle         joystick.ButtonL2 // Button for locking the goal 

#define kLowBattery             20



// Autonomous Constants

#define kAutoSelected           1
#define driveKp                 0.1 // PID proportional gain
#define driveKi                 0 // PID integral gain
#define driveKd                 0 // PID derivative gain
#define kCalibrateMode          'x' // Mode variable for PID tuning
#define kDegToInch              ((M_PI * kWheelDiameterInches) / 360)
#define kDegToRad               (M_PI / 180)
#define kRadToDeg               (180 / M_PI)
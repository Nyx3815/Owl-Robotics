#include "robot-config.h"

// Drivebase constants

#define kWheelDiameterInches     4
#define kEncoderOffsetX          0 // Distance between sensors and edge of robot in the X direction 
#define kEncoderOffsetY          0 // Distance between sensors and edge of robot in the Y direction 
#define kGearRatio               1 
#define kDriveRatio              ratio18_1


// Device Ports

#define kFrontLeftPort          PORT1
#define kMiddleLeftPort         PORT2
#define kBackLeftPort           PORT3
#define kFrontRightPort         PORT4
#define kMiddleRightPort        PORT5
#define kBackRightPort          PORT6

#define kInertialPort           PORT7
#define kEncoderPortX           Brain.ThreeWirePort.A
#define kEncoderPortY           Brain.ThreeWirePort.B

#define kLeftDistancePort       PORT8
#define kRightDistancePort      PORT9

#define kLiftMotor1Port         PORT10
#define kLiftMotor2Port         PORT11

#define kIntakeMotorPort        PORT12

#define kGoalLockPort           Brain.ThreeWirePort.C



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
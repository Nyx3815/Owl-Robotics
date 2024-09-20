using namespace vex;

// Brain and Controller

extern brain Brain;
extern controller joystick;


// Drive Motors 

extern motor frontL;
extern motor midL1;
extern motor midL2;
extern motor backL;

extern motor frontR;
extern motor midR1;
extern motor midR2;
extern motor backR;

extern motor_group driveLeft;
extern motor_group driveRight;


// Sensors 

extern encoder xDis;
extern encoder yDis;
extern inertial imu;

extern distance leftDistance;
extern distance rightDistance;


// Effector motors & pneumatics

extern motor liftMotor1;
extern motor liftMotor2;

extern pneumatics goalLock;

extern motor intake;


// VEX Code stuff

void vexcodeInit(void);
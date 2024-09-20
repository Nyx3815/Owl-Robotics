#ifndef FUNCTIONS
#define FUNCTIONS

#include "vex.h"

// VARIABLES 

extern double conversion;
extern bool isExponentialDrive;
extern bool isFrontReversed;
extern bool isLiftMacroRunning;
extern bool isLocked;


// METHODS 

void fd(double distance, bool pause = true);
void bd(double distance, bool pause = true);
void rt(double distance, bool pause = true);
void lt(double distance, bool pause = true);

void controllerSpeed(int move, int turn);
void driveSpeed(int speed);

void setDriveBrakeType(brakeType x);

int getExponential(int n, int e = 2);
int driveThread();

void liftMacro();

void batteryWarning();
void resetRobotHeading();
void clearTerminal();

#endif // FUNCTIONS
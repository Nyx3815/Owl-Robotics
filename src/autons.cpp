#include "vex.h"
#include "odom.hpp"
#include "autons.hpp"
#include "functions.hpp"

#include "pidSystem.hpp"

PidSystem movePID(driveKp, driveKi, driveKd);
PidSystem turnPID(0.25, 0, 0);


/// @brief Spins 180 degrees 
void auto1() {
  double desiredHeading = imu.heading() + 180;

  do {
    controllerSpeed(0, turnPID.calculate(imu.heading(), desiredHeading));
  } while (!turnPID.isFinished());
}


/// @brief Moves the robot to either 3ft or 90 degrees  
/// @param mode Calibrate mode: [m] or [t]
void calibratePID(char mode) {
  switch (mode) {
    case 'm':
      do {
        controllerSpeed(movePID.calculate(36, sqrt(pow(Odometer::position.xPos, 2) + pow(Odometer::position.yPos, 2))), 0);
      } while (!movePID.isFinished());

      break;
    case 't':
      double desiredHeading = imu.heading() + 90;

      do {
        controllerSpeed(0, turnPID.calculate(90, desiredHeading));
      } while (!turnPID.isFinished());

      break;
  }
}
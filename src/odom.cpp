#include "vex.h"
#include "odom.hpp"
#include "constants.h"

#include <cmath>

using namespace vex;
using std::atan;
using std::remainder;

Pose2D Odometer::position = {kEncoderOffsetX, kEncoderOffsetY, 0}; // Current robot position 
Pose2D Odometer::lastPosition = {0, 0, 0}; // Previous robot position 
Pose2D Odometer::deltaPosition = {0, 0, 0}; // Change in robot position 

EncoderValues Odometer::values = {0, 0, 0}; // Current encoder values
EncoderValues Odometer::lastValues = {0, 0, 0}; // Previous encoder values
EncoderValues Odometer::deltaValues = {0, 0, 0}; // Change in encoder values 



/// @brief Updates the values of the sensors
void Odometer::updateSensors() {
  values.xValue = xDis.position(rotationUnits::deg) * kDegToInch;
  values.yValue = yDis.position(rotationUnits::deg) * kDegToInch; 
  values.heading = imu.heading(rotationUnits::deg) * kDegToRad;

  deltaValues.xValue = values.xValue - lastValues.xValue; // Change in X value since previous iteration 
  deltaValues.yValue = values.yValue - lastValues.yValue; // Change in Y value since previous iteration
  deltaValues.heading = values.heading - lastValues.heading; // Change in heading since previous iteration

  lastValues.xValue = values.xValue; // Sets the X value for the next iteration 
  lastValues.yValue = values.yValue; // Sets the Y value for the next iteration 
  lastValues.heading = values.heading; // Sets the heading for the next iteration
}


/// @brief Updates the robot position using the encoder values 
void Odometer::updatePosition() {
  position.xPos = values.xValue + (deltaValues.xValue * cos(values.heading)) - (deltaValues.yValue * sin(values.heading));
  position.yPos = values.yValue + (deltaValues.xValue * sin(values.heading)) + (deltaValues.yValue * cos(values.heading));
  position.heading = imu.heading() * kDegToRad;   
}


/// @brief Determines the X coordinate of the robot on the field
void Odometer::determinePositionX() {
  double leftDis = leftDistance.isObjectDetected() ? leftDistance.objectDistance(inches) : 0;
  double rightDis = rightDistance.isObjectDetected() ? rightDistance.objectDistance(inches) : 0;

  // Change depending on where the point (0, 0) is determined to be on the field  
  position.xPos = leftDis + kEncoderOffsetX;
  // position.xPos = rightDis + kEncoderOffsetX;

  // Prints both distance values to the console 
  printf("Left Distance: %f\nRight Distance: %f\n\n", (leftDis + kEncoderOffsetX), (rightDis + kEncoderOffsetX));
}


/// @brief Resets the sensor values 
void Odometer::reset() {
  xDis.resetRotation();
  yDis.resetRotation();

  values = {0, 0, 0};
  deltaValues = {0, 0, 0};

  position = {0, 0, 0};
  deltaPosition = {0, 0, 0};
}


/// @brief Sets the odometer to a new position 
/// @param newPosition The new position for the odometer
void Odometer::setPosition(Pose2D newPosition) {
  Odometer::reset();

  Odometer::position = newPosition;
}


/// @brief Calculates the angle between the robot and a point on the field 
/// @param point A point on the field 
/// @return The angle in radians between the current robot heading and a point on the field 
double Odometer::getDeltaAngle(Translation2D point) {
  double angle = (atan((Odometer::position.yPos - point.yPos) / (Odometer::position.xPos - point.xPos))) + M_TWOPI;
  angle = remainder(angle, M_TWOPI); //  - Odometer::position.heading;

  return angle;
}


/// @brief Thread for running the odometry system 
int Odometer::Odometry() {
  while (true) {
    Odometer::updateSensors();
    Odometer::updatePosition();

    this_thread::sleep_for(20); // Pauses the thread for 10ms to not overload the brain 
  }

  return 1;
}
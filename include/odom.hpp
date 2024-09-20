#ifndef ODOMETRY 
#define ODOMETRY 

#include "vex.h"

using namespace vex;

// The odometry system only works based on the initial point                           
// To be a funcitonal coordinate system, it requires a method of locating known points
// If possible, this method would be a sort of visual odometry, which would require a $200 GPS sensor             


/// @brief Position and heading of the robot 
/// @note Values are reported in inches for distance and radians for heading
struct Pose2D {
  double xPos, yPos, heading;
};


/// @brief A point on the field given in inches
/// @note Values are reported in inches 
struct Translation2D {
  double xPos, yPos;
};


/// @brief Values of the X-Y encoders and Inertial Sensor
/// @note All encoder values for odometry are reported in degrees
struct EncoderValues {
  double xValue, yValue, heading;
};



/// @brief Class for control of odometry measurement 
/// @note Odometry values are reported in inches for distance and radians for heading 
class Odometer {
  public:
    static Pose2D position;      // Current robot position 
    static Pose2D lastPosition;  // Previous robot position 
    static Pose2D deltaPosition; // Change in robot position

    static EncoderValues values;      // Current encoder values 
    static EncoderValues lastValues;  // Last encoder values
    static EncoderValues deltaValues; // Change in encoder values

    static void updateSensors();
    static void updatePosition();

    static void determinePositionX();

    static void reset();
    static void setPosition(Pose2D newPosition);

    static double getDeltaAngle(Translation2D point);

    static int Odometry(); // Thread for running odometry 
};

#endif // ODOMETRY 
#ifndef PID_SYSTEM
#define PID_SYSTEM 

#include "vex.h"
#include "constants.h"

#include <cmath>

/// @brief Class for use as a PID controller 
class PidSystem {
  public:
    PidSystem(double KP, double KI, double KD);
    PidSystem(double KP, double KI, double KD, double minValue, double maxValue);

    double calculate(double setpoint, double position);

    void setValueRange(double minVal, double maxVal);

    template <class T>
    static T constrain(T x, T min, T max);

    bool isFinished();
    void setFinishedValue(double value);

  private:
    const double kIntegrationLimit = 6; // Limits the integral term to only within 12 inches of the setpoint
    const double kConversionRate = kDegToInch; // Conversion rate from degrees to inches

    double finishedValue = 0.1; // Value used to determine whether or not the PID system in complete

    double kP, kI, kD;
    double error, errorRate, errorSum;
    double deltaT, lastError, lastTimestamp;

    double output, minOutput, maxOutput;

    timer time;
};

#endif // PID_SYSTEM
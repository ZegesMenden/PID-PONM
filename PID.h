#ifndef PID_h
#define PID_h

class PID
{
  public:
    float kP, kI, kD, iMax, setpoint, error, output;
    bool PONM = false;
    PID();
    PID(float p, i, d, setPoint) { kP = p; kI = i; kD = d; setpoint = setPoint; }; // initializer
    PID(float p, i, d, imax, setPoint) { kP = p; kI = i; kD = d; iMax = imax; setpoint = setPoint; }; // initializer with integral cap
    
    void setKp(float p) { kP = p; };
    void setKi(float i) { kI = i; };
    void setKd(float d) { kD = d; };
    void setImax(float imax) { iMax = imax; };
    void setPONM( bool ponm ) { PONM = ponm; };

    void setSetpoint(float setPoint) { setpoint = setpoint; };

    void update(float input, dt); // dt should be in microseconds

  private:
    float lastError, initInput, lastInput, P, I;
};

#endif
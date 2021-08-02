#include "PID.h"
#include "Arduino.h"

void PID::update(float input, float dt){
    float trueDT = dt / 1000000; // convert from microseconds to seconds
    error = setpoint - input;
    if PONM { P -= kP * ( input - lastInput ); } // if we are using PONM which is explained here: http://brettbeauregard.com/blog/2017/06/introducing-proportional-on-measurement/
    else { P = kP * error} // standard P
    float D = (error - lastError) / trueDT;
    I += error * kI * trueDT;
    output = P + I + D;
}
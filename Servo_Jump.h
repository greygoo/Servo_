/*
  Servo_Jump.h - Library for moving a servo jumpy to a position.
*/

#ifndef Servo_Jump_h
#define Servo_Jump_h

#include "Arduino.h"
#include <Servo.h>

class Servo_Jump
{
  public:
    Servo_Jump(int interval, int position, int jitter);
    void Enable();
    void Attach(int pin);
    void Detach();
    void Update();
  private:
    int updateInterval;
    int targetPosition;
    int servoJitter;
    int currentJitter;
    int nextPos;
    int increment;
    bool enabled;
    long lastUpdate;
};

#endif

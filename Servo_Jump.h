/*
  Servo_Jump.h - Library for moving a servo jumpy to a position.
*/

#ifndef Lala_h
#define Lala_h

#include <Arduino.h>
/* Servo.h still needs to be included in the main sketch as otherwise the
Arduin IDE nclude it while linking */
#include "../Servo/Servo.h"

class Servo_Jump
{
  public:
    Servo_Jump(int interval, int position, int jitter);
    void JumpTo(int pos);
    void Enable();
    void Attach(int pin);
    void Detach();
    void Update();
  private:
    Servo servo;
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

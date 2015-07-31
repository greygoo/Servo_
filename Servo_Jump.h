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
    Servo_Jump(int interval, int start, int position, int dur);
    void JumpTo(int pos);
    void Enable();
    void Attach(int pin);
    void Detach();
    bool enabled;
    void Update();
    int nextPos;
    int targetPosition;
  private:
    Servo servo;
    int duration;
    int updateInterval;
    int increment;
    long lastUpdate;
    long currentMillis;
    long prevMillis;
};

#endif

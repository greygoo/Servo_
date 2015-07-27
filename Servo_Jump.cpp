#include "Arduino.h"
#include "Servo_Jump.h"
#include <Servo.h>


Servo_Jump::Servo_Jump(int interval, int position, int jitter)
{
      updateInterval = interval;
      targetPosition = position;
      servoJitter = jitter;
      increment = 1;
      enabled = 0;
}

void Servo_Jump::Enable()
{
  enabled = 1;
  lastUpdate = millis();
}

void Servo_Jump::Attach(int pin)
{
  Servo servo;
  servo.attach(pin);
}

void Servo_Jump::Detach()
{
  servo.detach();
}

void Servo_Jump::Update()
{
  if( enabled && (millis() - lastUpdate() > updateInterval))
  {
    lastUpdate = millis();
    currentJitter = random(servoJitter);

    nextPos += increment + currentJitter - (currentJitter / 2);
    servo.write(nextPos);
    if((nextPos >= targetPosition - currentJitter) && (nextPos <= targetPosition + currentJitter))
    {
      servo.write(targetPosition);
    }
  }
}

#include <Arduino.h>
#include <Servo_Jump.h>
#include <../Servo/Servo.h>


Servo_Jump::Servo_Jump(int interval, int position, int jitter)
{
      Servo servo;
      updateInterval = interval;
      targetPosition = position;
      servoJitter = jitter;
      increment = 1;
      enabled = 0;
}

void Servo_Jump::JumpTo(int pos)
{
  targetPosition = pos;
}

void Servo_Jump::Enable()
{
  enabled = 1;
  lastUpdate = millis();
}

void Servo_Jump::Attach(int pin)
{
  servo.attach(pin);
}

void Servo_Jump::Detach()
{
  servo.detach();
}

void Servo_Jump::Update()
{
  if( enabled && (millis() - lastUpdate > updateInterval))
  {
    lastUpdate = millis();
    currentJitter = random(servoJitter);

    nextPos += increment + currentJitter - (currentJitter / 2);
    servo.write(nextPos);
    if((nextPos >= targetPosition - currentJitter) && (nextPos <= targetPosition + currentJitter))
    {
      // move servo to final position and stop moving
      servo.write(targetPosition);
      enabled = 0;
    }
  }
}

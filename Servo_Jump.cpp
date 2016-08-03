#include <Arduino.h>
#include <Servo_Jump.h>
#include <Servo.h>


Servo_Jump::Servo_Jump(int interval, int start, int position, int dur)
{
      Servo servo;
      updateInterval = interval;
      targetPosition = position;
      duration = dur;
      increment = 1;
      prevMillis = 0;
      enabled = 0;
      nextPos = start;
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
  currentMillis = millis();

  if ( enabled && \
       currentMillis - prevMillis >= duration && \
       nextPos >= targetPosition - 90 && \
       nextPos <= targetPosition + 90)
  {
    enabled = 0;
    prevMillis = currentMillis;
    servo.write(targetPosition);
  }

  if(enabled && (currentMillis - lastUpdate) > updateInterval)
  {
    lastUpdate = currentMillis;
    nextPos = random(180);
    servo.write(nextPos);
  }
}

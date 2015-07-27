#include "Arduino.h"
#include "Servo_Jump.h"

Servo_Jump::Servo_Jump(int interval, int position, int jitter)
{
      updateInterval = interval;
      targetPosition = position;
      servoJitter = jitter;
      increment = 1;
}

void Attach(int pin)
{
  servo.attach(pin);
}

void Detach()
{
  servo.detach();
}

void Update()
{
  if( enabled && (millis() - lastUpdate() > updateInterval))
  {
    lastUpdate = millis();
    jitter = random(servoJitter);

    pos += increment + jitter - (jitter / 2);
    servo.write(pos);
    if((pos >= targetPosition - jitter) && (pos <= targetPosition + jitter))
    {
      servo.write(target_Position);
    }
  }
}

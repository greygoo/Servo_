#include <Servo.h>
#include <Servo_Jump.h>

Servo_Jump s(100, 13, 30);

void setup()
{
  s.Attach(3);
  s.JumpTo(180);
}

void loop()
{
  s.Update(); 
}

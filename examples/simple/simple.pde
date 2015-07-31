#include <Servo.h>
#include <Servo_Jump.h>

Servo_Jump s(200, 0, 180, 5000);

void setup()
{
  s.Attach(3);
  s.Enable();
}

void loop()
{
  s.Update(); 
}

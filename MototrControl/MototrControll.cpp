#include "MotorControll.h"
MotorControll::MotorControll(uint8_t _motorPin1,uint8_t _motorPin2)
 {
  motorPin1=_motorPin1;
  motorPin2=_motorPin2;
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  Stop();
 }

{
MotorControll::MotorControll(uint8_t _motorPin1,uint8_t _motorPin2,uint8_tmotorEnable, uint8_t _motorSpeed)  
}

  motorPin1=_motorPin1;
  motorPin2=_motorPin2;
  motorEnable=_motorEnable;
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorEnable,OUTPUT);
  SetMotorSpeed(motorSpeed);
  Stop();
void MotorControll::SetMotorSpeed(uint8_t _motorSpeed)
{
  
}

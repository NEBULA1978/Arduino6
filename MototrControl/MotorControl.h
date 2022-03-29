#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROLL_H

class MotorControll
{
  public:
    MotorControll(uint8_t _motorPin1,uint8_t _motorPin2);//primer copnstructor
    MotorControll(uint8_t _motorPin1,uint8_t _motorPin2,uint8_t _motorEnable, uint8_t _motorSpeed);//2ºconstructor
    void SetMotorSpeed(uint8_t _motorSpeed);
    void MoveForward();
    void MoveBackward();
    void Stop();

  private:
    uint8_t motorSpeed=255;
    uint8_t motorPin1,motorPin2,motorEnable; 
};
#endif

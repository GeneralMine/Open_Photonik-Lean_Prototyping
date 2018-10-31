#include <Adafruit_MotorShield.h>

//configuration
#define MOTOR_R     1
#define MOTOR_L     4

//global objects
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Motor_R = AFMS.getMotor(MOTOR_R);
Adafruit_DCMotor *Motor_L = AFMS.getMotor(MOTOR_L);

void setup() {
    AFMS.begin();
    Motor_L->setSpeed(255);
    Motor_R->setSpeed(255);
}

void loop(){
  //rechts drehen
  Motor_L->run(FORWARD);
  Motor_R->run(BACKWARD);
  delay(1000);

  //vorwärts
  Motor_L->run(FORWARD);
  Motor_R->run(FORWARD);
  delay(1000);

  //rechts drehen
  Motor_L->run(FORWARD);
  Motor_R->run(BACKWARD);
  delay(1000);
}

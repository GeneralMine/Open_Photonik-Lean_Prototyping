#include <Adafruit_MotorShield.h>

//configuration
#define MOTOR_R     1
#define MOTOR_L     4

//global objects
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Motor_R = AFMS.getMotor(MOTOR_R);
Adafruit_DCMotor *Motor_L = AFMS.getMotor(MOTOR_L);

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  Motor_L->setSpeed(255);
  Motor_R->setSpeed(255);
}

void loop(){
  //serial-Steuerung
  serialCommands();
}

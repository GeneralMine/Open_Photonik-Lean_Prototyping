#include <Adafruit_MotorShield.h>

//configuration
#define MOTOR_R     1
#define MOTOR_L     4
#define EYE_L_PIN   A2
#define EYE_M_PIN   A0
#define EYE_R_PIN   A1 

//global objects
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Motor_R = AFMS.getMotor(MOTOR_R);
Adafruit_DCMotor *Motor_L = AFMS.getMotor(MOTOR_L);

//global variables
long time = 0;
int counter = 0;
int eyeCalibration[3];
bool driving = false;
const int threshold = 10;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  Motor_L->setSpeed(255);
  Motor_R->setSpeed(255);

  //augen kalibrieren
  calibrateEyes();
}

void loop(){
  if(millis() > time){
    switch(counter){
      case 0:
        turnRight(1000);
        break;
      case 1:
        turnLeft(1000);
        break;
      case 2:
        moveForward(1000);
        break;
      case 3:
        moveBackward(1000);
        break;
      case 4:
        stop(1000);
        break;
      default:
        counter = 0;
        break;
    }
  }
}

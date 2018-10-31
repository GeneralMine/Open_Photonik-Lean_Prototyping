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
long switchtime = 0;
int counter = 0;
bool driving = false;
int eyeCalibration[3];
long starttime = 0;
int chargedDirection[30];
long chargedWay[30];
int currentDirection = 0;
int chargeCounter = 0;
bool charging = false;

bool lightControl = 0;
bool manuellControl = 0;
bool powerMode = 0;
bool kurve = 0;
void setup() {
    Serial.begin(115200);
    AFMS.begin();
    Motor_L->setSpeed(128);
    Motor_R->setSpeed(128);
    calibrateEyes();
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    Serial.println("start");
}

void loop(){
  serialCommands();
  if(lightControl == 1 && manuellControl == 0){
    followLight();
  }
  if(lightControl == 0 && manuellControl == 1){
    serialCommands();
  }
  if(lightControl == 1 && manuellControl == 1){
    Serial.println("both modes active!");
  }  
  if(lightControl == 0 && manuellControl == 0){
    Serial.println("no mod active!");
  }

}

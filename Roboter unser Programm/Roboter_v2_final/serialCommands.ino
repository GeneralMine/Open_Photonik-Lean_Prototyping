void serialCommands(){
 char input;
 if(Serial.available() > 0){
    input = (char)Serial.read();
 }

 switch(input){
    case 'd':
    kurve = 0;
      if(manuellControl==1 && lightControl == 0){
      turnRight();
      }
      break;
    case 'a':
    kurve = 0;
    if(manuellControl==1 && lightControl == 0){
      turnLeft();
      }
      break;
    case 'w':
    kurve = 0;
    if(manuellControl==1 && lightControl == 0){
      moveForward();
      }
      break;
    case 's':
    kurve = 0;
    if(manuellControl==1 && lightControl == 0){
      moveBackward();
      }
      break;
    case 32:
    if(manuellControl==1 && lightControl == 0){
      stop();
      }
      break;
    case 'l':
    Serial.println("lichtgesteuerter Betrieb");
      lightControl = 1;
      stop();
      manuellControl = 0;
      break;
    case 'm':
    Serial.println("manueller Betrieb");
      manuellControl = 1;
      lightControl = 0;
      break;
    case 'p':
    if(powerMode == 0){
      powerMode = 1;
      if(kurve==0){
      Motor_L->setSpeed(255);
    Motor_R->setSpeed(255);
      }
      else{
        Motor_L->setSpeed(128);
    Motor_R->setSpeed(128);
      }
    }
    else{
      powerMode = 0;
      if(kurve==0){
      Motor_L->setSpeed(128);
    Motor_R->setSpeed(128);
      }
    }
    break;
    case 'q':
    kurve = 1;
      Motor_L->setSpeed(80);
      Motor_R->setSpeed(255);
      Motor_L->run(FORWARD);
      Motor_R->run(FORWARD);
    break;
    case 'e':
    kurve = 1;
      Motor_L->setSpeed(255);
      Motor_R->setSpeed(80);
      Motor_L->run(FORWARD);
      Motor_R->run(FORWARD);
    break;
  }
}

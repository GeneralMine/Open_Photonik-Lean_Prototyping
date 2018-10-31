//cooool
void moveForward(){
  
//VORWÄRTS
Serial.println("Vorwärts");
Motor_R->run(FORWARD);
Motor_L->run(FORWARD);
}

void moveLeft(){
//Links
Serial.println("links");
Motor_R->run(FORWARD);
Motor_L->run(BACKWARD);
}
void moveRight(){
//RECHTS
Serial.println("rechts");
Motor_R->run(BACKWARD);
Motor_L->run(FORWARD);
}

void stop(){
  Serial.println("STAAAHP");
  Motor_R->run(RELEASE);
  Motor_L->run(RELEASE);
}
void moveBackward(){

//Rückwärts
Serial.println("rückwärts");
Motor_R->run(BACKWARD);
Motor_L->run(BACKWARD);
}

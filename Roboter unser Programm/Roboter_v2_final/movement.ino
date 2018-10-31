void moveForward(long duration){
  Motor_L->setSpeed(128);
    Motor_R->setSpeed(128);
  Serial.println("moved forward");
  Motor_L->run(FORWARD);
  Motor_R->run(FORWARD);
  switchtime = millis()+duration;
  counter++;
  driving = true;
}

void moveForward(){
  moveForward(0);
}

void moveBackward(long duration){
  Serial.println("moved backward");
  Motor_L->run(BACKWARD);
  Motor_R->run(BACKWARD);
  switchtime = millis()+duration;
  counter++;
  driving = true;
}

void moveBackward(){
  Motor_L->setSpeed(128);
    Motor_R->setSpeed(128);
  moveBackward(0);
}

void turnRight(long duration){
  Motor_L->setSpeed(128);
    Motor_R->setSpeed(128);
  Serial.println("turned right");
  Motor_L->run(FORWARD);
  Motor_R->run(BACKWARD);
  switchtime = millis()+duration;
  counter++;
  driving = true;
}

void turnRight(){
  turnRight(0);
}

void turnLeft(long duration){
  Serial.println("turned left");
  Motor_L->run(BACKWARD);
  Motor_R->run(FORWARD);
  switchtime = millis()+duration;
  counter++;
  driving = true;
}

void turnLeft(){
  Motor_L->setSpeed(128);
    Motor_R->setSpeed(128);
  turnLeft(0);
}

void stop(long duration){
  Serial.println("stopped");
  Motor_L->run(RELEASE);
  Motor_R->run(RELEASE);
  switchtime = millis()+duration;
  counter++;
  driving = false;;
}

void stop(){
  stop(0);
}

void stopForever(){
  Serial.println("stopped forever");
  Motor_L->run(RELEASE);
  Motor_R->run(RELEASE);
  driving = false;
  while(true){}
}

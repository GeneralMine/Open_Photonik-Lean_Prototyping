void moveForward(){
  Serial.println("vorwärts");
  Motor_L->run(FORWARD);
  Motor_R->run(FORWARD);
}

void moveBackward(){
  Serial.println("rückwärts");
  Motor_L->run(BACKWARD);
  Motor_R->run(BACKWARD);
}

void turnRight(){
  Serial.println("rechts");
  Motor_L->run(FORWARD);
  Motor_R->run(BACKWARD);
}

void turnLeft(){
  Serial.println("links");
  Motor_L->run(BACKWARD);
  Motor_R->run(FORWARD);
}

void stop(){
  Serial.println("stop");
  Motor_L->run(RELEASE);
  Motor_R->run(RELEASE);
}

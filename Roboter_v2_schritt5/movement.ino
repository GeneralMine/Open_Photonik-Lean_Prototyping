void moveForward(long duration){
  Serial.print("vorwärts für ");
  Serial.print(duration);
  Serial.println(" ms");
  Motor_L->run(FORWARD);
  Motor_R->run(FORWARD);
  addTime(duration);
}

void moveBackward(long duration){
  Serial.print("rückwärts für ");
  Serial.print(duration);
  Serial.println(" ms");
  Motor_L->run(BACKWARD);
  Motor_R->run(BACKWARD);
  addTime(duration);
}

void turnRight(long duration){
  Serial.print("nach rechts drehen für ");
  Serial.print(duration);
  Serial.println(" ms");
  Motor_L->run(FORWARD);
  Motor_R->run(BACKWARD);
  addTime(duration);
}

void turnLeft(long duration){
  Serial.print("nach links drehen für ");
  Serial.print(duration);
  Serial.println(" ms");
  Motor_L->run(BACKWARD);
  Motor_R->run(FORWARD);
  addTime(duration);
}

void stop(long duration){
  Serial.print("anhalten für ");
  Serial.print(duration);
  Serial.println(" ms");
  Motor_L->run(RELEASE);
  Motor_R->run(RELEASE);
  addTime(duration);
  driving = false;
}

void addTime(long duration){
  time = millis()+duration;
  counter++;
  driving = true;
}

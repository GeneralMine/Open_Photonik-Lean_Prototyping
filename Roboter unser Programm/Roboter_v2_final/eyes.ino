const int threshold = 10;

void calibrateEyes(){
  eyeCalibration[0] = analogRead(EYE_L_PIN)-5;  
  eyeCalibration[1] = analogRead(EYE_M_PIN)-5;  
  eyeCalibration[2] = analogRead(EYE_R_PIN)-5; 
}

void followLight(){
  int rawValue[3];
  float weightedValue[3];
  rawValue[0] = analogRead(EYE_L_PIN)-eyeCalibration[0];  
  rawValue[1] = analogRead(EYE_M_PIN)-eyeCalibration[1];  
  rawValue[2] = analogRead(EYE_R_PIN)-eyeCalibration[2]; 

  if(rawValue[0] < 0){
    rawValue[0] = 0;
  }
  if(rawValue[1] < 0){
    rawValue[1] = 0;
  }
  if(rawValue[2] < 0){
    rawValue[2] = 0;
  }

  float mean = (rawValue[0]+rawValue[1]+rawValue[2])/3.0;

  //if(mean < 1.f){
  //  mean = 1.f;
  //}
  
  weightedValue[0] = rawValue[0]/mean;  
  weightedValue[1] = rawValue[1]/mean;
  weightedValue[2] = rawValue[2]/mean;

  int maxDifference = max(max(rawValue[0], rawValue[1]), rawValue[2])-min(min(rawValue[0], rawValue[1]), rawValue[2]);

  Serial.print("Lr=");
  Serial.print(rawValue[0]);
  Serial.print(",\tMr=");
  Serial.print(rawValue[1]);
  Serial.print(",\tRr=");
  Serial.print(rawValue[2]);
  Serial.print(",\tLw=");
  Serial.print(weightedValue[0]);
  Serial.print(",\tMw=");
  Serial.print(weightedValue[1]);
  Serial.print(",\tRw=");
  Serial.print(weightedValue[2]);
  Serial.print(",\tmean=");
  Serial.print(mean);
  Serial.print(",\tdiff=");
  Serial.println(maxDifference);

  if(weightedValue[0] > weightedValue[1] && weightedValue[0] > weightedValue[2] && maxDifference > threshold){
    turnLeft();
  }else if(weightedValue[1] > weightedValue[0] && weightedValue[1] > weightedValue[2] && maxDifference > threshold){
    moveForward();
  }else if(weightedValue[2] > weightedValue[0] && weightedValue[2] > weightedValue[1]&& maxDifference > threshold){
    turnRight();
  }else{
    if(driving){
      stop();
      calibrateEyes();
    }
  }

  
}

const float threshold2[3] = {1.5f, 1.5f, 1.5f};
const int delayValue[3] = {0, 0, 0};

void chargeAndDrive(){
  int rawValue[3];
  float weightedValue[3];
  rawValue[0] = analogRead(EYE_L_PIN);  
  rawValue[1] = analogRead(EYE_M_PIN);  
  rawValue[2] = analogRead(EYE_R_PIN); 

  float mean = (rawValue[0]+rawValue[1]+rawValue[2])/3.0;

  weightedValue[0] = rawValue[0]/mean;  
  weightedValue[1] = rawValue[1]/mean;
  weightedValue[2] = rawValue[2]/mean;

  /*Serial.print("Lr=");
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
  Serial.println(mean);*/

  if(weightedValue[0] > threshold2[0]){
    if(!charging && millis() > starttime+delayValue[0]){
      Serial.println("charging left");
      currentDirection = 0;
      charging = true;
      starttime = millis();
    }
  }else if(weightedValue[1] > threshold2[1]){
    if(!charging && millis() > starttime+delayValue[1]){
      Serial.println("charging center");
      currentDirection = 1;
      charging = true;
      starttime = millis();
    }
  }else if(weightedValue[2] > threshold2[2]){
    if(!charging && millis() > starttime+delayValue[2]){
      Serial.println("charging right");
      currentDirection = 2;
      charging = true;
      starttime = millis();
    }
  }else{
    if(charging){
      if(millis()-starttime > 200){
        chargedWay[chargeCounter] = millis()-starttime-delayValue[currentDirection];
        chargedDirection[chargeCounter] = currentDirection;
        Serial.println(currentDirection);
        Serial.println(chargedWay[chargeCounter]);
        chargeCounter++; 
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
      }
      starttime = millis()+200;
      charging = false;
    }
  }

  if(millis() > 5000+starttime && chargeCounter > 0){
    for(int i = 0; i < chargeCounter; i++){
      if(chargedDirection[i] == 0){
        turnLeft();
      }else if(chargedDirection[i] == 1){
        moveForward();
      }else{
        turnRight();
      }
      delay(chargedWay[i]);
    }
    stop();
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    chargeCounter = 0;
  }

}

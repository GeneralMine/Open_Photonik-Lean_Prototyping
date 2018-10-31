void calibrateEyes(){
  eyeCalibration[0] = analogRead(EYE_L_PIN);  
  eyeCalibration[1] = analogRead(EYE_M_PIN);  
  eyeCalibration[2] = analogRead(EYE_R_PIN); 
}

void followLight(){
  int rawValue[3];
  float weightedValue[3];
  float mean;
  int maxDifference;

  //werte lesen und kalibrierung beachten
  rawValue[0] = analogRead(EYE_L_PIN)-eyeCalibration[0];  
  rawValue[1] = analogRead(EYE_M_PIN)-eyeCalibration[1];  
  rawValue[2] = analogRead(EYE_R_PIN)-eyeCalibration[2]; 

  //durchschnitt bilden
  mean = (rawValue[0]+rawValue[1]+rawValue[2])/3.0;

  //werte gewichten
  weightedValue[0] = rawValue[0]/mean;  
  weightedValue[1] = rawValue[1]/mean;
  weightedValue[2] = rawValue[2]/mean;

  //maximale differenz zwischen den 3 Werten berechnen
  maxDifference = max(max(rawValue[0], rawValue[1]), rawValue[2])-min(min(rawValue[0], rawValue[1]), rawValue[2]);

  //Debug-Ausgabe
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

  //Fallunterscheidung: Vergleich der 3 Werte
  if(weightedValue[0] > weightedValue[1] && weightedValue[0] > weightedValue[2] && maxDifference > threshold){
    //linker Wert an größten und maximale Differenz sehr groß
    turnLeft(0);
  }else if(weightedValue[1] > weightedValue[0] && weightedValue[1] > weightedValue[2] && maxDifference > threshold){
    //mittlerer Wert an größten und maximale Differenz sehr groß
    moveForward(0);
  }else if(weightedValue[2] > weightedValue[0] && weightedValue[2] > weightedValue[1]&& maxDifference > threshold){
    //rechter Wert an größten und maximale Differenz sehr groß
    turnRight(0);
  }else{
    //maximale Differenz klein
    if(driving){
      //anhalten falls gefahren wird
      stop(0);

      //neu kalibrieren
      calibrateEyes();
    }
  }

  
}

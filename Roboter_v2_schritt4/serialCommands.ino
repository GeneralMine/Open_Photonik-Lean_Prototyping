void serialCommands(){
  if(Serial.available() < 1){
    return;
  }
 
  char input = (char)Serial.read();

  switch(input){
    case 'r':
      turnRight(1000);
      break;
    case 'l':
      turnLeft(1000);
      break;
    case 'f':
      moveForward(1000);
      break;
    case 'b':
      moveBackward(1000);
      break;
    case 's':
      stop(1000);
      break;
    default:
    Serial.println("falscher Befehl");
      break;
   }
}

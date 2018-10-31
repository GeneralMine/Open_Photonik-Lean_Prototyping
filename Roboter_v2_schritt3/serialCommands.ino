void serialCommands(){
  if(Serial.available() < 1){
    return;
  }
 
  char input = (char)Serial.read();

  switch(input){
    case 'r':
      turnRight();
      break;
    case 'l':
      turnLeft();
      break;
    case 'f':
      moveForward();
      break;
    case 'b':
      moveBackward();
      break;
    case 's':
      stop();
      break;
    default:
    Serial.println("falscher Befehl");
      break;
   }
}

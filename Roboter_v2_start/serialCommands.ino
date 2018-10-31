void serialCommands(){
 if(Serial.available() < 1){
 return;
  } 

 char input = (char)Serial.read();

switch(input){
  case'd':
  moveRight();
  break;
  case'w':
  moveForward();
  break;
  case'a':
  moveLeft();
  break;
  case's':
  moveBackward();
  break;
  case 32:
  stop();
  break;
}
}



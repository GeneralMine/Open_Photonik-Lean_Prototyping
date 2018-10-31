void sequence(){
  if(switchtime < millis()){
    switch(counter){
      case 0:
        turnLeft(5000);
        break;
      case 1:
        moveBackward(5000);
        break;
      case 2:
        stopForever();
        break;
      default:
        counter = 0;
        break;
    } 
  }
}

void sequence2(){
  turnLeft();
  delay(1000);
  moveBackward();
  delay(1000);
  stopForever();
}

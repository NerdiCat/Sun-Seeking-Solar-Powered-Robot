void Move1(){
 if (DataResult==1) //if left is brighter turn left and go forward
 {
   Go();
   turn_left2();
   Go();
   forward();
   fourth2lastmove=third2lastmove;
   third2lastmove=second2lastmove;
   second2lastmove=lastmove;
   lastmove=3;
 }
 if (DataResult==2) //if right is brighter turn right and go forward
 {
  Go();
  turn_right2();
  Go();
  forward();
  fourth2lastmove=third2lastmove;
  third2lastmove=second2lastmove;
  second2lastmove=lastmove;
  lastmove=4;
 }
 if (DataResult==3) //if front is brighter go forward
 {
  Go();
  forward();
  fourth2lastmove=third2lastmove;
  third2lastmove=second2lastmove;
  second2lastmove=lastmove;
  lastmove=1;
 }
 if (DataResult==4) //if back is brighter go backwards
 {
  Go();
  backward();
  fourth2lastmove=third2lastmove;
  third2lastmove=second2lastmove;
  second2lastmove=lastmove;
  lastmove=2;
 }
 delay(1000);
}

void Move2(){
  if (DataResult2==1){  //if new data is darker than old then move back
    Go();
    backward();
    fourth2lastmove=third2lastmove;
    third2lastmove=second2lastmove;
    second2lastmove=lastmove;
    lastmove=2;
    
  }
  if (DataResult2==2){  //if new data is same as old then charge
    Charge();
  }
}
void Charge(){
lastmove=0; //1=forward 2=back 3=left 4=right
second2lastmove=0; //1=forward 2=back 3=left 4=right
third2lastmove=0; //1=forward 2=back 3=left 4=right
fourth2lastmove=0; //1=forward 2=back 3=left 4=right
Serial.println("charging");
delay(10000);
}
void shouldstop(){
if ((lastmove==2) && (second2lastmove==1) && (third2lastmove==2) && (fourth2lastmove==1)){ //if robot has gone forward and backward repeatedly stop and charge
      Charge();
    }
if ((lastmove==1) && (second2lastmove==2) && (third2lastmove==1) && (fourth2lastmove==2)){ //if robot has gone forward and backward repeatedly stop and charge
      Charge();
    }
}



void single_test(){
  for (int i = 1; i <= 4; i++) {
   Motor(i,'f');
   delay(1000);
   Motor(i,'b');
   delay(1000);
    Motor(i,'s');
   delay(1000);
  }
}
void toggleForward(){
  /*for (int i = 1; i <= 4; i++) {
    Motor(i,'f');
 }*/
 Motor(1,'f');
 Motor(3,'f');
 delay(100);
 Motor(2, 'f');
 Motor(4, 'f');
}
void toggleBackward(){
 delay(200);
 Motor(1,'b');
 Motor(3,'b');
 delay(50);
 Motor(2, 'b');
 Motor(4, 'b');
 
}
void Stop(){
 for (int i = 1; i <= 4; i++) {
    Motor(i,'s');
 }
}
void Forward(int t){
  /*for (int i = 1; i <= 4; i++) {
    Motor(i,'f');
 }*/
 toggleForward();
 delay(t);
 Stop();
}

void Left(int t){
  Motor(1,'f');
  Motor(2,'f');
  Motor(3,'b');
  Motor(4,'b');
  delay(t);
  Stop();
}

void Right(int t){
  Motor(1,'b');
  Motor(2,'b');
  Motor(3,'f');
  Motor(4,'f');
  delay(t);
  Stop();
}

void Back(int t){
 toggleBackward();
 delay(t);
 Stop();
}

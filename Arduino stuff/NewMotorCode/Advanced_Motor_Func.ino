void test(){
  single_test();
  Forward(1000);
  Back(1000);
  Left(1000);
  Right(1000);
}
int S=0;
void dontFall(){
  int currentRead=analogRead(cliff);
  
  delay(25);
  int lastRead=currentRead;
  currentRead=analogRead(cliff);
  if (abs(lastRead-currentRead)>100 && S==0){
    Stop();
    Serial.println(analogRead(cliff));
    Serial.println("stop");
    S=1;
    
  } 
  if (S==1){
    Back(500);
    S=2;    
  }
  if (S==0){
    Serial.println(analogRead(cliff));
  }
}

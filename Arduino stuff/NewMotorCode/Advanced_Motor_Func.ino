void test(){  //runs a serise of motor comands to make sure the motors are working and calabrated
  single_test();
  Forward(1000);
  Back(1000);
  Left(1000);
  Right(1000);
}
int S=0;  //variable used to trigger stop command once
void dontFall(){  //code to check if going over a clif and correct
  int currentRead=analogRead(cliff);
  delay(25);
  int lastRead=currentRead;
  currentRead=analogRead(cliff);
  if (abs(lastRead-currentRead)>100 && S==0){ //check the last two readings and if there is a dramatic change stop going forward and initiate anti-falling mechanisms
    Stop();
    Serial.println(analogRead(cliff));
    Serial.println("stop");
    S=1;
  } 
  if (S==1){//the antifalling mechanism is currently just going backwards for half a seccond
    Back(500);
    S=2;    
  }
  if (S==0){
    Serial.println(analogRead(cliff));
  }
}

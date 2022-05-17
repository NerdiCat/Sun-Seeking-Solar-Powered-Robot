void test(){  //runs a serise of motor comands to make sure the motors are working and calabrated
  Serial.println("testing");
  single_test();
  Right(1000);
}
int S=0;  //variable used to trigger stop command once
void dontDie(){  //code to check if going over a clif and correct
    if (gonnaFall()||gonnaCrash()){
    Stop();
    Back(350);
    Serial.println("stop");
  } 
}

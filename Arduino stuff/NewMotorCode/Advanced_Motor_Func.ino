void test(){
  single_test();
  Forward(1000);
  Back(1000);
  Left(1000);
  Right(1000);
}

void dontFall(){
  if (analogRead(cliff)>700){
    Stop();
  }
}

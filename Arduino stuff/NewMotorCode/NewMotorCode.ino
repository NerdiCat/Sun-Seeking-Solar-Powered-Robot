  int m1p=13; //motor 1 positive
  int m1n=12; //motor 1 negative
  int m2p=11;
  int m2n=10;
  int m3p=9;
  int m3n=8;
  int m4p=7;
  int m4n=6;
  int cliff=A0;
  #include <Wire.h>
  #include "Adafruit_VL6180X.h"

  Adafruit_VL6180X vl = Adafruit_VL6180X();
void setup() {
  // put your setup code here, to run once:
  pinMode(m1p,OUTPUT);
  pinMode(m1n,OUTPUT);
  pinMode(m2p,OUTPUT);
  pinMode(m2n,OUTPUT);
  pinMode(m3p,OUTPUT);
  pinMode(m3n,OUTPUT);
  pinMode(m4p,OUTPUT);
  pinMode(m4n,OUTPUT);
  Serial.begin(115200);
  //test();
  //Left(1000);
  //toggleForward();
  delay(200);
  
  // wait for serial port to open on native usb devices
  while (!Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL6180x test!");
  if (! vl.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
  Serial.println("Sensor found!");
}

void loop() {
  //Serial.println(analogRead(cliff));
 // Serial.println("test");
  // put your main code here, to run repeatedly:
 checkCliff();
 //dontFall();
}

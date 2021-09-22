#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *Motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *Motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *Motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *Motor4 = AFMS.getMotor(4);
int sensorPin1 =A5;   //left  Light Detecting Resistor
int sensorValue1 =0;  //old left data
int sensorPin2 =A4;   //right   "
int sensorValue2 =0;  //old right data
int sensorPin3 =A0;   //top 1*   "
int sensorValue3 =0;  //old top 1* data
int sensorPin4 =A1;   //right*    "
int sensorValue4 =0;  //old right data*
int sensorPin5 =A3;   //front*   "
int sensorValue5 =0;  //old front* data
int sensorPin6 =A2;   //Top 2*   "
int sensorValue6 =0;  //old top 2 data*
int DataResult =0;    //What derection is brightest 1=left 2=right 3=front 4=back
int DataResult2 =0;   //If new spot is brighter, darker, or same 1=Darker 2=Same 3=brighter
int Top1 =0;          //new top 1 data
int Top2 =0;          //new top 2 data
int TopAverage1 =0;   //average of old data
int TopAverage2 =0;   //aveerage of new data
int offset1=577;
int offset2=577;
int offset3=0;
int offset4=0;
int offset5=0;
int offset6=0;
int max1=1015;
int max2=1015;
int max3=1015;
int max4=1010;
int max5=1010;
int max6=1010;
int lastmove=0; //1=forward 2=back 3=left 4=right
int second2lastmove=0; //1=forward 2=back 3=left 4=right
int third2lastmove=0; //1=forward 2=back 3=left 4=right
int fourth2lastmove=0; //1=forward 2=back 3=left 4=right
int diff;
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  //Serial.print("HI");
  AFMS.begin();
  Go();
  Dance();
 
}

void loop() {
  /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    
  Go();
  forward(); 
  //Serial.print("forward");
  Go();
  backward();
  //Serial.print("backward");*/

  //Speed_Trial();
  /*
  Take_Data();
  Check_Data();
  Move1();
  Check_Top();
  Move2();
  shouldstop();
  */
  Serial.println("s1:");
  Serial.println(sensorValue1);
  Serial.println("s2:");
  Serial.println(sensorValue2);
  Serial.println("s3:");
  Serial.println(sensorValue3);
  Serial.println("s4:");
  Serial.println(sensorValue4);
  Serial.println("s5:");
  Serial.println(sensorValue5);
  Serial.println("s6:");
  Serial.println(sensorValue6);
  Serial.println("last move");
  Serial.println(lastmove);
  Serial.println("second to last move");
  Serial.println(second2lastmove);
  Serial.println("third to last move");
  Serial.println(third2lastmove);
  Serial.println("fourth to last move");
  Serial.println(fourth2lastmove); 
  Serial.println("diff");
  Serial.println(diff);
  Serial.println("top1");
  Serial.println(Top1);
  Serial.println("top2");
  Serial.println(Top2);
  Serial.println("topaverage1");
  Serial.println(TopAverage1);
  Serial.print("topaverage2: ");
  Serial.println(TopAverage2);
  delay(1000);
  
}

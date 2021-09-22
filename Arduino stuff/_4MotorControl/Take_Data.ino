void Take_Data() {
  sensorValue1 = map(analogRead(sensorPin1),offset1,max1,0,1023);
  sensorValue2 = map(analogRead(sensorPin2),offset2,max2,0,1023);
  sensorValue3 = map(analogRead(sensorPin3),offset3,max3,0,1023);
  sensorValue4 = map(analogRead(sensorPin4),offset4,max4,0,1023);
  sensorValue5 = map(analogRead(sensorPin5),offset5,max5,0,1023);
  sensorValue6 = map(analogRead(sensorPin6),offset6,max6,0,1023);
}


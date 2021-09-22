void Check_Data() {
  if ((sensorValue1 > sensorValue2) && (sensorValue1 > sensorValue5) && (sensorValue1 > sensorValue4))  //if left is brightest
  {
    DataResult = 1;   //if left is brighter turn left and go forward
  }
  if ((sensorValue4 > sensorValue1) && (sensorValue4 > sensorValue2) && (sensorValue4 > sensorValue5))  //if right is brightest
  {
    DataResult = 2;  //if right is brighter turn right and go forward
  }
  if ((sensorValue5 > sensorValue1) && (sensorValue5 > sensorValue2) && (sensorValue5 > sensorValue4))  //if front is brightest
  {
    DataResult = 3;  //if front is brighter go forward
  }
  if ((sensorValue2 > sensorValue1) && (sensorValue2 > sensorValue4) && (sensorValue2 > sensorValue5)) //if back is brightest
  {
    DataResult = 4;  //if back is brighter go backwards
  }
}

void Check_Top() {
  TopAverage1 = (sensorValue3 + sensorValue6) / 2;
  // int sensorValue3;
  // int sensorValue6;
  Take_Data();
  // Top1 = sensorValue3;
  // Top2 = sensorValue6;
  TopAverage2 = (sensorValue3 + sensorValue6) / 2;
  diff = abs(TopAverage1 - TopAverage2);
  if (diff <= 50) {              //if the difference between the old reading and new is less/equal to 100
    DataResult2 = 2;
  }
  else if (TopAverage1 > TopAverage2) // else if old readings are brighter than new
  {
    DataResult2 = 3;
  }
  else                                // if non of the ubove than new readings must be brighter than old
  {
    DataResult2 = 1;
  }
}






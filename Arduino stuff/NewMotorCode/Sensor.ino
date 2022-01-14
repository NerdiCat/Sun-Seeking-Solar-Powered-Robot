void VL6180XSetUp(){  //copied code from vl6180x library and modified for 2 sensors instead of 3
    // address we will assign if dual sensor is present
  #define LOX1_ADDRESS 0x30
  #define LOX2_ADDRESS 0x31
  // set the pins to shutdown
  #define SHT_LOX1 7
  #define SHT_LOX2 6
  
  // objects for the VL6180X
  Adafruit_VL6180X cliff = Adafruit_VL6180X();
  Adafruit_VL6180X front = Adafruit_VL6180X();
  
  // Setup mode for doing reads
  typedef enum {RUN_MODE_DEFAULT, RUN_MODE_TIMED, RUN_MODE_ASYNC, RUN_MODE_GPIO, RUN_MODE_CONT} runmode_t;
  
  runmode_t run_mode = RUN_MODE_DEFAULT;
  uint8_t show_command_list = 1;
  
  //==========================================================================
  // Define some globals used in the continuous range mode
  // Note: going to start table drive this part, may back up and do the rest later
  Adafruit_VL6180X *sensors[] = {&lox1, &lox2};
  const uint8_t COUNT_SENSORS = sizeof(sensors) / sizeof(sensors[0]);
  const int sensor_gpios[COUNT_SENSORS] = {GPIO_LOX1, GPIO_LOX2, GPIO_LOX3}; // if any are < 0 will poll instead
  
  uint8_t         sensor_ranges[COUNT_SENSORS];
  uint8_t         sensor_status[COUNT_SENSORS];
  // Could do with uint8_t for 8 sensors, but just in case...
  const uint16_t  ALL_SENSORS_PENDING = ((1 << COUNT_SENSORS) - 1);
  uint16_t        sensors_pending = ALL_SENSORS_PENDING;
  uint32_t        sensor_last_cycle_time;
  /*
      Reset all sensors by setting all of their XSHUT pins low for delay(10), then set all XSHUT high to bring out of reset
      Keep sensor #1 awake by keeping XSHUT pin high
      Put all other sensors into shutdown by pulling XSHUT pins low
      Initialize sensor #1 with lox.begin(new_i2c_address) Pick any number but 0x29 and it must be under 0x7F. Going with 0x30 to 0x3F is probably OK.
      Keep sensor #1 awake, and now bring sensor #2 out of reset by setting its XSHUT pin high.
      Initialize sensor #2 with lox.begin(new_i2c_address) Pick any number but 0x29 and whatever you set the first sensor to
  */
  void setID() {
    
    // all reset
    digitalWrite(SHT_LOX1, LOW);
    digitalWrite(SHT_LOX2, LOW);
    delay(10);
    
     // all unreset
    digitalWrite(SHT_LOX1, HIGH);
    digitalWrite(SHT_LOX2, HIGH);
    delay(10);
    
    // activating LOX1 and reseting LOX2
    digitalWrite(SHT_LOX1, HIGH);
    digitalWrite(SHT_LOX2, LOW);
    
    // initing LOX1
    if (!lox1.begin()) {
      Serial.println(F("Failed to boot first VL6180X"));
      while (1);
    }
    lox1.setAddress(LOX1_ADDRESS);
    delay(10);
    
     // activating LOX2
    digitalWrite(SHT_LOX2, HIGH);
    delay(10);

    //initing LOX2
    if (!lox2.begin()) {
      Serial.println(F("Failed to boot second VL6180X"));
      while (1);
    }
    lox2.setAddress(LOX2_ADDRESS);
  }
}
void checkCliff(){
  float lux = vl.readLux(VL6180X_ALS_GAIN_5);

  Serial.print("Lux: "); Serial.println(lux);
  
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();

  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Range: "); Serial.println(range);
  }

  // Some error occurred, print it out!
  
  if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
    Serial.println("System error");
  }
  else if (status == VL6180X_ERROR_ECEFAIL) {
    Serial.println("ECE failure");
  }
  else if (status == VL6180X_ERROR_NOCONVERGE) {
    Serial.println("No convergence");
  }
  else if (status == VL6180X_ERROR_RANGEIGNORE) {
    Serial.println("Ignoring range");
  }
  else if (status == VL6180X_ERROR_SNR) {
    Serial.println("Signal/Noise error");
  }
  else if (status == VL6180X_ERROR_RAWUFLOW) {
    Serial.println("Raw reading underflow");
  }
  else if (status == VL6180X_ERROR_RAWOFLOW) {
    Serial.println("Raw reading overflow");
  }
  else if (status == VL6180X_ERROR_RANGEUFLOW) {
    Serial.println("Range reading underflow");
  }
  else if (status == VL6180X_ERROR_RANGEOFLOW) {
    Serial.println("Range reading overflow");
  }
  delay(50);
}
bool gonnaFall(){
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();

  if (status == VL6180X_ERROR_NONE && range<100) {
    return false;
  }
  else return true;
  delay(50);
}

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


//copied code from vl6180x library and modified for 2 sensors instead of 3:

//////////////////////////////////////////////////////////////////////////////////////
// address we will assign if dual sensor is present
#define LOX1_ADDRESS 0x30
#define LOX2_ADDRESS 0x31

// set the pins to shutdown
#define SHT_LOX1 3  //wall sensor
#define SHT_LOX2 2  //cliff sensor

// Optional define GPIO pins to check to see if complete
#define GPIO_LOX1 4
#define GPIO_LOX2 3

#define TIMING_PIN 13

// objects for the VL6180X
Adafruit_VL6180X lox1 = Adafruit_VL6180X();// wall sensor
Adafruit_VL6180X lox2 = Adafruit_VL6180X();// cliff sensor

// Setup mode for doing reads
typedef enum {RUN_MODE_DEFAULT, RUN_MODE_TIMED, RUN_MODE_ASYNC, RUN_MODE_GPIO, RUN_MODE_CONT} runmode_t;

runmode_t run_mode = RUN_MODE_DEFAULT;
uint8_t show_command_list = 1;

//==========================================================================
// Define some globals used in the continuous range mode
// Note: going to start table drive this part, may back up and do the rest later
Adafruit_VL6180X *sensors[] = {&lox1, &lox2,/*&lox3*/};
const uint8_t COUNT_SENSORS = sizeof(sensors) / sizeof(sensors[0]); 
const int sensor_gpios[COUNT_SENSORS] = {GPIO_LOX1, GPIO_LOX2, /*GPIO_LOX3*/}; // if any are < 0 will poll instead

uint8_t         sensor_ranges[COUNT_SENSORS];
uint8_t         sensor_status[COUNT_SENSORS];
// Could do with uint8_t for 8 sensors, but just in case...
const uint16_t  ALL_SENSORS_PENDING = ((1 << COUNT_SENSORS) - 1);
uint16_t        sensors_pending = ALL_SENSORS_PENDING;
uint32_t        sensor_last_cycle_time;
/////////////////////////////////////////////////////////////////////////////////
  
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
  delay(200);
  sensorSetup();
  toggleForward();
}
 
void loop() {
 dontDie();
}

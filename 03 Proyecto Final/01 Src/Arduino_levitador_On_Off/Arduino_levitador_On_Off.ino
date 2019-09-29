#include <Wire.h>
#include <VL53L0X.h>
#include "TimerOne.h"

int interval=40;

int digPin = 9; // pin digital 9
float error=0;
const int pastSize = 2;
double dist=0;
double dist1=0;
long previousMillis = 0;        // will store last time PWM was updated
int analoginic=65;              // initial pwm
int analogfin=75;               // final pwm
int analog=analoginic;
float motorCmd=0;

float desired=0;  // Desired value (speed or angle) from host.
float Uin=70;
float pastError[pastSize];
float sum;
float distOP=7; //set operating point
VL53L0X sensor;


void setup() {
 
    int myEraser = 7;             // this is 111 in binary and is used as an eraser
    TCCR2B &= ~myEraser;   // this operation (AND plus NOT),  set the three bits in TCCR2B to 0
    int myPrescaler = 1;         // this could be a number in [1 , 6]. In this case, 3 corresponds in binary to 011.   
    TCCR2B |= myPrescaler;  //this operation (OR), replaces the last three bits in TCCR2B with our new value 011

    Serial.begin(230400);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
    }
    Wire.begin();

    sensor.init();
    sensor.setTimeout(500);
#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  sensor.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif

#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor.setMeasurementTimingBudget(200000);
#endif

}



void loop() {
  control();
  Relay();

 }


void control()
{
 
  for(int i =pastSize-1; i>0; i--){
  pastError[i] = pastError[i-1];
  }
  
  error = desired - dist1;

  pastError[0] = error;

  if(error>1)
  motorCmd=10;          // INSERT HERE UPPER PWM VALUE
  else
  if(error<-1)
  motorCmd=-10;          // INSERT HERE LOWER PWM VALUE
  
  
  //motorCmd = min(max(motorCmd+Uin, 0), 100);

  analogWrite(digPin,(min(max(motorCmd+Uin, 0), 100)*255/100));

}


float filter(float x) //class II 
    {
      float v[2];
      v[0]=0.0;
      v[0] = v[1];
      v[1] = (3.131764229192701265e-3 * x)
         + (0.99373647154161459660 * v[0]);
      return 
         (v[0] + v[1]);
    }

void Relay()
{
  unsigned long currentMillis = millis();
   if(currentMillis - previousMillis >= interval) {
     previousMillis = currentMillis;
    dist=sensor.readRangeSingleMillimeters();
  dist1=-((filter(dist))*24.2917466410749)+14;
  dist1=dist1-distOP;

  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
     
  Serial.print(millis());
  Serial.print(" ");
  Serial.print(motorCmd);
  Serial.print(" ");
  Serial.print(error);
  Serial.print(" ");
  Serial.println(dist1);

  }
}

import processing.serial.*;
import cc.arduino.*;


Arduino arduino;

int ledPin = 3;
boolean led = false;

void setup(){
  size(200,200);
  arduino = new Arduino(this,Arduino.list()[0],38400);
  arduino.pinMode(ledPin,Arduino.OUTPUT);
  arduino.digitalWrite(ledPin,arduino.HIGH);
}

void draw(){
  
}

void mousePressed(){
  if(led){
    arduino.digitalWrite(ledPin,Arduino.HIGH);
  }else{
    arduino.digitalWrite(ledPin,Arduino.LOW);
  }
  led = !led;
}

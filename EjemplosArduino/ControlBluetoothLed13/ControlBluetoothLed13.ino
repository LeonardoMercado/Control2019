#include <SoftwareSerial.h>

int DATO = 0;
int LED = 13;

void setup(){
  Serial.begin(19200);
  pinMode(LED,OUTPUT);

}

void loop(){
  if(Serial.available()){
    DATO = (Serial.read());
    if(DATO == '1'){
      digitalWrite(LED,!digitalRead(LED));
    }
  }
}

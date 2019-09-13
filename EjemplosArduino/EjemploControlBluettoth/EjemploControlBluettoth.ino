#include <SoftwareSerial.h>



char DATO = 0;
int LEDROJO = 2;
int LEDVERDE = 3;
int LEDAZUL = 4;

void setup(){
  Serial.begin(19200);
  pinMode(LEDROJO,OUTPUT);
  pinMode(LEDVERDE,OUTPUT);
  pinMode(LEDAZUL,OUTPUT);
}

void loop(){
  if(Serial.available()){
    DATO = (Serial.read());
    if(DATO == '1'){
      digitalWrite(LEDROJO,!digitalRead(LEDROJO));
    }
    if(DATO == '2'){
    digitalWrite(LEDAZUL,!digitalRead(LEDAZUL));
    }
    if(DATO == '3'){
    digitalWrite(LEDVERDE,!digitalRead(LEDVERDE));
    }
  }
}

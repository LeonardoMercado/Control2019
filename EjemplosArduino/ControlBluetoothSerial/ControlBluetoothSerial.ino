#include <SoftwareSerial.h>



char DATO = 0;
int LEDROJO = 2;
int LEDVERDE = 3;
int LEDAZUL = 4;
int LEDPEQ = 13;
int BOTON = 5;


void setup(){
  Serial.begin(9600);
  pinMode(LEDROJO,OUTPUT);
  pinMode(LEDVERDE,OUTPUT);
  pinMode(LEDAZUL,OUTPUT);
  pinMode(LEDPEQ,OUTPUT);
  pinMode(BOTON,INPUT);
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
    if(DATO == '4'){
    digitalWrite(LEDPEQ,!digitalRead(LEDPEQ));
    }
  }
  if(digitalRead(BOTON) == 0){
    Serial.write(23);
    Serial.write(57);
  }
}

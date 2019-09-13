int ledRojo = 3;
int ledAzul = 2;
char dato = 0;

void setup() {
  Serial.begin(38400);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledAzul,OUTPUT);
}

void loop() {
  if(Serial.available()){
    dato = Serial.read();
    if(dato == '1'){
      digitalWrite(ledRojo,!digitalRead(ledRojo));
    }
    if(dato == '2'){
      digitalWrite(ledAzul,!digitalRead(ledAzul));
    }
  }

}

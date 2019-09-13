void setup() {
  Serial.begin(38400);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop() {
  if(Serial.available()){
    char dato = Serial.read();

    if(dato == '1'){
      digitalWrite(12,HIGH);
    }
    if(dato == '2'){
      digitalWrite(12,LOW);
    }
        
    
  }

}

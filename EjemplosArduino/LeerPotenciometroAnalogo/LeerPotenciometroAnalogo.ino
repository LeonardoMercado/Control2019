
int pot = 0;
int dato = 0;

void setup(){
  Serial.begin(19200);
  
}

void loop(){
  dato = analogRead(pot);
  Serial.println(dato);
  delay(100);
   
}


int pot1 = 0;
int canal1 = 0;
int pot2 = 6;
int canales[8];



void setup(){
  Serial.begin(19200);  
}

void loop(){
  canales[0] = (analogRead(pot1));
  canales[1] = (analogRead(pot2));
  canales[2] = (analogRead(pot1));
  canales[3] = (analogRead(pot2));
  canales[4] = (analogRead(pot1));
  canales[5] = (analogRead(pot2));
  canales[6] = (analogRead(pot1));
  canales[7] = (analogRead(pot2));

  Serial.println(canales[0]);
  Serial.println(canales[1]);
  Serial.println(canales[2]);
  Serial.println(canales[3]);
  Serial.println(canales[4]);
  Serial.println(canales[5]);
  Serial.println(canales[6]);
  Serial.println(canales[7]); 
  
  
  delay(100);
   
}

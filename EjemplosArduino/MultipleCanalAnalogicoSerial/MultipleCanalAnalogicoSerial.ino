
int pot1 = 0;
int canal1 = 0;
int pot2 = 6;
int canales[5];



void setup(){
  Serial.begin(19200);  
}

void loop(){
  canales[0] = analogRead(pot1);
  canales[1] = analogRead(pot2);
  canales[2] = analogRead(pot1);
  canales[3] = analogRead(pot2);
  canales[4] = analogRead(pot1);

 
  Serial.print("S1:");
  Serial.print(canales[0]);
  Serial.print("   ");
  //Serial.print('\t');
  Serial.print("S2:");
  Serial.print(canales[1]);
  Serial.print("   ");
  //Serial.print('\t');
  Serial.print("S3:");
  Serial.print(canales[2]);
  Serial.print("   ");
  //Serial.print('\t');  
  Serial.print("S4:");
  Serial.print(canales[3]);
  Serial.print("   ");
  //Serial.print('\t');
  Serial.print("S5:");
  Serial.println(canales[4]);


  
  
  
  delay(100);
   
}

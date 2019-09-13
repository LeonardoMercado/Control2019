
unsigned char canal[8];
unsigned char i = 0;



void setup(){
  Serial.begin(19200);  
}

void loop(){

  canal[0] = i;
  canal[1] = (analogRead(A6))/4;
  canal[2] = (analogRead(A0))/4;
  canal[3] = (analogRead(A6))/4;
  canal[4] = (analogRead(A0))/4;
  canal[5] = (analogRead(A6))/4;
  canal[6] = (analogRead(A0))/4;
  canal[7] = (analogRead(A6))/4;
  

  Serial.write(canal[0] + 48);
  delay(5);
  Serial.write(canal[1] + 48);
  delay(5);
  Serial.write(canal[2] + 48);
  delay(5);
  Serial.write(canal[3] + 48);
  delay(5);
  Serial.write(canal[4] + 48);
  delay(5);
  Serial.write(canal[5] + 48);
  delay(5);
  Serial.write(canal[6] + 48);
  delay(5);
  Serial.write(canal[7] + 48);
  delay(5);
  Serial.write('\n');

  /*
  Serial.print("S1: ");
  Serial.print(canal[0]);
  Serial.print("  ");
  Serial.print("S2: ");
  Serial.print(canal[1]);
  Serial.print("  ");
  Serial.print("S3: ");
  Serial.print(canal[2]);
  Serial.print("  ");
  Serial.print("S3: ");
  Serial.print(canal[3]);
  Serial.print("  ");
  Serial.print("S4: ");
  Serial.println(canal[4]);*/
  i++;  
  
  
  delay(100);
   
}

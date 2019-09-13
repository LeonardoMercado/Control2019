char DATO = 0;


void setup(){
  Serial.begin(9600);
}
 
void loop(){
  DATO = analogRead(A0);
  Serial.println(DATO);
}

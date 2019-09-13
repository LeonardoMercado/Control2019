
int pot = 1;



void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  int entrada = analogRead(pot);  
  Serial.println(entrada);
  

}

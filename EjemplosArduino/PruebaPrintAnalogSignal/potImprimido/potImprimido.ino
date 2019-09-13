
int led = 3;
int pot = 0;



void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
  int val = analogRead(pot);
  int brillo = val / 4;
  analogWrite(led,brillo);
  Serial.println(brillo);
  delay(20);

  

}

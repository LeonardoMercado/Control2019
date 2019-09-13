
int in1 = 8;
int in2 = 7;
int ena = 9;
int pot = 0;

void setup() {

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(ena,OUTPUT);

}

void loop(){

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  int velocidad = analogRead(pot)/4;
  analogWrite(ena,velocidad);

}

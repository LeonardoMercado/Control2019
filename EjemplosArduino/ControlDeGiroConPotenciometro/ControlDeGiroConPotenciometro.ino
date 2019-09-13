int in1 = 8;
int in2 = 7;
int pot = 0;

void setup() {

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);

  
}
  
void loop() {

  int giro = analogRead(pot)/4;
  
  if(giro>=127){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }

}

/*
 * realizar un programa que al pulsarse el boton encienda el led por
 * 5 segundos y despues se apage
 */
int salida = 2;
int entrada = 3;

void setup(){
  pinMode(salida, OUTPUT);
  pinMode(entrada, INPUT);
}

void loop(){
  if(digitalRead(entrada) == HIGH){
    digitalWrite(salida,HIGH);
    delay(5000);
    digitalWrite(salida,LOW);
  }
  
}

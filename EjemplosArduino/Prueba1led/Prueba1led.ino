void setup(){ 
  
  pinMode(13,OUTPUT); //Se inicializa el pin 13 como salida

  /*
   * Comentario por bloques
   */
  
}

void loop(){
  
  digitalWrite(13,HIGH); //setea el pin 13 en alto
  delay(2000);  //tiempo de espera medida en milesimas de segundos
  digitalWrite(13,LOW); // setea el pin 13 en bajo
  delay(2000); // tiempo de espera en apagado

    
}

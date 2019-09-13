/*
 * En este espacio se pueden declarar las variables Globales
 */
 int BOTON = 3;
 int SALIDA = 2;
 int estado = LOW;

void setup(){

  pinMode(SALIDA,OUTPUT);
  pinMode(BOTON,INPUT);
  
}
void loop(){  
  /*
   * digitalRead recibe un solo parametro, el numero de pin que esta 
   * muestreando, y retorna HIGH si esta en alta la entrada o LOW si esta 
   * en baja la entrada.
   */
   /*
   if(digitalRead(BOTON) == HIGH){
      digitalWrite(SALIDA,HIGH);      
   }else{
      digitalWrite(SALIDA,LOW);
   }    */
   while(digitalRead(BOTON)== LOW){
                 
   }
   estado = digitalRead(SALIDA);
   digitalWrite(SALIDA,!estado);

   while(digitalRead(BOTON) == HIGH){  //Antirebote para el Boton
      
      
   }
    
}

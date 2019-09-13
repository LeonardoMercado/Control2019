#include <elapsedMillis.h> 
elapsedMillis SimTime; // Tiempo en milisegundos
elapsedMicros loopTime; // Tiempo en microsegundos

int deltaT=20000; // Periodo de muestreo en microsegundos

void setup() {
    Serial.begin(115200); // se define la velocidad de conexión en Baudios
     while (!Serial) {
    ; // Esperar mientras el puerto se conecta. Necesario solo en conexión USB
  }
}

float u=0,y=0;

void loop() {
  //-------------------------------------------------------------
  //CONFIGURACIÓN DE PARAMETROS
  float A = 5;      
  int T = 300;
  //-------------------------------------------------------------  

  //------------------------------------------------------------- 
  //SEÑALES A IMPRIMIR
   
   u = A*0.003333*(SimTime % 300);
  
  //------------------------------------------------------------- 
  
  // Imprime los datos
  //-------------------------------------------------------------
  Serial.print(u);
  Serial.print('\t');
  Serial.println(y);           //Otras señales aquí
  //-------------------------------------------------------------

  while(loopTime<deltaT){ } //esperar hasta completar el siguiente ciclo y así puede mantener la frecuencia de operación constante
 
  loopTime=0;
 
}

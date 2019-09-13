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
  float fr = (0.001);        // Defina la frecuencia
  float A = 5;               // Denfia la Amplitud aquí
  float fi = 0;              // Defina el desfase aquí
  //-------------------------------------------------------------  

  //------------------------------------------------------------- 
  //SEÑALES A IMPRIMIR
   
  u = A*sin(2*PI*fr*SimTime + fi);
  
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

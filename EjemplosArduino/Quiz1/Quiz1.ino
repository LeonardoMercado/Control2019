#include <elapsedMillis.h> 
elapsedMillis SimTime; // Tiempo en milisegundos
elapsedMicros loopTime; // Tiempo en microsegundos

int deltaT=20000; // Periodo de muestreo en microsegundos

void setup() {
    Serial.begin(2000000); // se define la velocidad de conexión en Baudios
     while (!Serial) {
    ; // Esperar mientras el puerto se conecta. Necesario solo en conexión USB
  }
}

float u=0,y=30;

void loop() {
// Operciones sobre variables 

u=y-3;

// Enviar Datos
Serial.print(u);
Serial.print('\t');
Serial.println(y);

while(loopTime<deltaT){ } //esperar hasta completar el siguiente ciclo y mantener la frecuencia de operación constante
 
loopTime=0;
 
}


/*
voltimetro de verdadero valor eficaz 

Autor Pedro Robles
24/05/14

solo para 50 hz.
para otras frecuencias hay que cambiar la longitud de la matriz
ojo muy importante !!!!!!!
se pone la entrada analogica A1 a la mitad de Vcc mediante un divisor resistivo

*/


int lecturas[80]; // declaro matriz
unsigned long suma=0; // variable para la suma de los cuadrados
float rms=0;    // varible para la media de cuadrados
float volt=0;    // varible para la tension

void  setup()
{
  Serial.begin (9600);    // inicio comunicacion serial
 }
void loop(){
    for(byte cont=0;cont<80;cont++)      //hace un bucle for
  {                                  
    lecturas[cont]=analogRead(A1);     // Se toman 80 lecturas en la entrada A1 con un intervalo de 500 microsegudo obteniendose asi el equivalente a un ciclo en 50 hz
    delayMicroseconds(250);  // para completar un ciclo completo
  }
    for(byte j=0;j<80;j++)     // otro for para calcular los cuadrados
  {    
   // Serial.println(lecturas[j]); // para debuguear
    suma=suma+pow((lecturas[j]-509),2);  // calcula la suma de los cuadrados, se resta el valor de VCC
  //  Serial.println(suma);  // para debuguear
  }
 rms=sqrt((suma/80));
 volt=rms*0.0044;   //   0.0044=4.58/1024  ( 4,58 tensioin de salida usb)
 Serial.println(volt);
 
 suma=0;
} 

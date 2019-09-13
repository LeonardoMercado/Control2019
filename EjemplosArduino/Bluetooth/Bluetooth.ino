#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);

/*Donde pinDigital 10 = Rx en el arduino
 * y pingDigital 11 = Tx en el arduino
 * 
 * Conecte Rxd (Del HC-06) al pin 11
 * conecte Txd (Del HC-06) al pin 10
 * 
 * Recuerde comandos de lectura:
 *    AT
 *    AT+NAME?
 *    AT+PSWR?
 *    AT+UART?
 *    AT+ROLE?
 * Recuerde comandos de escritura:
 *    AT+NAME="Nombre"
 *    AT+PSWR=XXXX
 *    AT+UART=BPS,Parity,StopBit (Ejemplo = 19200,0,0)
 *    AT+ROLE=0; (0 = slave y 1 = master)
 * 
 */

void setup(){
  Serial.begin(9600);
  Serial.println("Listo");
  miBT.begin(38400);
}

void loop(){
  if(miBT.available()){ //lee BT y envia a arduino
    Serial.write(miBT.read());
  }
  if(Serial.available()){
    miBT.write(Serial.read()); //Lee Serial y envia a BT
  }
}

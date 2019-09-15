//*
//********************************************************************************************
//* UNIVERSIDAD NACIONAL DE COLOMBIA - SEDE BOGOTÁ - CONTROL 2019-II 
//********************************************************************************************
//*
//* Title: Código para proyecto de control 2019-II.
//*
//* Author: Leonardo Fabio Mercado Benítez.
//*         Paulo Jocirei Dias 
//*         Santiago
//*
//* Description: Salida PWM en PIN-DIG 9(Led), 10(enA).
//* 
//* Documentation: https://github.com/LeonardoMercado/Control2019
//*
//* Include Files: Ninguno.
//*
//* Rev #      Date           Who             Comments
//* ----- ------------ -------------------  ---------------------------------------------------
//*  1.1	15-sep-2019   Leonardo M. Benítez Se implementa el PWM por App para led y Ventilador  de 10bits
//*
//*
//********************************************************************************************

String cadena, objetivo, dato; //Variables auxiliares para el manejo del mensaje
int led = 9;     //Define el puerto Digital a conectar el led
int enA = 10;    //Define el puerto para enviar el PWM al enA
int valor;       //Valor final del mensaje recibido

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void setup () {
    Serial.begin(19200);  //Inicializa el puerto Serial (Segun config del Bluetooth)
    while(!Serial){       //Espera a que el serial esta Habilitado
    }
    pinMode(led,OUTPUT);  //Configura el led como salida
    pinMode(enA,OUTPUT);  //Configura el enA como salida
    setupPWM10();
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void loop () {  
  if (objetivo == "led"){     //Selecciona el receptor del mensaje
    //analogWrite10(led, valor);  //Entrega el mensaje modificando el PWM del objetivo
    analogWrite10(led, valor);  //Entrega el mensaje modificando el PWM del objetivo
  }
  else if(objetivo == "motor"){ //Selecciona el receptor del mensaje
    //analogWrite10(enA, valor);  //Entrega el mensaje modificando el PWM del objetivo
    analogWrite10(enA, valor);  //Entrega el mensaje modificando el PWM del objetivo

  }    
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - INTERRUPCIÓN DE LA COMUNICACIÓN SERIAL- - - - - - - - - - - - - - - - - - - - - - - - - -
void serialEvent() {
  if(Serial.available()){     // Pregunta si hay dato en el buffer de entrada.
    recibirMensaje();         // LLamada a recibirMensaje
  } 
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - FUNCION PARA RECIBIR EL MENSAJE Y EL OBJETIVO - - - - - - - - - - - - - - - - - - - - - -
void recibirMensaje(){
  cadena = String("");
    while (Serial.available()) { //Mientras Haya dato en el Buffer del Uart
      cadena = cadena + char(Serial.read());  //Concate el mensaje y lo almacena en cadena
      delay(1);                  
    }
    if (cadena.indexOf(" ") >=0){ //Comprobación de mensaje 
      objetivo = cadena.substring(0,(cadena.indexOf(" "))); //Filtra la cadena en el objetivo
      dato = cadena.substring(cadena.indexOf(" ")+1);  //Filtra la cadena en el valor del mensaje
      valor = dato.toInt();   //Convierte el valor recibido en un entero
      //Serial.println(valor);  //Muestra el valor en recibido en el terminal serial
    }
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - FUNCION PARA CONFIGURACION DE REGISTROS - - - - - - - - - - - - - - - - - - - - - - - - -
/* Configure digital pins 9 and 10 as 12-bit PWM outputs. */
void setupPWM10(){
  DDRB |= _BV(PB1) | _BV(PB2);        /* set pins as outputs */
  TCCR1A = _BV(COM1A1) | _BV(COM1B1)  /* non-inverting PWM */
      | _BV(WGM11);                   /* mode 14: fast PWM, TOP=ICR1 */
  TCCR1B = _BV(WGM13) | _BV(WGM12)
      | _BV(CS10);                    /* no prescaling */
  ICR1 = 0x03ff;                      /* TOP counter value */
}

/* 10-bit version of analogWrite(). Works only on pins 9 and 10. */
void analogWrite10(unsigned char pin, unsigned int val){
  switch (pin) {
    case  9: OCR1A = val; break;
    case 10: OCR1B = val; break;
  }
}
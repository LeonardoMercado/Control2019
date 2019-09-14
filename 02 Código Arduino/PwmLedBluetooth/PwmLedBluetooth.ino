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
//* Description: Salida PWM en PIN-DIG 3(Led), 5(enA).
//* 
//* Documentation: https://github.com/LeonardoMercado/Control2019
//*
//* Include Files: Ninguno.
//*
//* Rev #      Date           Who             Comments
//* ----- ------------ -------------------  ---------------------------------------------------
//*  1.0	14-sep-2019   Leonardo M. Benítez Se implementa el PWM por App para led y Ventilador
//*
//*
//********************************************************************************************

String cadena, objetivo, dato; //Variables auxiliares para el manejo del mensaje
int led = 3;      //Define el puerto Digital a conectar el led
int enA = 5;    //Define el puerto para enviar el PWM al enA
int valor;        //Valor final del mensaje recibido

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void setup () {
    Serial.begin(19200);  //Inicializa el puerto Serial (Segun config del Bluetooth)
    while(!Serial){       //Espera a que el serial esta Habilitado
    }
    pinMode(led,OUTPUT);  //Configura el led como salida
    pinMode(enA,OUTPUT);  //Configura el enA como salida
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void loop () {  
  if (objetivo == "led"){     //Selecciona el receptor del mensaje
    analogWrite(led, valor);  //Entrega el mensaje modificando el PWM del objetivo
  }
  else if(objetivo == "motor"){ //Selecciona el receptor del mensaje
    analogWrite(enA, valor);  //Entrega el mensaje modificando el PWM del objetivo
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
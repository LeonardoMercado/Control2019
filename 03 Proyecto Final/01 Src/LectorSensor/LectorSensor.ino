//********************************************************************************************
//* UNIVERSIDAD NACIONAL DE COLOMBIA - SEDE BOGOTÁ - CONTROL 2019-II 
//********************************************************************************************
//*
//* Title: Código para proyecto de control 2019-II [Levitador Neúmatico].
//*      sub: Código para la lectura del Sensor VL530L0x-CJMCU
//*
//* Author: Leonardo Fabio Mercado Benítez.
//*         Paulo Jocirei Dias 
//*         Santiago
//*
//* Description: Lectura por i^2C del sensor de distancia VL530L0x.
//* 
//* Documentation: https://github.com/LeonardoMercado/Control2019
//*
//* Include Files: Libreria VL530L0x pololu v 1.0.2
//*
//* Rev #      Date           Who             Comments
//* ----- ------------ -------------------  ---------------------------------------------------
//*  1.0  29-sep-2019   Leonardo M. Benítez Se implementa la lectura por puertos Analogicos
//*                                          (Tiempo de muestreo+promedio = 395ms)
//*
//********************************************************************************************

//*Conecciones: 
//*  _____________________________________
//*  |SENSOR VL530L0x-CJMCU|     |ARDUINO|
//*  |   -VDD --------------------->+5v  |
//*  |   -GND --------------------->GND  |
//*  |   -SCL --------------------->A5   |
//*  |   -SDA --------------------->A4   |
//*  |   -DNC --------------------->NC   |
//*  |   -GND2 -------------------->GND  |
//*  |   -XSH --------------------->+5v  |
//*  |   -INT --------------------->NC   |
//*  |___________________________________|
//*  ¡La distancia del cable afecta la lectura del sensor!
//*

#include <Wire.h>
#include <VL53L0X.h>


VL53L0X sensor;

void setup(){
  Serial.begin(19200);
  while(!Serial){
  }
  Serial.println("Configurando el sensor");
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous(20);  //Define el Tiempo de medición en miliSegundos
  Serial.println("Fin configuración");
  Serial.println("Iniciando a medir: ");
}
void loop(){  
  medirDistancia();
}
void medirDistancia(){
  int medida = 0;
  int muestras = 10;
  unsigned long time = 0;
  unsigned long time1 = 0;
  time1 = millis();
  for (int i = 0; i < muestras; i++){
    medida += sensor.readRangeContinuousMillimeters();
  }  
  time = millis()-time1;
  Serial.print("Fin del promedio, time quedo en: [");
  Serial.print(time);
  Serial.println("] millis");  
  Serial.print("Distancia [mm]: ");
  Serial.println((medida/muestras));
  if (sensor.timeoutOccurred()){
    Serial.print(" TIMEOUT");
  }
}
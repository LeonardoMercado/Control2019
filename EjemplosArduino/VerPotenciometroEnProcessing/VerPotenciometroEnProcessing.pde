import processing.serial.*;

Serial puerto;


void setup(){
 size(400,400);
 puerto = new Serial(this, Serial.list()[0], 38400);
 background(0);
}


void draw(){
    
    String dato = puerto.readStringUntil('\n');
    
    if(dato != null){
      background(0);
      textSize(100);
      text(dato,100,300);
  }
}

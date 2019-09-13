import processing.serial.*;

Serial puerto;


void setup(){
 puerto = new Serial(this, Serial.list()[0], 38400);
 size(300,200);
 background(0,0,0);
}

void draw(){
  
  fill(255,255,255);
  textSize(16);
  textAlign(CENTER, TOP);
  text("CONTROL LEDS CON PROCESSING",150,25);
  stroke(0,0,255);
  strokeWeight(2);  
  
  fill(255,255,255);
  rect(60,90,60,60,3);
  fill(0,0,0);
  text("LEDR",90,120);
  
  
  fill(255,255,255);
  rect(150,90,60,60,3);
  fill(0,0,0);
  text("LEDA",180,120);
    
}

void mousePressed(){
  if((mouseX>=60 & mouseX<=120)&(mouseY>=90 & mouseY<150)){
    fill(255,0,0);
    rect(60,90,60,60,3);
    puerto.write('1'); 
    text(puerto.read(),150,180);
    
  }
  if((mouseX>150 & mouseX<210)&(mouseY>90 & mouseY<150)){
    fill(255,0,0);
    rect(150,90,60,60,3);
    puerto.write('2'); 
    text(puerto.read(),150,180);
    
  }
  
  
}

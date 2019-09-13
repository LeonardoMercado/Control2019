import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class ControlLedsProcessing extends PApplet {



Serial puerto;


public void setup(){
 puerto = new Serial(this, Serial.list()[0], 38400);
 
 background(0,0,0);
}

public void draw(){
  
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

public void mousePressed(){
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
  public void settings() {  size(300,200); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "ControlLedsProcessing" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

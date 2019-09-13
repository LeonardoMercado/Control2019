
int led = 3;
int pot = 0;
int brillo;

void setup(){
  
  pinMode(led,OUTPUT);
  //los puertos analogos no hay que declararlos
  
}

void loop(){

  brillo = analogRead(pot) / 4; //analogRead lee entre 0 a 1024

  analogWrite(led,brillo);

  
    
 
}

#include <Stepper.h>
const int stepsPerRevolution = 100; 
Stepper yStepper(stepsPerRevolution, 3,11,12,13); 
Stepper xStepper(stepsPerRevolution, 7,8,9,6);
Stepper zStepper(stepsPerRevolution,2,4,5,10);
String commandAux;
int xPosition=0;
int yPosition=0;
int zPosition=0;
int speedZ=50;
void setup() {
  Serial.begin(9600);
  moveToStartupPosition();
  //yStepper.setSpeed(70);  
  //xStepper.setSpeed(70);
  //zStepper.setSpeed(70);
  Serial.println("Ready\n");
  
}

void moveToStartupPosition(){
  Serial.println("Moving to startup position");
  
}

void moveToYPosition(int y){

}

void moveToXPosition(int x){

}

void moveToZPosition(int z){

}
void loop() {
    String command="";
    char character;
    while(Serial.available()) {
      character = Serial.read();
      commandAux.concat(character);
      if(character=='\n'){
        command=commandAux;
      }
      Serial.flush();
    }

    if (command != "") {
      Serial.println(command);
      command="";
    }
    //Serial.println("Sali");
   
    
}

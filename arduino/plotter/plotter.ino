#include <Stepper.h>
const int stepsPerRevolution = 4; 
Stepper yStepper(stepsPerRevolution, 3,11); 
Stepper xStepper(stepsPerRevolution, 7,8);
Stepper zStepper(stepsPerRevolution,2,4,5,10);
String commandAux;
int xPosition=0;
int yPosition=0;
int zPosition=0;
int speedZ=50;
String OK="OK";
void setup() {
  Serial.begin(9600);
  moveToStartupPosition();
  yStepper.setSpeed(70);  
  xStepper.setSpeed(800);
  zStepper.setSpeed(70);
  Serial.println("Ready\n");
  
}

void moveToStartupPosition(){
  Serial.println("Moving to startup position");
  
}

void moveXSteps(int x){
   xStepper.step(x);
   xPosition=xPosition+x;
}

void moveYSteps(int y){
   yStepper.step(y);
   yPosition=yPosition+y;
}

void moveToYPosition(int y){
  int dy=y-yPosition;
  Serial.println(dy);
  yStepper.step(dy);
  yPosition=y;
}

void moveToXPosition(int x){
   int dx=x-xPosition;
  Serial.println(dx);
  xStepper.step(dx);
  xPosition=x;
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
        commandAux="";
      }
    
    }

    if (command != "") {
      processCommand(command);
    }
   
   
    
}

void getCommandArgs(String command, String* args){
  int index = command.indexOf(' ');
  int aIndex=0;
  
  for(int i=index+1; i<command.length(); i++){
      char current = command.charAt(i);
      if(current!=','){
        args[aIndex].concat(command.charAt(i));
      }else{
        aIndex++;
      }
  }
}

String getCommandOperation(String command){
   int spIndex=command.indexOf(' ');
   String operation="";
   for(int i=0;i<spIndex; i++){
       operation.concat(command.charAt(i));
   }
   return operation;
}

void processCommand(String command){
 
  String operation=getCommandOperation(command);
  String args[10];
  getCommandArgs(command,&args[0]);
  if(operation=="moveto"){
     int y=args[1].toInt();
     int x=args[0].toInt();
     moveToYPosition(y);
     moveToXPosition(x); 
  }else if(operation=="move"){
     int y=args[1].toInt();
     int x=args[0].toInt();
     moveXSteps(x);
     moveYSteps(y); 
  }
  Serial.println(OK);
}

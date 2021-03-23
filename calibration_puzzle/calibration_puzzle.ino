#include <LiquidCrystal.h>
#define split1 341
#define split2 682
const int potOne = A0;
const int potTwo=A1;
const int potThree=A2;
const int  tiltSwitch = 11;
int setOne[3]={1,2,3}, setTwo[3]={1,2,3}, setThree[3]={1,2,3}, password[3]={1,3,2};
int lastState = HIGH;
int sensorVal;
LiquidCrystal myLCD(2,3,4,5,6,7);
int value1, value2, value3, loc1, loc2,loc3;
bool isCorrect=false;
void setup() {
  pinMode(potOne, INPUT);
  pinMode(potTwo, INPUT);
  pinMode(potThree, INPUT);
  
  pinMode(tiltSwitch, INPUT);
  digitalWrite(tiltSwitch, HIGH);

  
  myLCD.begin(16,2);
  myLCD.clear();
  myLCD.print("Check Sudoku");
  Serial.begin(9600);
  Serial.print(analogRead(tiltSwitch));

}

void loop() {
  if(!tiltIsOn()){
  value1=analogRead(potOne);
  
  value2=analogRead(potTwo);

  value3=analogRead(potThree);
  
  loc1=getSpot(value1);
  
  loc2=getSpot(value2);

  loc3=getSpot(value3);
  
  myLCD.setCursor(0,1);
  myLCD.print(setOne[loc1-1]);
  myLCD.setCursor(1,1);
  myLCD.print(setTwo[loc2-1]);
  myLCD.setCursor(2,1);
  myLCD.print(setThree[loc3-1]);
  if(setOne[loc1-1]==password[0] && setTwo[loc2-1]==password[1] &&setThree[loc3-1]==password[2]){
    isCorrect=true;
  }
  if(isCorrect){
    myLCD.setCursor(8,1);
    myLCD.print("Correct");
    delay(5000);
    myLCD.clear();
    myLCD.print("The guitar is");
    myLCD.setCursor(0,1);
    myLCD.print("bluffing.");
    delay(10000);
    myLCD.clear();
    myLCD.setCursor(0,0);
    myLCD.print("Key Number: 0");
    delay(10000);
    myLCD.clear();
    isCorrect=false;
    myLCD.print("Check Sudoku:");
  }
  delay(1000); 
  }
}

int getSpot(int val){
  if(val<split1){
    return 1;
  }
  else if(val<split2){
    return 2;
  }
  else{
    return 3;
  }

}

bool tiltIsOn(){
sensorVal=digitalRead(tiltSwitch);
if(sensorVal==HIGH){
  return true;
}
else{
  return false;
}

}

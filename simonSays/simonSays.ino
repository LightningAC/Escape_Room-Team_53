#define buttonstart A1
#define button2 A2
#define button3 A3
#define button4 A4
#define button5 A5
int light [15];
boolean correct;
boolean repeat;
#include <Servo.h>
Servo myServo;
int lightnumber=0;
int seed=100;
void setup() {
  // put your setup code here, to run once:

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT); 
pinMode(5,OUTPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT); 
pinMode(10,OUTPUT);


pinMode(6, OUTPUT); 

pinMode(buttonstart,INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP);
pinMode(button3,INPUT_PULLUP);
pinMode(button4,INPUT_PULLUP);
pinMode(button5,INPUT_PULLUP);
myServo.attach(7);

myServo.write(90);
Serial.begin(9600);
}

void loop() {

repeat=true;
randomSeed(analogRead(seed));
  
while(digitalRead(buttonstart)==HIGH){
}


//Generates random list of 15 random numbers 2-5
for(int i=0; i<15;i++){
  light[i]=random(2,6);
  if (light[i]==2){
    Serial.println("green");
  }
  if (light[i]==3){
    Serial.println("yellow");
  }if (light[i]==4){
    Serial.println("white");
  }
  if (light[i]==5){
    Serial.println("blue");
  }
}
//Lights up the lights corresponding to the random number generated


for(int i=0;i<15;i++){
  digitalWrite(light[i],HIGH);
  delay(500);
  digitalWrite(light[i],LOW);
  delay(500);
}




for(int i=1;i<16;i++){
    if(repeat){
      if(correctButton(light[i-1])){
          digitalWrite(14-(i/3),HIGH);
          delay(400);
         
 
     }
      else{
        repeat=false;
        digitalWrite(6,HIGH);
     }
  }
}

if(repeat){
         myServo.write(180);
         for(int i=0;i<6;i++){
         celebrate();
         }
}

/*
if(correctButton(light[0])){
      Serial.println("14");
      digitalWrite(13,HIGH);
      delay(500);
      if(correctButton(light[1])){
          Serial.println("15");
          digitalWrite(12,HIGH);
          delay(500);
          if(correctButton(light[2])){
              Serial.println("16");
              digitalWrite(11,HIGH);
              delay(500);
              if(correctButton(light[3])){
                  Serial.println("17");
                  digitalWrite(10,HIGH);
                  delay(500);
                      if(correctButton(light[4])){
                           Serial.println("correct combo");
                           myservo.write(180);
                           
                      }
                      else{
                        digitalWrite(9,HIGH);
                      }
              }
              else{
              digitalWrite(9,HIGH);
              }
         }
         else{
         digitalWrite(9,HIGH);
         }
     }
     else{
     digitalWrite(9,HIGH);
     }
}
else{
digitalWrite(9,HIGH);
}
*/
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
delay(1000);
digitalWrite(6,LOW);
seed=seed*2;
}





boolean correctButton(int x){
  boolean repeat=true;
  boolean correct=true;
  if(x==2){
       while((digitalRead(button5)==HIGH)&&(repeat)){
        while((digitalRead(button5)==LOW)&&(repeat)){
         
          repeat=false;
          
        }
        
           while((digitalRead(button2)==LOW)||(digitalRead(button3)==LOW)||(digitalRead(button4)==LOW)){
              correct=false;
              repeat=false;
              
          
           } 
       }
  }

  
  
  if(x==3){
       while((digitalRead(button4)==HIGH)&&(correct)){
          while((digitalRead(button4)==LOW)&&(correct)){
              
              repeat=false;
            
          }
        
           while((digitalRead(button2)==LOW)||(digitalRead(button3)==LOW)||(digitalRead(button5)==LOW)){
              correct=false;
              repeat=false;
              
          
           } 
       }
  }



  if(x==4){
       while((digitalRead(button3)==HIGH)&&(repeat)){
        while((digitalRead(button3)==LOW)&&(repeat)){
          
          repeat=false;
          
        }       
           while((digitalRead(button2)==LOW)||(digitalRead(button4)==LOW)||(digitalRead(button5)==LOW)){
              correct=false;
              repeat=false;
              
          
           } 
       }
  }

if(x==5){
       while((digitalRead(button2)==HIGH)&&(repeat)){
        while((digitalRead(button2)==LOW)&&(repeat)){
         
          repeat=false;
          ;
        }      
        
           while((digitalRead(button3)==LOW)||(digitalRead(button4)==LOW)||(digitalRead(button5)==LOW)){
              correct=false;
              repeat=false;
             
          
           } 
       }
  }
if(correct){
 digitalWrite(x,HIGH);
 delay(300);
 digitalWrite(x,LOW);
}
  
  return correct;
}


void celebrate() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
delay(100);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
delay(100);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
delay(100);
digitalWrite(10,LOW);
delay(350);
}
  

#include <LiquidCrystal.h>

#include <IRremote.h>

#define IR_PIN 2
#define zero 0xE916FF00
#define one 0xF30CFF00
#define two 0xE718FF00
#define three 0xA15EFF00
#define four 0xF708FF00
#define five 0xE31CFF00
#define six 0xA55AFF00
#define seven 0xBD42FF00
#define eight 0xAD52FF00
#define nine 0xB54AFF00
#define play 0xBF40FF00

LiquidCrystal myLCD(7,8,9,10,11,12);

int activate = 0;
int blackjackpassword[] = {1, 2, 3, 4};
int pokerpassword[] = {6, 5, 9, 7};

void setup() {
  myLCD.begin(16,2);

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  // won't activate until the user finds the IR remote and presses 0   
  while (activate == 0) 
  {
    myLCD.clear();
    myLCD.setCursor(0,0);
    myLCD.print("Aim remote at");
    myLCD.setCursor(0,1);
    myLCD.print("Marked location");
    delay(3000);
    myLCD.clear();
    myLCD.setCursor(0,0);
    myLCD.print("Press 0");
    myLCD.setCursor(0,1);
    myLCD.print("To begin");
    delay(4000);
    if (IrReceiver.decode())
    {
      if (IrReceiver.decodedIRData.decodedRawData != 0)
      {
        switch (IrReceiver.decodedIRData.decodedRawData)
        {
          case zero:
            activate = 1;
            myLCD.clear();
            break;
          case one:
          case two:
          case three:
          case four:
          case five:
          case six:
          case seven:
          case eight:
          case nine:
            activate = 0;
        }
      }
      IrReceiver.resume();
    }
  }
  // checks if the user can guess the poker puzzle
  checkpassword(pokerpassword, 2, 4);
  // will run indefinitely if the user guesses correctly 
  int complete = 1;
  while (complete == 1) {
    myLCD.clear();
    myLCD.setCursor(0,0);
    myLCD.print("Final code is");
    myLCD.setCursor(0,1);
    myLCD.print("0738");
    delay(50000); 
  }
}

// function that will read the input from the user and determine if the user's guess is correct based upon the password
void checkpassword(int password[], int storyline, int arraysize) {
  int correct = 0;
  int guess[arraysize];
  // will run until the user guesses correctly 
  while (correct == 0) {
    myLCD.clear();
    int count = 0;
    int temp = storyline;
    // displays the hints 
    if (temp == 2)
    {
      myLCD.setCursor(0,0);
      myLCD.write("Go take a look");
      myLCD.setCursor(0,1);
      myLCD.write("at Poker.");
      delay(3000);
      myLCD.clear();
      myLCD.setCursor(0,0);
      myLCD.write("Take a look at");
      myLCD.setCursor(0,1);
      myLCD.write("winning hands.");
      delay(3000);
      myLCD.clear();
      myLCD.setCursor(0,0);
      myLCD.write("Start with the");
      myLCD.setCursor(0,1);
      myLCD.write("player w/ sixes.");
      delay(3000);
      myLCD.clear();
      myLCD.setCursor(0,0);
      myLCD.write("What card does");
      myLCD.setCursor(0,1);
      myLCD.write("each player want");
      delay(3000);
      myLCD.clear();
      myLCD.setCursor(0,0);
      myLCD.write("Do not move");
      myLCD.setCursor(0,1);
      myLCD.write("the cards.");
      delay(3000);
      myLCD.clear();
      temp = 0;
    }
    // sets up the screen for the user to enter the password
    int index = 0;
    myLCD.setCursor(0,0);
    myLCD.write("Play to see hint");
    myLCD.setCursor(0,1);
    myLCD.write("Password: ");
    for (int k = 0; k < arraysize; k++)
    {
      myLCD.setCursor(k + 10, 1);
      myLCD.print("0");
    }
    // reads the password that is entered into the IR receiver
    while (index < arraysize ) {
      if (IrReceiver.decode())
      {
        if (IrReceiver.decodedIRData.decodedRawData != 0)
        {
          myLCD.setCursor(index + 10,1);
          switch (IrReceiver.decodedIRData.decodedRawData)
          {
            case zero:
              guess[index] = 0;
              myLCD.print("0");
              index++;
              break;
            case one:
              guess[index] = 1;
              myLCD.print("1");
              index++;
              break;
            case two:
              guess[index] = 2;
              myLCD.print("2");
              index++;
              break;
            case three:
              guess[index] = 3;
              myLCD.print("3");
              index++;
              break;
            case four:
              guess[index] = 4;
              myLCD.print("4");
              index++;
              break;
            case five:
              guess[index] = 5;
              myLCD.print("5");
              index++;
              break;
            case six:
              guess[index] = 6;
              myLCD.print("6");
              index++;
              break;
            case seven:
              guess[index] = 7;
              myLCD.print("7");
              index++;
              break;
            case eight:
              guess[index] = 8;
              myLCD.print("8");
              index++;
              break;
            case nine:
              guess[index] = 9;
              myLCD.print("9");
              index++;
              break;
            case play:
              index = arraysize + 1;
              temp = storyline;
          }
        }
        IrReceiver.resume();
      }
    }
    // checks if the password is correct
    for (int j = 0; j < arraysize; j++) {
      if (guess[j] == password[j])
      {
        count++;
      }
    }
    // displays incorrect and will continue in the while loop
    if (count < arraysize && temp == 0) 
    {
      correct = 0;
      myLCD.setCursor(0,0);
      myLCD.print("Incorrect       ");
      delay(3000);
    }
    // displays correct and breeaks out of the while loop
    if (count == arraysize && temp == 0) 
    {
      correct = 1;
      myLCD.setCursor(0,0);
      myLCD.print("Correct         ");
      delay(3000);
    }
  }
}

/**************************************/
/*  Laser Maze Puzzle Code Ver. 1.0   */
/*  Author: Aaron Chen    Team 53     */
/*  ENGR 1282.01H     Freuler 3:00    */
/**************************************/

//Photoresistor Pinout
#define photoPin A0
int photoValue = 0;
int roomLight = 0;
bool solved = false;

//7-Segment Display Pinouts
#define A_pin 8
#define B_pin 9
#define C_pin 10
#define D_pin 5
#define E_pin 4
#define F_pin 7
#define G_pin 6
#define DP_pin 11
int state = 0;
int count = 0;
int start = 0;

//Array that stores the code
int code[] = {1, 2, 3, 4};


void setup() {
  //Initialize Serial Monitor
  Serial.begin(9600);


  //Photoresistor Setup
  pinMode(photoPin, INPUT);



  //7-Segment Display Setup
  pinMode(A_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  pinMode(C_pin, OUTPUT);
  pinMode(D_pin, OUTPUT);
  pinMode(E_pin, OUTPUT);
  pinMode(F_pin, OUTPUT);
  pinMode(G_pin, OUTPUT);
  pinMode(DP_pin, OUTPUT);

  //Generate code
  Serial.print("Code: ");
  for (int i = 0; i < 4; i++) {
    code[i] = random(10);
    Serial.print(code[i]);
  }
  Serial.println();


  state = code[0];

}

void loop() {
  photoValue = analogRead(photoPin);
  Serial.println(photoValue);
  if (start == 10) {
    Serial.println("Calibrating photoresistor...");
    roomLight += analogRead(photoPin);
    Serial.print("Calibrated value: ");
    Serial.println(roomLight);
  }
  if (photoValue > roomLight + 10 && start > 10) {
    solved = true;
    Serial.println("Puzzle Solved");
  }
  while (solved == true)
    revealCode();
  start++;
}



//This function displays the randomly generated code on a 7-segment display using a state machine
void revealCode() {
  Serial.print(count);
  Serial.print("  ");
  Serial.print(state);
  Serial.print("  ");
  Serial.println(code[count]);
  count++; //Increment through the code
  switch (state)
  {
    case 9:
      // Turn on the segments that correspond a '9'
      // Turn off the segments that should be off
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, LOW);
      digitalWrite(E_pin, LOW);
      digitalWrite(F_pin, HIGH);
      digitalWrite(G_pin, HIGH);
      digitalWrite(DP_pin, LOW);
      state = code[count]; // Change the state to the next value in the code
      break;

    case 8:
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, HIGH);
      digitalWrite(E_pin, HIGH);
      digitalWrite(F_pin, HIGH);
      digitalWrite(G_pin, HIGH);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 7:
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, LOW);
      digitalWrite(E_pin, LOW);
      digitalWrite(F_pin, LOW);
      digitalWrite(G_pin, LOW);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 6:
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, LOW);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, HIGH);
      digitalWrite(E_pin, HIGH);
      digitalWrite(F_pin, HIGH);
      digitalWrite(G_pin, HIGH);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 5:
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, LOW);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, HIGH);
      digitalWrite(E_pin, LOW);
      digitalWrite(F_pin, HIGH);
      digitalWrite(G_pin, HIGH);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 4:
      digitalWrite(A_pin, LOW);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, LOW);
      digitalWrite(E_pin, LOW);
      digitalWrite(F_pin, HIGH);
      digitalWrite(G_pin, HIGH);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 3:
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, HIGH);
      digitalWrite(E_pin, LOW);
      digitalWrite(F_pin, LOW);
      digitalWrite(G_pin, HIGH);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 2:
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, LOW);
      digitalWrite(D_pin, HIGH);
      digitalWrite(E_pin, HIGH);
      digitalWrite(F_pin, LOW);
      digitalWrite(G_pin, HIGH);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 1:
      digitalWrite(A_pin, LOW);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, LOW);
      digitalWrite(E_pin, LOW);
      digitalWrite(F_pin, LOW);
      digitalWrite(G_pin, LOW);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
    case 0:
      digitalWrite(A_pin, HIGH);
      digitalWrite(B_pin, HIGH);
      digitalWrite(C_pin, HIGH);
      digitalWrite(D_pin, HIGH);
      digitalWrite(E_pin, HIGH);
      digitalWrite(F_pin, HIGH);
      digitalWrite(G_pin, LOW);
      digitalWrite(DP_pin, LOW);
      state = code[count];
      break;
  }


  //Display the last value in the code for 5 sec and restart the cycle
  if (count == 4) {
    delay(5000);
    count = 0;
    state = code[count];
  }
  else {
    delay(1000);
  }
}

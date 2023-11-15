#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 6  //Left Motor MB1
#define m4 7  //Left Motor MB2
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
//***************Switch 1,2,3,4,R,L**********************//
#define sw1 12 
#define sw2 2
#define sw3 11
#define sw4 3
//#define swR
//#define SwL


void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);                                          
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  
  
}

void  MotorSpeed (int speed_A, int speed_B)
{
  if (speed_B >= 0)
  {
    analogWrite(e1, speed_B);
    digitalWrite(m1, LOW);
    digitalWrite(m3, HIGH);
  }
  else
  {
    analogWrite(e1, -speed_B);
    digitalWrite(m1, HIGH);
    digitalWrite(m3, LOW);
  }
  if (speed_A >= 0)
  {
    analogWrite(e2, speed_A);
    digitalWrite(m2, HIGH);
    digitalWrite(m4, LOW);
  }
  else
  {
    analogWrite(e2, -speed_A);
    digitalWrite(m2, LOW);
    digitalWrite(m4, HIGH);
  }

}
  
  
void loop() {
  // Reading Sensor Values
  int s1 = analogRead(ir1);  // Left Most Sensor
  int s2 = analogRead(ir2);  // Left Sensor
  int s3 = analogRead(ir3);  // Middle Sensor
  int s4 = analogRead(ir4);  // Right Sensor
  int s5 = analogRead(ir5);  // Right Most Sensor

  // Reading switch condition
  // int s

  


 // if only Middle Sensor detects a black line // forward with 2 motors
if ((s1 < 300) && (s2 < 300) && (s3 > 300) && (s4 < 300) && (s5 < 300)) {
  MotorSpeed(150, 150);
}

// RIGHT
// if only RIGHT Sensor detects a black line // turn right with left motor
if ((s1 < 300) && (s2 > 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  MotorSpeed(255,80);
}

// if only Most RIGHT Sensor detects a black line // turn right with left motor
if ((s1 > 300) && (s2 < 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  MotorSpeed(255, 80);
}

// if Both RIGHT sensor detects a black line // turn right with left motor
if ((s1 > 300) && (s2 > 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  MotorSpeed(255, 80);
}

// LEFT
// if only LEFT sensor detects a black line // turn Left with right motor
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 > 300) && (s5 < 300)) {
  MotorSpeed(80, 250);
}

// if only Most LEFT sensor detects a black line // turn left with right motor
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 < 300) && (s5 > 300)) {
  MotorSpeed(80, 250);
}

// if only Both LEFT sensor detects a black line // turn left with right motor
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 > 300) && (s5 > 300)) {
  MotorSpeed(80, 250);
}

// MIDDLE RIGHT LEFT

// MIDDLE RIGHT
// if Middle and Right sensor detects black lines
if ((s1 < 300) && (s2 < 300) && (s3 > 300) && (s4 > 300) && (s5 < 300)) {
  MotorSpeed(255, 80);
}

// if Middle and both Right sensor detects black lines
if ((s1 < 300) && (s2 < 300) && (s3 > 300) && (s4 > 300) && (s5 > 300)) {
  MotorSpeed(255, 80);
}

// MIDDLE LEFT
// if Middle and Left sensor detects black lines
if ((s1 < 300) && (s2 > 300) && (s3 > 300) && (s4 < 300) && (s5 < 300)) {
  MotorSpeed(80, 250);
}

// if Middle and both left sensor detects black lines
if ((s1 > 300) && (s2 > 300) && (s3 > 300) && (s4 < 300) && (s5 < 300)) {
  MotorSpeed(80, 250);
}

// All black
if ((s1 > 300) && (s2 > 300) && (s3 > 300) && (s4 > 300) && (s5 > 300)) {
  MotorSpeed(0, 0);
}
//All White
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  MotorSpeed(0, 0);
}


////////////////// switch conditon ///////////////////////
// if
}
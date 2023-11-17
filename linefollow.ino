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
//********************3 Switch , Left Right Switch***********************//
#define sw1 2   // Switch 1
#define sw2 3   // Switch 2
#define sw3 11  // Switch 3
#define swr 12  // Switch Right
#define swl 13  // Switch Left

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
  pinMode(sw1, INPUT_PULLUP); 
  pinMode(sw2, INPUT_PULLUP); 
  pinMode(sw3, INPUT_PULLUP);
  pinMode(swr, INPUT_PULLUP);
  pinMode(swl, INPUT_PULLUP);
  
   Serial.begin(9600);

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
  
 void fowards ()
 {
  MotorSpeed(85, 80);
 }  



  void TurnRight ()
 {
  MotorSpeed(255,60);
 }  


  void TurnLeft ()
 {
  MotorSpeed(60, 250);
 }  


  void Stop ()
 {
  MotorSpeed(0, 0);
 }  


  void Gripper ()
 {
  MotorSpeed(85, 80);
 }  

 void automation (int s1, int s2, int s3, int s4, int s5)
 {
  // if only Middle Sensor detects a black line // forward with 2 motors
if ((s1 < 300) && (s2 < 300) && (s3 > 300) && (s4 < 300) && (s5 < 300)) {
  fowards ();
}

// RIGHT
// if only RIGHT Sensor detects a black line // turn right with left motor
if ((s1 < 300) && (s2 > 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  TurnRight ();
}

// if only Most RIGHT Sensor detects a black line // turn right with left motor
if ((s1 > 300) && (s2 < 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  TurnRight ();
}

// if Both RIGHT sensor detects a black line // turn right with left motor
if ((s1 > 300) && (s2 > 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  TurnRight ();
}

// LEFT
// if only LEFT sensor detects a black line // turn Left with right motor
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 > 300) && (s5 < 300)) {
 TurnLeft ();
}

// if only Most LEFT sensor detects a black line // turn left with right motor
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 < 300) && (s5 > 300)) {
  TurnLeft ();
}

// if only Both LEFT sensor detects a black line // turn left with right motor
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 > 300) && (s5 > 300)) {
  TurnLeft ();
}

// MIDDLE RIGHT LEFT

// MIDDLE RIGHT
// if Middle and Right sensor detects black lines
if ((s1 < 300) && (s2 < 300) && (s3 > 300) && (s4 > 300) && (s5 < 300)) {
  TurnRight ();
}

// if Middle and both Right sensor detects black lines
if ((s1 < 300) && (s2 < 300) && (s3 > 300) && (s4 > 300) && (s5 > 300)) {
  TurnRight ();
}

// MIDDLE LEFT
// if Middle and Left sensor detects black lines
if ((s1 < 300) && (s2 > 300) && (s3 > 300) && (s4 < 300) && (s5 < 300)) {
  TurnLeft ();
}

// if Middle and both left sensor detects black lines
if ((s1 > 300) && (s2 > 300) && (s3 > 300) && (s4 < 300) && (s5 < 300)) {
  TurnLeft ();
}

// All black
if ((s1 > 300) && (s2 > 300) && (s3 > 300) && (s4 > 300) && (s5 > 300)) {
  Stop ();
}
//All White
if ((s1 < 300) && (s2 < 300) && (s3 < 300) && (s4 < 300) && (s5 < 300)) {
  Stop ();
}
 }
 
void loop() {
  // Reading Sensor Values
   int s1 = analogRead(ir1);   // Left Most Sensor
   int s2 = analogRead(ir2);   // Left Sensor
   int s3 = analogRead(ir3);   // Middle Sensor
   int s4 = analogRead(ir4);   // Right Sensor
   int s5 = analogRead(ir5);   // Right Most Sensor
   int s6 = digitalRead(sw1);  // Switch 1
   int s7 = digitalRead(sw2);  // Switch 2
   int s8 = digitalRead(sw3);  // Switch 3
   int s9 = digitalRead(swr);  // Switch Right
   int s10 = digitalRead(swl); // Switch Left

 
 
 ///// condition 1 : press 1/////
 if((s6 == 0) && (s7 == 1) && (s8 == 1))
 {
    automation(s1,s2,s3,s4,s5);
 }

 ///// condition 1 : press 1/////
 if((s6 == 1) && (s7 == 0) && (s8 == 1))
 {
  automation(s1,s2,s3,s4,s5);
 }

  ///// condition 1 : press 1/////
 if((s6 == 1) && (s7 == 1) && (s8 == 0))
 {
  automation(s1,s2,s3,s4,s5);
 }


 
char buff[99]; // Fix: Use square brackets for array declaration
  sprintf(buff, "Switch 1: %d, Switch 2: %d Switch 3: %d, Right Switch: %d, Left Switch: %d", digitalRead(2),digitalRead(11),digitalRead(3),digitalRead(12),digitalRead(13));
  Serial.println(buff);

}
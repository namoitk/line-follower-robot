void setup() 
{
  Serial.begin(9600);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
}


void loop() {
  char buff[99]; // Fix: Use square brackets for array declaration
  sprintf(buff, "Switch 1: %d, Switch 2: %d Switch 3: %d, Switch 4: %d", digitalRead(12),digitalRead(2),digitalRead(11),digitalRead(3)); // Fix: Use sprintf correctly
  
  Serial.println(buff);
 
}
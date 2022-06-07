const int motorR1 = 6;
const int motorR2 = 5;
const int motorL1 = 11;
const int motorL2 = 10;

void setup() {
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  
  Serial.begin(38400);
}

String lastState;
void loop() {
 String textString;
 
 while (Serial.available() > 0) {
    delay(3);
    int text = Serial.read();
    textString += text;
 }
 
 if (textString != "") {
   lastState = textString;
 }
  
 if (lastState == "128128248") {
  forward();
 } else if (lastState == "1280248") {
  backward();
 } else if (lastState == "0248248") {
  left();
 } else if (lastState == "120248248") {
  right();
 } else {
  stopM();
 }
 
}

void forward(){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
}

void backward(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
}

void right(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
}

void left(){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
}

void stopM(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
}

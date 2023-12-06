//This code makes a robot write "LOVE" in Morse code
int dot = 300;
int line = 500;
int dot_line = 400; //transition from dot to line
int pause = 1000;

void setup() {
pinMode(3, OUTPUT);
pinMode(9, OUTPUT); 
pinMode(10, OUTPUT); 
pinMode(11, OUTPUT); 
}

void loop() {
  delay(3000);

  //one dot
  rightBkwd();
  delay(dot);
  allStop();
  delay(dot_line); //pause to go from dot to line

  //one line
  rightBkwd();
  leftBkwd();
  delay(line);
  allStop();
  delay(dot_line);

  //two dots
  rightFwd();
  delay(dot);
  allStop();
  leftFwd();
  delay(dot);
  allStop();
  delay(dot_line);

  //three lines
  rightFwd();
  leftFwd();
  delay(line);
  allStop();
  rightBkwd();
  leftBkwd();
  delay(line);
  allStop();
  rightFwd();
  leftFwd();
  delay(line);
  allStop();
  delay(dot_line);

  //three dots
  rightFwd();
  delay(dot);
  allStop();
  leftFwd();
  delay(dot);
  allStop();
  rightFwd();
  delay(dot);
  allStop();
  delay(dot_line);

  //one line
  rightFwd();
  leftFwd();
  delay(line);
  allStop();
  delay(dot_line);

  //one dot
  rightBkwd();
  delay(dot);
  allStop();


}

//right wheel turns backward
void rightBkwd (){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
}

//left wheel turns forward
void leftFwd (){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
}


//right wheel turns forward
void rightFwd (){
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}

//left wheel turns backward 
void leftBkwd (){
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}

//both wheels stop
void allStop (){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
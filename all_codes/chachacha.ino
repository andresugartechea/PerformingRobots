#include <Adafruit_NeoPixel.h>

void setup() {

  //motor for right wheel
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  //motor for left wheel
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {

  // moves forward
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(500); // let it turn for 3 seconds

  //cha-cha-cha
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(170); // let it turn for 3 seconds
  //////
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(170); // let it turn for 3 seconds
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(170); // let it turn for 3 seconds
  //////
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(170); // let it turn for 3 seconds


  //moves  backwards
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(500);


  //cha-cha-cha
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(500); // let it turn for 3 seconds
  //////
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(170); // let it turn for 3 seconds
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(170); // let it turn for 3 seconds
  //////
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(170); // let it turn for 3 seconds
}


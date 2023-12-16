#include <Servo.h>

Servo neck;  // create servo object to control a servo

Servo body;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos_body = 40;    // variable to store the servo position SERVOMOTOR1

void setup() {
  body.attach(18);  // pin for servomotor that controls body
  neck.attach(17);  // pin for servomotor that controls body

}

void loop() {
  move_body();

}

void move_body() {
  if (pos_body>20){
    body.write(20);
    delay(30);
  }
  for (pos_body = 20; pos_body <= 60; pos_body += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    body.write(pos_body);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos_body = 60; pos_body >= 20; pos_body -= 1) { // goes from 180 degrees to 0 degrees
    body.write(pos_body);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }

  
  if (pos_body>20){
    body.write(20);
    delay(30);
  }
  for (pos_body = 20; pos_body <= 60; pos_body += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    body.write(pos_body);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos_body = 60; pos_body >= 20; pos_body -= 1) { // goes from 180 degrees to 0 degrees
    body.write(pos_body);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}
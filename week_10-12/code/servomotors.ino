#include <Servo.h>

Servo body;  // create servo object to control a servo
Servo neck;
// twelve servo objects can be created on most boards

int pos_body = 40;    // variable to store the servo position SERVOMOTOR1
int pos_head = 0;

void setup() {
  body.attach(18);  // pin for servomotor that controls body
  neck.attach(17);  //pin for servomotor that controls neck
}

void loop() {
  neck.write(0);
  //delay(5000);
  body.write(40);
  delay(5000);

  
  neck.write(20);
  //delay(5000);
  body.write(60);
  delay(5000);

}


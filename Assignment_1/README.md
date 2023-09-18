# Assignment 1 | First Robot

## Date: 9/12/2023:

For this first assignment, I teamed up with Ryan Wu. We based the concept of our first robot on the [_"larva"_ masks](https://www.nakupelle.com/masks/Resources/larvals1.gif), which are used in theater to make the audience focus on the moves of the actors rather than on their facial expressions. We took an ironic take by not adding any body extremity, so our robot is only a giant _"larva"_ face. 

<img src="IMG_2031.PNG" width ="375" /> <img src="IMG_2032.PNG" width ="375" />

## Date: 9/18/2023:

This week, my teammate and I constructed the base for our robot. 

<img src="base1.jpg" height ="275" /> <img src="base2.jpg" height ="275" /> <img src="base3.jpg" height ="275" />

To make the motors move, I used [Prof. Michael Shiloh's code](https://github.com/michaelshiloh/PerformingRobots/blob/master/lectureNotes.md#todays-lecture) shown in his class _Performing Robots_.

```
void setup() {
  // Pins 2 and 3 are connected to In1 and In2 respectively
  // of the L298 motor driver
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // make the motor turn in one direction
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(5000); // let it turn for 5 seconds

  // now reverse direction
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(5000);
}

```

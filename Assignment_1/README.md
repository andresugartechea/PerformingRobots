# Assignment 1 | First Robot

## Date: 9/13/2023:

For this first assignment, I teamed up with Ryan Wu. We based the concept of our first robot on the [_"larva"_ masks](https://www.nakupelle.com/masks/Resources/larvals1.gif), which are used in theater to make the audience focus on the moves of the actors rather than on their facial expressions. We took an ironic take by not adding any body extremity, so our robot is only a giant _"larva"_ face. 

<img src="IMG_2031.PNG" width ="375" /> <img src="IMG_2032.PNG" width ="375" />

## Date: 9/18/2023:

This week, my teammate and I constructed the base for our robot. The instructions were straightforward, so the only complication that we found was how slow we were doing things since it had been a while since we had used power tools. 

<img src="base1.jpg" height ="275" /> 

It was Ryan's first time soldering, so in order to practice and get familiar with the tools, he was in charge of soldering extension cables for our wires.

<img src="base2.jpg" height ="275" /> 

This is how our base looks thus far:

<img src="base3.jpg" height ="275" />

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
### Response to _Chapter 7: Machines/Mechanicals_ from the book _Entangled: Technology and the Transformation of Performance_ by Chris Salter

Chapter 7 of Chris Salter's book explores machine performance with some intriguing aspects that captivated my attention. Firstly, the concept of the Survival Research Lab's perception of machine performance challenged my view of machines as lifeless tools by offering a deep perspective on human's relationship with technology. The Lab's works respond to the idealized visions of technology from the past, placing it in the context of modern warfare technology. The Lab's standpoint was ambiguous since it was not clear whether it praises or criticizes post-industrial systems, but it's reflective of our ambivalence towards progress. Secondly, the chapter also explores the relatability of humans to robots, highlighting that it's through behavioral aspects and not appearance that we find a connection to technology. This idea extends to non-anthropomorphic robots like Wall-E, showcasing how actions and perceived emotions resonate with audiences. This concept applies to various mediums, emphasizing the importance of intentions behind creations in storytelling.

In conclusion, these aspects prompt us to reevaluate our relationship with technology and performance. They encourage experimentation in technology-driven art, highlighting the significance of actions and intentions. Salter's exploration urges us to examine our role in the post-industrial era's machinery and its impact on our perceptions of the mechanical and digital.

## Date: 9/20/2023:

<img src="base4.jpg" height ="275" /> 

<img src="base5.jpg" height ="275" /> 

```
void setup() {
  //right wheel
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  //left wheel
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // going forward
  
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


  // going backward
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
```

## Date: 9/25/2023:


To make the robot write "LOVE" in Morse code. 

```
int dot = 300;
int line = 500;
int dot_line = 400;
int pause = 1000;

void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT); 
pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
}

void loop() {
  delay(3000);
  // //"I"
  // rightFwd();
  // delay(dot);
  // allStop();
  // leftFwd();
  // delay(dot);
  // allStop();

  // //
  // delay(pause);
  // //

  // //////// I - "love"

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
```

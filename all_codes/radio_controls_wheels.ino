/*
   Minimal decoding of multiple RC channels using pin change interrupts

   Does not check for reasonable values or timeouts

   Based on https://ryanboland.com/blog/reading-rc-receiver-values

  change log

  02 may 2022 - ms - initial entry
  24 may 2022 - ms - changed RC_CHx_PIN names
  15 sep 2022 - ms - changed pin numbers to new assignments


  Important information to set up:

  Radio Channel - Arduino Pin
  1-7
  2-6
  3-5
  4-4

  Arduino Pin - Motor Pin (left to right)
  - Right wheel
  3-3
  10-4
  - Left wheel
  9-2
  11-1


*/


// install this library from the library manager
// by Mike "GreyGnome" Schwager
#include <EnableInterrupt.h>

#define SERIAL_PORT_SPEED 9600
#define RC_NUM_CHANNELS  4

#define RC_CH1  0
#define RC_CH2  1
#define RC_CH3  2
#define RC_CH4  3

#define RC_CH1_PIN  7
#define RC_CH2_PIN  6
#define RC_CH3_PIN  5
#define RC_CH4_PIN  4

//Left wheel
#define motors_1 11
#define motors_2 9

//Right wheel
#define motors_3 3
#define motors_4 10

uint16_t rc_values[RC_NUM_CHANNELS];
uint32_t rc_start[RC_NUM_CHANNELS];
volatile uint16_t rc_shared[RC_NUM_CHANNELS];

void rc_read_values() {
  noInterrupts();
  memcpy(rc_values, (const void *)rc_shared, sizeof(rc_shared));
  interrupts();
}

void calc_input(uint8_t channel, uint8_t input_pin) {
  if (digitalRead(input_pin) == HIGH) {
    rc_start[channel] = micros();
  } else {
    uint16_t rc_compare = (uint16_t)(micros() - rc_start[channel]);
    rc_shared[channel] = rc_compare;
  }
}

void calc_ch1() {
  calc_input(RC_CH1, RC_CH1_PIN);
}
void calc_ch2() {
  calc_input(RC_CH2, RC_CH2_PIN);
}
void calc_ch3() {
  calc_input(RC_CH3, RC_CH3_PIN);
}
void calc_ch4() {
  calc_input(RC_CH4, RC_CH4_PIN);
}

///// To control each wheel

void LW_forward() { //Left Wheel Forward
  digitalWrite(motors_1, HIGH);
  digitalWrite(motors_2, LOW);
}

void LW_reverse() { // Left Wheel Reverse
  digitalWrite(motors_1, LOW);
  digitalWrite(motors_2, HIGH);
}

void RW_forward() { // delayy controls angle to turn
  digitalWrite(motors_3, LOW);
  digitalWrite(motors_4, HIGH);
}

void RW_reverse() { // delayy controls angle to turn
  digitalWrite(motors_3, HIGH);
  digitalWrite(motors_4, LOW);
}

///// To move

void stop() {
  digitalWrite(motors_1, LOW);
  digitalWrite(motors_2, LOW);
  digitalWrite(motors_3, LOW);
  digitalWrite(motors_4, LOW);
}

void back() {
  RW_reverse();
  LW_reverse();
  Serial.println("BACK");
}
void front() {
  RW_forward();
  LW_forward();
  Serial.println("FRONT");
}
void turn_left() { // delayy controls angle to turn
  LW_forward();
  RW_reverse();
  Serial.println("RIGHT");

}
void turn_right() { // delayy controls angle to turn
  LW_reverse();
  RW_forward();
  Serial.println("LEFT");
}



void setup() {
  Serial.begin(SERIAL_PORT_SPEED);

  pinMode(RC_CH1_PIN, INPUT);
  pinMode(RC_CH2_PIN, INPUT);
  pinMode(RC_CH3_PIN, INPUT);
  pinMode(RC_CH4_PIN, INPUT);

  enableInterrupt(RC_CH1_PIN, calc_ch1, CHANGE);
  enableInterrupt(RC_CH2_PIN, calc_ch2, CHANGE);
  enableInterrupt(RC_CH3_PIN, calc_ch3, CHANGE);
  enableInterrupt(RC_CH4_PIN, calc_ch4, CHANGE);

  pinMode(motors_1, OUTPUT);
  pinMode(motors_2, OUTPUT);
  pinMode(motors_3, OUTPUT);
  pinMode(motors_4, OUTPUT);
  stop();
}



void loop() {
  rc_read_values();


  Serial.print("CH1:"); Serial.print(rc_values[RC_CH1]); Serial.print("\t");
  Serial.print("CH2:"); Serial.print(rc_values[RC_CH2]); Serial.print("\t");
  Serial.print("CH3:"); Serial.print(rc_values[RC_CH3]); Serial.print("\t");
  Serial.print("CH4:"); Serial.println(rc_values[RC_CH4]);

  // use whichever channel is the trigger to control forward and reverse movement
  if (rc_values[RC_CH2] > 1600) front();
  else if (rc_values[RC_CH2] < 1400) back();
  else if (rc_values[RC_CH1] > 1600) turn_left();
  else if (rc_values[RC_CH1] < 1400) turn_right();
  else if ((rc_values[RC_CH1] < 1600) && (rc_values[RC_CH1] > 1400) && (rc_values[RC_CH2] < 1600) && (rc_values[RC_CH2] > 1400)) stop();


  delay(200);
}
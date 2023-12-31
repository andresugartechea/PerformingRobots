# WEEK 6 | Oct, 2 & 4

## Date: 10/2/2023 |

For this week's assignment, I continued working with Fatema to get our robot working with the hobby RC remote control. We verified that we can control the numbers displayed for all four radio channels. This list will remind us what Arduino pin corresponds to each radio channel:

(Radio Channel - Arduino Pin)<br>
(1 - 7)<br>
(2 - 6)<br>
(3 - 5)<br>
(4 - 4)

Then, we reconnected the L298 H-bridge to the Arduino. Finally, we implemented this code given by our professor to connect the values from the radio channels to the motors: 

```
// use whichever channel is the trigger to control forward and reverse movement
if (rc_values[RC_CH3] > 17) reverse();
if (rc_values[RC_CH3] < 13) forward();
if ((rc_values[RC_CH3] < 17) && (rc_values[RC_CH3] < 13)) stop();

// use whichever channel is the steering wheel to turn:
if (rc_values[RC_CH2] > 18) turnRight();
```

You can click [here to see the Arduino code](code/radio_controls_wheels.ino), and [here to watch on YouTube](https://www.youtube.com/shorts/7YG41S5zT0k) how it looks in real life!


## Date: 10/4/2023 |

I went back to work with Ryan due to some confusion with the robots assigned to each group. Nobody was working on our robot before, so we were a bit behind. During class, we finished soldering the H-bridge and paired the hobby RC transmitter. However, the motors were not moving the way we wanted and the Music Maker Shield was not able to play our songs. 

The potential solutions to test next week are to verify that the Arduino pins are accurately written on the code, and to try a different SD for the Music Maker Shield.
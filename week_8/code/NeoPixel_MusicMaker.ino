#define PIN 31

//Libraries NeoPixel
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

//Libraries Music Maker Shield
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif


// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

//Music Player Declaration
Adafruit_VS1053_FilePlayer musicPlayer = 
  // create breakout-example object!
  // Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
  // create shield-example object!
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

//Matrix Declaration
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

int state;

void setup() {

  matrix.clear();
  //For Matrix
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);


  //For Music Maker
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test");

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));
  
   if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  }

  // list files
  printDirectory(SD.open("/"), 0);
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(1,1);

  // Timer interrupts are not suggested, better to use DREQ interrupt!
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
  
}

int x    = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);

  if (state == 0){
    matrix.clear();
    dr_letter();
    matrix.show();
    musicPlayer.playFullFile("/track001.mp3");
    Serial.println(F("Playing track 001"));
    state = 1;
    Serial.println(state);
  }

  if (state ==1){
    matrix.clear();
    dr_smile();
    matrix.show();
    musicPlayer.playFullFile("/track002.mp3");
    Serial.println(F("Playing track 002"));
    state = 2;
  }

  if (state ==2){
    matrix.clear();
    dr_triangle();
    matrix.show();
    musicPlayer.playFullFile("/track003.mp3");
    Serial.println(F("Playing track 003"));
    state = 0;
  }


  //For Music Maker Shield
    // File is playing in the background
  if (musicPlayer.stopped()) {
    Serial.println("Done playing music");
    while (1) {
      delay(10);  // we're done! do nothing...
    }
  }
  if (Serial.available()) {
    char c = Serial.read();
    
    // if we get an 's' on the serial console, stop!
    if (c == 's') {
      musicPlayer.stopPlaying();
    }
    
    // if we get an 'p' on the serial console, pause/unpause!
    if (c == 'p') {
      if (! musicPlayer.paused()) {
        Serial.println("Paused");
        musicPlayer.pausePlaying(true);
      } else { 
        Serial.println("Resumed");
        musicPlayer.pausePlaying(false);
      }
    }
  }

  delay(100);
}

void dr_smile(){
  matrix.fillCircle(4, 4, 3, YELLOW);
  matrix.drawPixel(2, 1,YELLOW);
  matrix.drawPixel(1, 2,YELLOW);
  matrix.drawPixel(3, 2, WHITE);
  matrix.drawPixel(5, 2, WHITE);
  matrix.drawPixel(2, 4, WHITE);
  matrix.drawPixel(6, 4, WHITE);
  matrix.drawLine(3, 5, 5, 5, WHITE);
}


void dr_triangle(){
  matrix.fillTriangle(0, 0, 4, 7, 7, 3, BLUE);
}

void dr_letter(){
  matrix.drawChar(1, 1, 'X', RED, BLACK, 1);
}



/// File listing helper
void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}



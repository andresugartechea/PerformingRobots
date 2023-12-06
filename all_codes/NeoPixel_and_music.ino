//Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 31

// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

//Matrix Declaration
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
}

int x    = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  dr_letter();
  //matrix.print(F("HOLA"));
  //if(--x < -36) {
  //  x = matrix.width();
  //  if(++pass >= 3) pass = 0;
  //  matrix.setTextColor(colors[pass]);
  //}
  matrix.show();
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



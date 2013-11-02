//Taken from http://arduino.cc/en/Reference/TFTText
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define SCLK 8
#define MOSI 9
#define CS   7
#define DC   10
#define RESET 11

Adafruit_ST7735 screen = Adafruit_ST7735(CS, DC, MOSI, SCLK, RESET);

void setup() {
  // initialize the screen
  //screen.begin(); begin() is only available when using TFT instead of Adafruit_ST7735
  //so we have to use the next two lines instead.
      screen.initR(INITR_REDTAB);
      screen.setRotation(1);

  // make the background black
  screen.background(255,255,255);

  // set the text color to white
  screen.stroke(0,0,0);

  // write text to the screen in the top left corner
  screen.text("Lorem ipsum dolor sit amet,", 0, 0);
  screen.text("consectetur adipisicing eli", 0, 6);
  screen.text("t, sed do eiusmod tempor ", 0, 12);
  screen.text("incididunt ut labore et", 0, 18);
  screen.text("dolore magna aliqua. Ut", 0, 24);
  screen.text("enim ad minim veniam,", 0, 30);
  screen.text("quis nostrud exercitation", 0, 36);
  screen.text("ullamco laboris nisi ut", 0, 42);
  screen.text("aliquip ex ea commodo.", 0, 48);
}

void loop() {
}

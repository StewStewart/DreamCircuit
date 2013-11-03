// include the library code:
#include <SPI.h>
#include <TFT.h>            // Arduino TFT library
// initialize the library with the numbers of the interface pins
#define SCLK 8
#define MOSI 9
#define CS   7
#define DC   10
#define RESET 11
 
const int trigPin = 12;
const int echoPin = 13;

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
  screen.text("Ultrasonic Sensor Test", 0, 0);
  screen.text("With 1602 Character LCD", 0, 12);
  screen.text("[cm]", 20, 24);
  screen.text("[in]", 20, 36);
  
}
void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
 
// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
 
// The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // HIGH신호의 주기를 거리로 변환
  inches = microsecondsToInches(duration); 
  cm = microsecondsToCentimeters(duration);
  
  screen.stroke(0,0,0);
  screen.setCursor(0, 24);
  screen.print(cm);
  screen.setCursor(0, 36);
  screen.print(inches);
  
  delay(100);
  
  screen.stroke(255,255,255);
  screen.setCursor(0, 24);
  screen.print(cm);
  screen.setCursor(0, 36);
  screen.print(inches);

}
 
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

/*
Revised Arduino Example code by dreamcircuit arduino team
Added 1602 LCD to print Motor RPM
*/

#include <LiquidCrystal.h>
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 9,10,11,12);
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  lcd.begin(16, 2); // define lcd matrix
  lcd.setCursor(1, 0); // define below message's start point
  lcd.print("Stepping Motor");
  lcd.setCursor(0, 2);
  lcd.print("Speed: ");
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution/100);
  }
  lcd.setCursor(7, 2);
  // print motor rpm to lcd
  lcd.print(motorSpeed);
}

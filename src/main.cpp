/**
 * Pyroelectric Infrared Sensor (PIR Sensor)
 * 
 * Detect motions passing through the sensor.
 * 
 * @author: ElexParts<engineering@elexparts.com>
 * @url: https://www.elexparts.com
 * @license: MIT
 */

#include <Arduino.h>

int ledPin = 13;                // Output: LED indicator pin
int inputPin = 2;               // Input: PIR input pin
int pirState = LOW;             // PIR state (default)
int val = 0;                    // PIR read value
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
 
  Serial.begin(9600);
}
 
void loop() {
  val = digitalRead(inputPin);             // Read value from PIR sensor.
  if (val == HIGH) {                       // Turn on LED indicator if motion is detected.
    digitalWrite(ledPin, HIGH);
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);             // Turn off LED indicator after motion has ended.
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
#include "RailSwitch.h"

const int swPin1 = 25;
const int swPin2 = 26;
const int ledPin = 2;

RailSwitch s1(swPin1), s2(swPin2);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  s1.begin();
  s2.begin();
}
 
void loop(){
  if (s1.is_pushed()) {
    digitalWrite(ledPin, HIGH);
  }
  if (s2.is_pushed()) {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}

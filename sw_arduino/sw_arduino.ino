#include "RailSwitch.h"

const int swPin1 = 2;
const int swPin2 = 3;
const int ledPin = 4;

volatile RailSwitch s1(swPin1), s2(swPin2);

void on_int0() {
  s1.set_pushed();
}

void on_int1() {
  s2.set_pushed();
}

void setup() {
  s1.begin(&on_int0);
  s2.begin(&on_int1);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
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

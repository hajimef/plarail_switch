#include "RailSwitch.h"
#include <Arduino.h>

RailSwitch::RailSwitch(int _pin) {
  pin = _pin;
  delay = 1000;
}

RailSwitch::RailSwitch(int _pin, unsigned long _delay) {
  pin = _pin;
  delay = _delay;
}

void RailSwitch::begin(void (*func)(void)) {
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), func, FALLING);
}

void RailSwitch::set_pushed(void) {
  t = millis();  
  pushed = true;
}

void RailSwitch::reset_pushed(void) {
  t = 0;
  pushed = false;
}

bool RailSwitch::is_pushed(void) {
  unsigned long now;

  if (pushed) {
    now = millis();
    if (now - t < delay) {
      return true;
    }
    else {
      reset_pushed();
      return false;
    }
  }
  else {
    return false;
  }
}

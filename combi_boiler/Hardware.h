#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#include <Arduino.h>

void HWInit();
void HWRestart();
void HWLoop();
void HWSetPin(int pin, boolean state);

#endif /* ARDUINO_HARDWARE_H */

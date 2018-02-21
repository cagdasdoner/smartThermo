#include "Hardware.h"
#include "Global.h"

uint16_t hw_delay = 10;
uint16_t hw_init_done = false;

void SerialInit()
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setDebugOutput(true);
  delay(hw_delay);
}

void GPIOInit()
{
#ifdef USE_NODEMCU_BOARD
  pinMode(pinMap[0], OUTPUT);
  HWSetPin(pinMap[0], LOW);
#else
  pinMode(pinMap[6], OUTPUT);
  HWSetPin(pinMap[6], LOW);
#endif
  delay(hw_delay);
}

void HWInit()
{
  SerialInit();
  GPIOInit();
  hw_init_done = true;
}

void HWSetPin(int pin, boolean state)
{
#ifdef LOW_LEVEL_TRIGGER
  digitalWrite(pin, !state);
#else
  digitalWrite(pin, state);
#endif
}

void HWRestart()
{
  ESP.restart();
}

void HWLoop()
{

}

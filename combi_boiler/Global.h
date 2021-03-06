#ifndef ARDUINO_GLOBAL_H
#define ARDUINO_GLOBAL_H

#define Printf            Serial.printf
#define SERIAL_BAUD_RATE  9600

/* Board Definitions */
#define USE_NODEMCU_BOARD
//#define USE_GENERIC_ESP8266
//#define USE_ADAFRUIT_HUZZAH

/* Peripheral definitions */
#define LOW_LEVEL_TRIGGER

/* Buffer sizes */
#define LEN_IP_MAX          17 
#define LEN_SSID_MAX        32 
#define LEN_PASSPHRASE_MAX  64
#define LEN_TEMP_MAX        6

/* GPIO Definitions */
static const uint8_t pinMap[11] = {16, 5, 4, 0, 2, 14, 12, 13, 15, 3, 1};

#endif /* ARDUINO_GLOBAL_H */

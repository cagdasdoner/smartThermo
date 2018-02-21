#ifndef ARDUINO_CLOUDCONNECTOR_H
#define ARDUINO_CLOUDCONNECTOR_H

#include <Arduino.h>

#define THERMOSTAT_ADDRESS "/iot/data/thermostat"
#define COMBI_ADDRESS      "/iot/data/combi"
#define LIMIT_ADDRESS      "/iot/data/limit"

void    MQTTBegin();
void    MQTTLoop();
boolean MQTTConnected();
/* Switch to more friendly function names. */
boolean Publish(const char* topic, const char* payload);
boolean Subscribe(const char* topicToSubscribe);


#endif /* ARDUINO_CLOUDCONNECTOR_H */

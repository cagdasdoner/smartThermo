#ifndef ARDUINO_MQTTCONNECTOR_H
#define ARDUINO_MQTTCONNECTOR_H

#include <Arduino.h>

#define MQTT_TOPIC_THERMOSTAT "/iot/data/thermostat"
#define MQTT_TOPIC_COMBI      "/iot/data/combi"

void    MQTTBegin();
void    MQTTLoop();
boolean MQTTPublish(const char* topic, const char* payload);
boolean MQTTSubscribe(const char* topicToSubscribe);
boolean MQTTConnected();

#endif /* ARDUINO_MQTTCONNECTOR_H */

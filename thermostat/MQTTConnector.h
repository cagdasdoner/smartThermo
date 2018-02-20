#ifndef ARDUINO_MQTTCONNECTOR_H
#define ARDUINO_MQTTCONNECTOR_H

#include <Arduino.h>

#define MQTT_TOPIC_SENSOR  "/iot/data/sensor"
#define MQTT_TOPIC_RELAY   "/iot/data/relay"

void    MQTTBegin();
void    MQTTLoop();
boolean MQTTPublish(const char* topic, const char* payload);
boolean MQTTSubscribe(const char* topicToSubscribe);
boolean MQTTConnected();

#endif /* ARDUINO_MQTTCONNECTOR_H */

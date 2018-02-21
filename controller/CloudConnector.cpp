#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "CloudConnector.h"
#include "Global.h"
#include "Credentials.h"

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

boolean mqttInitCompleted = false;
String clientId = "IoTPractice-" + String(ESP.getChipId());

/* Incoming data callback. 
 * Received thermostat data need to be compared in this function.
 */
void dataCallback(char* topic, byte* payload, unsigned int length)
{
  char payloadStr[length + 1];
  memset(payloadStr, 0, length + 1);
  strncpy(payloadStr, (char*)payload, length);
  Printf("Data    : dataCallback. Topic : [%s]\n", topic);
  Printf("Data    : dataCallback. Payload : %s\n", payloadStr);

  if(strcmp(topic, THERMOSTAT_ADDRESS) == 0)
  {
    /* ATTENTION : temperature variable is converting to an integer. */
    String temperatureStr = payloadStr;
    /* Gathered temperature value as integer. */
    int temperature = temperatureStr.toInt();

    Printf("Gathered.%d\n", temperature);
  
    /*
     * Do your implementation below ! 
     * 
     * Gathered thermostat value need to be compared with given threshold/limit. 
     * For example : If read temperature value is greater than 29 degrees in C,
     *               combi(boiler) need to be disabled.
     * 
     * Need to publish control data to this topic : COMBI_ADDRESS
     * 
     * Send "on" to enable, "off" to disable the combi(boiler).
     * 
     * USAGE : Publish(DEVICE_MESSAGE_ADDRESS, DATA_TO_BE_SENT);
     */
           if(temperature > 29)
        Publish(THERMOSTAT_ADDRESS, "off");
       else
        Publish(THERMOSTAT_ADDRESS, "on");
  }
}

/* MQTT connector function. 
 * Subscribe to the related topic after connection has established.
 */
void performConnect()
{
  uint16_t connectionDelay = 5000;
  while (!mqttClient.connected())
  {
    Printf("Trace   : Attempting MQTT connection...\n");
    if (mqttClient.connect(clientId.c_str(), MQTT_USERNAME, MQTT_PASS))
    {
      Printf("Trace   : Connected to Broker.\n");
      
      /* 
       *  Do your implementation below ! 
       *  
       *  Need to Subscribe to this topic to read temperature: THERMOSTAT_ADDRESS
       *  
       *  With this subscription, we will receive temperature sensor values from thermostat!
       *  
       *  USAGE: Subscribe(DEVICE_MESSAGE_ADDRESS);
       */

      Subscribe(THERMOSTAT_ADDRESS);
    }
    else
    {
      Printf("Error!  : MQTT Connect failed, rc = %d\n", mqttClient.state());
      Printf("Trace   : Trying again in %d msec.\n", connectionDelay);
      delay(connectionDelay);
    }
  }
}

/* MQTT Publisher function. */
boolean Publish(const char* topic, const char* payload)
{
  boolean retval = false;
  if (mqttClient.connected())
  {
    retval = mqttClient.publish(topic, payload);
  }
  return retval;
}

/* MQTT Subscriber function. */
boolean Subscribe(const char* topicToSubscribe)
{
  boolean retval = false;
  if (mqttClient.connected())
  {
    retval = mqttClient.subscribe(topicToSubscribe);
  }
  return retval;
}

/* Gather MQTT status. */
boolean MQTTConnected()
{
  return mqttClient.connected();
}

/* Init MQTT process */
void MQTTBegin()
{
  mqttClient.setServer(MQTT_BROKER, MQTT_BROKER_PORT);
  mqttClient.setCallback(dataCallback);
  mqttInitCompleted = true;
}

/* Sustain broker connection. */
void MQTTLoop()
{
  if(mqttInitCompleted)
  {
    if (!MQTTConnected())
    {
      performConnect();
    }
    mqttClient.loop();
  }
}

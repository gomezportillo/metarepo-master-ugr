#include "PubSubClient.h"
#include <ESP8266WiFi.h>

// Pines del sensor de ultrasonidos
#define trigPin 5
#define echoPin 4

// Punto de acceso wifi al que se conecta el dispositivo
const char* ssid = "pedro";
const char* pass = "12345678";

// Parámetros del cloud
int status = WL_IDLE_STATUS;

char* topic = "channels/750774/publish/HK7IF32I1L1NINHA";
char* server = "mqtt.thingspeak.com";

WiFiClient wifiClient;
PubSubClient client(server, 1883, wifiClient);


void callback(char* topic, byte* payload, unsigned int length) 
{
  // handle message arrived
}

void setup()
{
  Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  String clientName = "ESP-Thingspeak-pedro";
  Serial.print("Connecting to ");
  Serial.print(server);
  Serial.print(" as ");
  Serial.println(clientName);

  if (client.connect((char*) clientName.c_str()))
  {
    Serial.println("Connected to MQTT broker");
    Serial.print("Topic is: ");
    Serial.println(topic);

    if (client.publish(topic, "hello from ESP8266"))
    {
      Serial.println("Publish ok");
    }
    else
    {
      Serial.println("Publish failed");
    }
  }
  else
  {
    Serial.println("MQTT connect failed");
    Serial.println("Will reset and try again...");
    abort();
  }
}

void loop()
{
  static int counter = 0;
  String payload = "field1=";
  payload += micros();
  payload += "&field2=";
  payload += counter;
  payload += "&status=MQTTPUBLISH";

  if (client.connected()) 
  {
    Serial.print("Sending payload: ");
    Serial.println(payload);

    if (client.publish(topic, (char*) payload.c_str())) 
    {
      Serial.println("Publish ok");
    }
    else {
      Serial.println("Publish failed");
    }
  }
  ++counter;
  delay(20000);
}

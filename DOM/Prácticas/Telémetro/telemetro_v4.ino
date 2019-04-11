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

char* topic = "Domotica";
char* server = "atcmqtt.ugr.es";

char mqttUser[] = "alumno";
char mqttPass[] = "atcatcatc";

WiFiClient wifiClient;
PubSubClient client(server, 1883, wifiClient);


void callback(char* topic, byte* payload, unsigned int length)
{
  // handle message arrived
}

void setup()
{
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);

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

  String clientName = "Pedro";
  Serial.print("Connecting to ");
  Serial.print(server);
  Serial.print(" as ");
  Serial.println(clientName);

  if (client.connect((char*) clientName.c_str(), mqttUser, mqttPass))
  {
    Serial.println("Connected to MQTT broker");
    Serial.print("Topic is: ");
    Serial.println(topic);

    if (client.publish(topic, "Hello wrold desde la ESP8266 de Pedro"))
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
    abort();
  }
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);

  // Medida de la distancia
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distancia = 0.0172 * pulseIn(echoPin, HIGH);

  // Visualización por el puerto serie
  Serial.print("Distancia: ");
  Serial.println(distancia);

  //Medida del rssi de la wifi
  float rssi = WiFi.RSSI();

  //  String message = "{'distance':" + distancia + "},{'rssi':" + rssi + "}";
  String message = String(distancia);

  if (client.connected())
  {
    Serial.print("Sending payload: ");
    Serial.println(message);

    if (client.publish(topic, (char*) message.c_str()))
    {
      Serial.println("Publish ok");
    }
    else {
      Serial.println("Publish failed");
    }
  }
  delay(20000);
}

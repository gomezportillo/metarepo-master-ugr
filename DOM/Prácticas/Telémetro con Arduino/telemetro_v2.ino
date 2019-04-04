#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
// Pines del sensor de ultrasonidos
#define trigPin 5
#define echoPin 4

// Punto de acceso wifi al que se conecta el dispositivo
char ssid[] = "pedro"; // your network SSID Name
char pass[] = "12345678"; // your network password

// Parámetros del cloud
int status = WL_IDLE_STATUS;
WiFiClient cliente;

unsigned long myChannelNumber = 750774; // your ThingSpeak Channel Number
const char * myWriteAPIKey = "HK7IF32I1L1NINHA"; // your ThingSpeak Write API Key

void setup()
{
  Serial.begin(9600);
  pinMode ( LED_BUILTIN, OUTPUT );
  pinMode ( trigPin, OUTPUT );
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  //Conexión a la WiFi y al cloud
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(cliente);
  delay(500);
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

  //Contrucción del mensaje y envío al cloud
  ThingSpeak.setField(1, rssi);
  ThingSpeak.setField(2, distancia);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(19500); //cada 20 segundos
}

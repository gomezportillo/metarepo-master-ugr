// Pines del sensor de ultrasonidos
 #define trigPin 5
 #define echoPin 4
 
void setup() 
{
 Serial.begin(9600);
 pinMode ( LED_BUILTIN, OUTPUT );
 pinMode ( trigPin, OUTPUT );
 pinMode(echoPin, INPUT);
 digitalWrite(trigPin, LOW);
}

void loop() 
{
 digitalWrite(LED_BUILTIN, HIGH);
 delay(500);
 digitalWrite(LED_BUILTIN, LOW);
 delay(500);
// Medida de la distancia
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 float distancia = 0.0172*pulseIn(echoPin, HIGH);
// Visualización por el puerto serie
 Serial.print("Distancia: ");
 Serial.println(distancia);
}

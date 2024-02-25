#include <Adafruit_Sensor.h>
#include <DHT.h>

#define LED1 15 // D15
#define LED2 2  // D2
#define LED3 4  // D4
#define DHT_PIN 16 // D16 (Pino do DHT11)
#define TOUCH_PIN 5 // D5 (Pino do sensor capacitivo)
#define REFLECTIVE_PIN 17 // D17 (Pino do sensor ótico reflexivo)

DHT dht(DHT_PIN, DHT11);

float lastHumidity = 0.0;
float lastTemperature = 0.0;
int lastReflectiveValue = 0;

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(TOUCH_PIN, INPUT); // Define o pino do sensor capacitivo como entrada
  pinMode(REFLECTIVE_PIN, INPUT); // Define o pino do sensor ótico reflexivo como entrada
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  dht.begin();
}

void loop() {
  // Sensor DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Sensor de toque capacitivo
  int touchValue = digitalRead(TOUCH_PIN);

  // Sensor ótico reflexivo
  int reflectiveValue = digitalRead(REFLECTIVE_PIN);

  // Exibe as leituras no monitor serial
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Temperature: ");
  Serial.print(temperature);
  Serial.print("C, Touch Value: ");
  Serial.print(touchValue);
  Serial.print(", Reflective Value: ");
  Serial.println(reflectiveValue);

  // Verifica o sensor DHT11 e pisque o LED1 se houver uma mudança significativa na temperatura
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);

  lastTemperature = temperature;

  // Verifique o sensor de toque capacitivo e acenda o LED2 se houver toque
  if (touchValue == HIGH) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  // Verifique o sensor ótico reflexivo e acenda o LED3 se houver objeto próximo
  if (reflectiveValue == LOW && lastReflectiveValue == HIGH) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  lastReflectiveValue = reflectiveValue;

  delay(1000); // Aguarde um segundo entre as leituras
}

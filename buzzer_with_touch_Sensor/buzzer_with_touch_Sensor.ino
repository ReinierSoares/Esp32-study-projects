

int touch = 16;  // pin for touch sensor
int ledPin = 2; // pin for the LED
const int buzzerPin = 17;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(touch, INPUT);
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin); // Desligue o buzzer no início
}

void loop() {
  int touchValue = digitalRead(touch);
  if (touchValue == HIGH){
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000); // Frequência de 1000 Hz
    delay(1000); // Mantenha o som ativado por 1 segundo
    noTone(buzzerPin); // Desligue o buzzer
    Serial.println("touched");
  }
  else{
    digitalWrite(ledPin,LOW);
    Serial.println("not touched");
  }
  delay(500);

}
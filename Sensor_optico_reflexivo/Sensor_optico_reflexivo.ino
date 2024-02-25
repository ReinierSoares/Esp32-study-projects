int pinLed = 17; // led conectado no pino digital 12
int pinSensor = 16; // fototransistor conectado no pino digial 2
   
void setup(){ 
  pinMode(pinSensor, INPUT); // define como entrada 
  pinMode(pinLed, OUTPUT); // definoe como saída   
  digitalWrite(pinLed, LOW); // led incia apagado
}  
   
void loop(){
  if (digitalRead(pinSensor) == LOW){ // se for LOW 
        digitalWrite(pinLed, HIGH); // acende o led
  }else{ // caso contrário
        digitalWrite(pinLed, LOW); // apaga o led
  }    
}
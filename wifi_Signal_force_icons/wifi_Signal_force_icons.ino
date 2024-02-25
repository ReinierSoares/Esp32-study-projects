#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <ArduinoJson.h> // Instale esta biblioteca via Gerenciador de Bibliotecas Arduino

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "Perola-5G";
const char* password = "18012217";

 unsigned char wifi1_icon16x16[] =
{
	0b00000000, 0b00000000, //                 
	0b00000111, 0b11100000, //      ######     
	0b00011111, 0b11111000, //    ##########   
	0b00111111, 0b11111100, //   ############  
	0b01110000, 0b00001110, //  ###        ### 
	0b01100111, 0b11100110, //  ##  ######  ## 
	0b00001111, 0b11110000, //     ########    
	0b00011000, 0b00011000, //    ##      ##   
	0b00000011, 0b11000000, //       ####      
	0b00000111, 0b11100000, //      ######     
	0b00000100, 0b00100000, //      #    #     
	0b00000001, 0b10000000, //        ##       
	0b00000001, 0b10000000, //        ##       
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
};

 unsigned char wifi2_icon16x16[] =
{
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
	0b00000111, 0b11100000, //      ######     
	0b00001111, 0b11110000, //     ########    
	0b00011000, 0b00011000, //    ##      ##   
	0b00000011, 0b11000000, //       ####      
	0b00000111, 0b11100000, //      ######     
	0b00000100, 0b00100000, //      #    #     
	0b00000001, 0b10000000, //        ##       
	0b00000001, 0b10000000, //        ##       
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
};

 unsigned char cancel_icon16x16[] =
{
	0b00000000, 0b00000000, //                 
	0b00000000, 0b00000000, //                 
	0b00111000, 0b00001110, //   ###       ### 
	0b00111100, 0b00011110, //   ####     #### 
	0b00111110, 0b00111110, //   #####   ##### 
	0b00011111, 0b01111100, //    ##### #####  
	0b00001111, 0b11111000, //     #########   
	0b00000111, 0b11110000, //      #######    
	0b00000011, 0b11100000, //       #####     
	0b00000111, 0b11110000, //      #######    
	0b00001111, 0b11111000, //     #########   
	0b00011111, 0b01111100, //    ##### #####  
	0b00111110, 0b00111110, //   #####   ##### 
	0b00111100, 0b00011110, //   ####     #### 
	0b00111000, 0b00001110, //   ###       ### 
	0b00000000, 0b00000000, //                 
};

const unsigned char bitmap_icon_3dcube [] PROGMEM = {
  0x00, 0x00, 0xC0, 0x0F, 0x00, 0x10, 0x80, 0x27, 0x00, 0x48, 0x00, 0x53, 
  0x60, 0x54, 0xE0, 0x54, 0xE0, 0x51, 0xE0, 0x43, 0xE0, 0x03, 0x50, 0x00, 
  0xF8, 0x00, 0x04, 0x01, 0xFE, 0x03, 0x00, 0x00, };

void setup() {
  Serial.begin(115200);

  // Inicializa a comunicação com a tela OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Limpa a tela
  display.clearDisplay();

  // Exibe o ícone inicial
  display.drawBitmap(0, 0, cancel_icon16x16, 16, 16, SSD1306_WHITE);

  display.drawBitmap(0, 20, bitmap_icon_3dcube, 16, 16, SSD1306_WHITE);
  display.display();

    // Inicializa a conexão WiFi

  connectToWiFi();
}


void loop() {
  int signalStrength = WiFi.RSSI();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);


  if (WiFi.status() == WL_CONNECTED) {
    if (signalStrength > -50) {
      display.drawBitmap(0, 0, wifi1_icon16x16, 16, 16, SSD1306_WHITE);
        display.setCursor(0, 20);
      display.println(signalStrength);
    }  else {
      display.drawBitmap(0, 0, wifi2_icon16x16, 16, 16, SSD1306_WHITE); // Pode ajustar este para um ícone específico se preferir
        display.setCursor(0, 20);
      display.println(signalStrength);
    }
  } else {
    display.drawBitmap(0, 0, cancel_icon16x16, 16, 16, SSD1306_WHITE);
    display.setCursor(0, 20);
    display.println(signalStrength);
  }
  display.display();
  delay(3000);
}


void connectToWiFi() {
  Serial.println("Conectando ao WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Tentando conectar ao WiFi...");
  }

  Serial.println("Conectado ao WiFi!");
}


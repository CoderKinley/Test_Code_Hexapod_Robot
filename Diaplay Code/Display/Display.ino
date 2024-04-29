#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_WIDTH 128 // OLED display width,  in pixels
#define OLED_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000); // wait for initializing
  oled.setCursor(0, 0);
}

void loop() {
  oled.clearDisplay(); // clear display
  oled.setTextSize(1.5);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);        // position to display
  oled.println("Hello Kinley!!"); // text to display
  oled.display();        
  delay(2000);

  oled.clearDisplay();
  oled.drawCircle(30, 35, 20, WHITE);
  oled.drawCircle(90, 35, 20, WHITE);
  oled.display();
  delay(2000);  

  oled.clearDisplay();
  oled.fillCircle(30, 35, 20, WHITE);
  oled.fillCircle(90, 35, 20, WHITE);
  oled.display();
  delay(100);

  oled.clearDisplay();
  oled.drawCircle(30, 25, 20, WHITE);
  oled.drawCircle(90, 25, 20, WHITE);
  oled.display();
  delay(2000);  

  oled.clearDisplay();
  oled.drawCircle(30, 45, 20, WHITE);
  oled.drawCircle(90, 45, 20, WHITE);
  oled.display();
  delay(2000);  

  oled.clearDisplay();
  oled.drawCircle(30, 35, 20, WHITE);
  oled.drawCircle(90, 35, 20, WHITE);
  oled.display();
  delay(2000);  
  
  oled.clearDisplay();
  oled.fillCircle(30, 35, 20, WHITE);
  oled.fillCircle(90, 35, 20, WHITE);
  oled.display();
  delay(100);

  // draw triangle
  // oled.clearDisplay();
  // oled.drawTriangle(30, 60, 40, 80, 50, 60, WHITE);
  // oled.drawTriangle(70, 60, 80, 80, 90, 60, WHITE);
  // oled.display();
  // delay(20000);

  // // fill triangle
  // oled.clearDisplay();
  // oled.fillTriangle(30, 15, 0, 60, 60, 60, WHITE);
  // oled.display();
  // delay(2000);
}

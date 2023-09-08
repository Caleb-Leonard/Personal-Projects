//Author: Caleb Leonard 
//Project: QT PY Watch

#include <SPI.h>
#include <Wire.h>
#include <Time.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_TestBed.h>
#include <splash.h>

#define DEFAULT_I2C_PORT &WIRE

#define NUMPIXELS 1 
#define NEOPIXEL_PIN 2
#define NEOPIXEL_POWER 8

#define tiltSwitch 4

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3D

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(115200);
#if defined(NEOPIXEL_POWER)
  pinMode(NEOPIXEL_POWER, OUTPUT);
  digitalWrite(NEOPIXEL_POWER, HIGH);
#endif

pinMode(tiltSwitch, INPUT);

   pixels.begin();
   pixels.setBrightness(15);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(tiltSwitch, HIGH);
  tiltSwitch = digitalRead(4);

  if (tiltSwitch == LOW) {
  while (tiltSwitch == LOW) { 
    powerCycle();
  }
  
  } 
  else {
    while (tiltSwitch == HIGH) { 
      drawTimeDate();
  }
  
}

void powerCycle(void) {
  pixels.fill(0xFF0000);
  pixels.show();
  delay(500);

  pixels.fill(0x000000);
  pixels.show();
  delay(500);
  
  esp_sleep_enable_timer_wakeup(9000);
  esp_light_sleep_start();
  delay(1000);
  
  pixels.fill(0x00FF00);
  pixels.show();
  delay(500);

  pixels.fill(0x000000);
  pixels.show();
  delay(500);
  
}

void drawTimeDate(void) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor (SSD1306_WHITE);
  display.setCursor(63,15);
  display.print(F(hour());
  display.print(F(":"));
  display.print(F(minute());

 
  display.setCursor(67,15);
  display.print(F(monthStr(month());
  display.print(F(" "));
  display.print(F(dayStr(weekday());
  display.print(F(", "));
  display.print(F(year());
}

void I2CAddressBook(void){

  
}

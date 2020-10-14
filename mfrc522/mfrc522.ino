/*
 * 
 * All the resources for this project: https://randomnerdtutorials.com/
 * Modified by Rui Santos
 * 
 * Created by FILIPEFLOP
 * 
 */
 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define LOGO_HEIGHT 64
#define LOGO_WIDTH 128 
static const unsigned char PROGMEM logo_bmp[] =
{ 
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x01,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0f,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x3f,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0xff,0xff,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x03,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x07,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x0f,0xff,0xff,0xff,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x1f,0xff,0xe0,0x0f,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x7f,0xff,0x80,0x03,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x7f,0xff,0x00,0x00,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0xff,0xfc,0x00,0x00,0x7f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x01,0xff,0xf8,0x00,0x00,0x3f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x03,0xff,0xf0,0x00,0x00,0x1f,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x07,0xff,0xf0,0x00,0x00,0x0f,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x07,0xff,0xe0,0x78,0x1e,0x0f,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x0f,0xff,0xe0,0x7c,0x3f,0x07,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x0f,0x8f,0xc0,0xfc,0x3f,0x07,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1f,0x07,0xc0,0x7c,0x1f,0x07,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1f,0x07,0xc0,0x38,0x1e,0x03,0xf1,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x3e,0x03,0xc0,0x00,0x00,0x03,0xe0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x3f,0x03,0xc0,0x00,0x00,0x03,0xe0,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x3f,0x07,0xc3,0x00,0x00,0xc3,0xe0,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7c,0x03,0xc3,0x00,0x00,0xc3,0xe0,0xf8,0x00,0x7c,0x03,0xc3,0xf0,0x30,0x70,0x00,
  0x78,0x01,0xc2,0x00,0x00,0x43,0xe0,0x78,0x00,0xcf,0x0f,0xe6,0x00,0x70,0xfc,0x00,
  0x78,0x00,0x43,0x00,0x00,0xc7,0xc0,0x18,0x00,0xc1,0x18,0x36,0x00,0x71,0x8c,0x00,
  0x78,0x00,0x01,0x00,0x00,0x87,0x00,0x18,0x00,0xc1,0x98,0x06,0x00,0xd1,0x04,0x00,
  0x78,0x00,0x01,0x80,0x01,0x84,0x00,0x0c,0x00,0xc1,0x90,0x07,0xe1,0x91,0x06,0x00,
  0x7c,0x30,0x00,0x80,0x03,0x00,0x00,0x1c,0x00,0xc1,0x90,0x06,0x33,0x13,0x06,0x00,
  0x7e,0x7c,0x00,0x60,0x06,0x00,0x0c,0x1c,0x00,0xc1,0x90,0x00,0x12,0x11,0x06,0x00,
  0x7f,0xff,0x00,0x30,0x1c,0x00,0x3e,0x3c,0x00,0xc1,0x98,0x10,0x17,0xfd,0x04,0x00,
  0x7f,0xff,0xc0,0x0f,0xf0,0x00,0xff,0xfc,0x00,0xc3,0x18,0x34,0x30,0x31,0x8c,0x00,
  0x7f,0xff,0xe0,0x00,0x00,0x03,0xff,0xfc,0x00,0xcf,0x0f,0xe7,0xf0,0x10,0xfc,0x00,
  0x7f,0xff,0xf8,0x00,0x00,0x0f,0xff,0xfc,0x00,0xfc,0x03,0xc3,0xc0,0x10,0x70,0x00,
  0x7f,0xff,0xfe,0x00,0x00,0x3f,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0x80,0x00,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xe0,0x07,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0xd0,0x03,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7f,0xff,0xff,0x04,0x00,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x3f,0xff,0xfc,0x01,0x00,0x3f,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x3f,0xff,0xf0,0x01,0xc0,0x0f,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x3f,0xdf,0xc0,0x0f,0xe0,0x03,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1f,0x87,0x00,0x3f,0xf8,0x01,0xc3,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1f,0x00,0x00,0xff,0xfe,0x00,0x01,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x0f,0x00,0x01,0xff,0xff,0x80,0x01,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x0f,0x00,0x07,0xff,0xff,0xe0,0x01,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x07,0x00,0x1f,0xff,0xff,0xf0,0x03,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x07,0x80,0xff,0xff,0xff,0xfc,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x03,0xe0,0xff,0xff,0xff,0xfe,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x01,0xe0,0xff,0xff,0xff,0xfe,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x01,0xe0,0x7f,0xff,0xff,0xfe,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0xe0,0x7f,0xff,0xff,0xfe,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x60,0xff,0xff,0xff,0xfe,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x31,0xff,0xff,0xff,0xff,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x1f,0xff,0xff,0xff,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x07,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x03,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0xff,0xff,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x7f,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0f,0xff,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x1f,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#include <MFRC522.h>
#include <string.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
String content = "";
String myUsername = "";

void drawAccepted()
{
  Serial.print("Accepted\n");
  Serial.print(content);
  display.ssd1306_command(SSD1306_DISPLAYON);
  display.clearDisplay();
  display.setCursor(0,0);             // Start at top-left corner
  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.println(F("Accepted:"));
  display.setTextSize(1);
  display.println(content);
  display.setTextSize(2);
  display.println(F("Welcome"));
  display.println(myUsername);
  display.display();
  delay(2000);
  Serial.println(F("Placing display into sleep mode..."));
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  content="";
}

void drawDenied()
{
  Serial.print("Unknown\n");
  Serial.print(content);
  display.ssd1306_command(SSD1306_DISPLAYON);
  display.clearDisplay();
  display.setCursor(0,0);             // Start at top-left corner
  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.println(F("Unknown:"));
  display.setTextSize(1);
  display.println(content);
  display.setTextSize(2);
  display.println(F("Denied"));
  display.display();
  delay(2000);
  Serial.println(F("Placing display into sleep mode..."));
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  content="";
}

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  Serial.print("Begin setup...\n");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); //loop forever
  }
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  // display DC540 Splash screen
  display.clearDisplay();
  display.setCursor(0,0);
  display.drawBitmap(
    //0,0,logo_bmp,127,63,1);
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  Serial.print("Splash screen complete...\n");
  delay(2000);
  display.clearDisplay();
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  Serial.print("Approximate your card to the reader...\n");
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "54 0D C5 40") //change here the UID of the card/cards that you want to give access
  {
    Serial.print("Authorized access\n");
    myUsername="dc540baab";
    Serial.print("\n");
    drawAccepted();
    delay(3000);
    content="";
  }
  else   {
    Serial.print(" Access denied\n");
    drawDenied();
    delay(3000);
    content="";
  }
} 

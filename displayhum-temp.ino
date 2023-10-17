
#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>


DHT dht(D4,DHT11);
LiquidCrystal_I2C lcd(0x3f, 16, 2);

void setup() {
  Serial.begin (115200);
  dht.begin();
  lcd.begin();
  lcd.display();        //เปิดหน้าจอ
  lcd.backlight();      //เปิดไฟ backlight 
  lcd.clear();          //ล้างหน้าจอ
}

void loop() {
  float h = dht.readHumidity();             //รับค่าความชื้น
  float t = dht.readTemperature();          //รับค่าอุณหภูมิ
  lcd.setCursor(0, 0);
  lcd.print("Temp = "+String(t,1)+" C");    //แสดงค่าอุณหภูมิ
  lcd.setCursor(0, 1);
  lcd.print("Humi = "+String(h,1)+" %");    //แสดงค่าความซื้น
  delay(1000);
  lcd.clear();
}

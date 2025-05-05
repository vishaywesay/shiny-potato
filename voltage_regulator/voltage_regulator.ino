#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <OneWire.h>
#define TempSense 2  // DHT11 data pin connected to Pin 2
#define Temps        // Define sensor type
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object
int VoltPin = A5;

float temp;
float VoltValue;
float volt;
//int fan;
//int x;
//int y;
//int z;
//int high;
//int med;
//int low;

void setup() {
  // put your setup code here, to run once:
  /*lcd.begin(16, 2);*/  // Initialize LCD type (x columns, y rows)
  Serial.begin(9600);
  pinMode(VoltPin, INPUT);
}
/*
void Temper(float temp,float fan){
  temp = dht.readTemperature();
  if(temp >= 30){
    fan = HIGH;
    return fan;
  } else if (temp >= 35){
    fan = HIGH;
    return fan;
  } else if (temp <= 40){
    fan = LOW;
    return fan;
  }
}
*/
float Voltage() {
  int VoltValue = analogRead(VoltPin);
  //Analog read from the voltage divider using A to D conversion
  float volt = VoltValue * (5.0 / 1023.0);
  //Mapping the voltage
  return volt;
}

/*
void display(float volt, float temp) {
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C");
  lcd.setCursor(0, 8);
  Serial.println("Voltage: ");
  Serial.print(volt);
  Serial.print("V");
  lcd.setCursor(0, 8);
}
*/

void loop() {
  //float VoltValue = analogRead(VoltPin);
  //analogRead(VoltPin);
  VoltValue = Voltage();
  Serial.print("Voltage:");
  Serial.print(VoltValue);
  Serial.println("V");
  delay(500);
  //getVolt(float volt);
  //Temper(temp, fan);
  lcd.clear();
 // display(volt);
}

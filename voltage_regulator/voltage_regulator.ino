#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <OneWire.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object
int VoltPin = A5;
int fanPin = A0;
float volt;
float temp;
int fan;
int x;
int y;
int z;
int FAST = 255;
int MED = 128;
int SLOW = 48;

#define tempPin 3
OneWire oneWire(tempPin);             // Initialize OneWire protocol on pin tempPin.
DallasTemperature sensors(&oneWire);  // DallasTemperature library to simplifies



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(VoltPin, INPUT);
  sensors.begin();
  pinMode(tempPin, INPUT);
  lcd.begin(16, 2);  // Initialize LCD type (x columns, y rows)
}


float Voltage() {
  int VoltValue = analogRead(VoltPin);
  //Analog read from the voltage divider using A to D conversion
  float volt = VoltValue * (48.7 / 1023.0);  //The number divided by 1023.0 is the calibration constant
  //Mapping the voltage
  return volt;
}



float Temper() {
  sensors.requestTemperatures();  // Function requesting Temperature
  temp = sensors.getTempCByIndex(0);
  if (temp >= 30) {
    analogWrite(fanPin, 255);
  } else if (temp >= 25) {
    analogWrite(fanPin, 128);
  } else if (temp <= 21) {
    analogWrite(fanPin, 48);
  }
  return temp;
}


void Serialdisplay(float volt, float temp) {
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.print(" °C ");
  lcd.setCursor(0, 8);
  lcd.print("Voltage: ");
  lcd.print(volt);
  lcd.println(" V ");
  lcd.setCursor(0, 8);
}

void loop() {
  float VoltValue = analogRead(VoltPin);
  temp = sensors.getTempCByIndex(0);
  analogRead(tempPin);
  analogRead(VoltPin);
  VoltValue = Voltage();
  Serial.print("Voltage:");
  Serial.print(VoltValue);
  Serial.println("V");
  Serial.println(temp);
  delay(500);
  lcd.clear();
}
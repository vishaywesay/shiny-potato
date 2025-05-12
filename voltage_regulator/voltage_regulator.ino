#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <OneWire.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object
int VoltPin = A5;
int fanPin = 5;
float volt;
float temp;
int fan;
int x;
int y;
int z;
const int HIGH_SPEED = 255; //This is used to set pin controlling fan to full on
const int MED = 128;  // Value for setting fan to half speed on analog pin control
const int SLOW = 48;  // Value for min fan speed on analog pin control pin for TIP110

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
  analogRead(VoltPin);
  //Analog read from the voltage divider using A to D conversion
  float volt = VoltValue * (48.7 / 1023.0);  //The number divided by 1023.0 is the calibration constant
  //Mapping the voltage
  return volt;
}



float Temper() {
  analogRead(tempPin);
  sensors.requestTemperatures();  // Function requesting Temperature
  temp = sensors.getTempCByIndex(0);
  int = fanSpeed = 0;
  if (temp >= 30) {

    fanSpeed = HIGH_SPEED;
  } else if (temp >= 25) {

    fanSpeed

  } else if (temp <= 21) {

    analogWrite(fanPin, 0);
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
  Temper();
  Voltage();
  Serial.print("Voltage:");
  Serial.println("V");
  Serial.println(temp);
  delay(500);
  lcd.clear();
}
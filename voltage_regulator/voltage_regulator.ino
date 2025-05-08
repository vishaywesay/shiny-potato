#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <OneWire.h>
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object
int VoltPin = A5;

#define tempPin 3
OneWire oneWire(tempPin); // Initialize OneWire protocol on pin tempPin.
DallasTemperature sensors(&oneWire); // DallasTemperature library to simplifies

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
  sensors.begin();
  pinMode(tempPin, INPUT);
}
/*
float Temper(float temp,float fan){
  sensors.requestTemperatures(); //Function requesting Temperature
  temp = sensors.getTempCByIndex(0);
  if(temp >= 30){
    fan = HIGH;
    return fan;
  } else if (temp >= 35){
    fan = HIGH;
    return fan;
  } else if (temp <= 40){
    fan = LOW;
    return fan;
    return temp;
  }
}
*/
float Voltage() {
  int VoltValue = analogRead(VoltPin);
  //Analog read from the voltage divider using A to D conversion
  float volt = VoltValue * (48.7 / 1023.0); //The number divided by 1023.0 is the calibration constant
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
=======
float volt;
int fan;
int x;
int y;
int z;
int high;
int med;
int low;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);             // Initialize LCD type (x columns, y rows)
  Serial.begin(9600);
  sensors.begin();
  pinMode(tempPin, INPUT);
}

float Temper(){
  sensors.requestTemperatures(); // Function requesting Temperature
  temp = sensors.getTempCByIndex(0); 
  if(temp >= 1){
    fan = HIGH;
  } else if (temp >= 2){
    fan = HIGH;
  } else if (temp <= 3){
    fan = LOW;
  }
  return fan;
  return temp;
  
  
}
/*
void Serialdisplay(float volt, float temp){
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C ");
  Serial.print("Voltage: ");
  Serial.print(volt);
  Serial.println(" V ");
}
*/

void Serialdisplay(float volt, float temp){
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
  //getVolt(float volt);
  Temper();
  lcd.clear();
 
  display(volt, temp);

  
}

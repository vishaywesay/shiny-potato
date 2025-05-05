#include <DallasTemp.h>
#include <LiquidCrystal.h>
#define DHTPIN 2      // DHT11 data pin connected to Pin 2
#define DHTTYPE DHT11 // Define sensor type
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object
DHT dht(DHTPIN, DHTTYPE); // Create a DHT sensor object

float temp;
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
}

void Temper(float temp,float fan){
  temp = dht.readTemperature();
  if(temp >= 1){
    fan = HIGH;
    return fan;
  } else if (temp >= 2){
    fan = HIGH;
    return fan;
  } else if (temp <= 3){
    fan = LOW;
    return fan;
  }
}

void display(float volt, float temp){
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C");
  lcd.setCursor(0, 8);
  Serial.print("Voltage: ");
  Serial.print(volt);
  Serial.print(" °C");
  lcd.setCursor(0, 8);
  

}
void loop() {
  //getVolt(float volt);
  Temper(temp, fan);
  lcd.clear();
  display(volt, temp);
  
}

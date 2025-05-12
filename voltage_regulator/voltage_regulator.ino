/* 
Dawson College
Electronics Engineering Technology
Lab Exam
Authors: Evan Matulina and Victor Matta-Myers
Project: Arduino Managment System for a Linear Power Supply
*/

//All the libraries needed for this code to run
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <OneWire.h>

//Assigning of the variables and constants as well as one object created
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object
int VoltPin = A5;                           //used for analog in
int fanPin = 5;                             //PWM control
float volt;                                 //volt will be a variable that requires some precision. Float is required
float temp;                                 //can be changed to int if memory is an issue
int fan;
int x;
int y;
int z;
const int Hspeed = 255;  //This is used to set pin controlling fan to full on
const int Mspeed = 200;  // Value for setting fan to half speed on analog pin control
const int Lspeed = 102;  // Value for min fan speed on analog pin control pin for TIP110

#define tempPin 3
OneWire oneWire(tempPin);             // Initialize OneWire protocol on pin tempPin.
DallasTemperature sensors(&oneWire);  // DallasTemperature library to simplifies



void setup() {
  //Starting the serial connections and defining pins
  Serial.begin(9600);
  pinMode(VoltPin, INPUT);
  sensors.begin();  //Initialize the temp sensor
  pinMode(tempPin, INPUT);
  pinMode(fanPin, OUTPUT);
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


//This function is for the temperature readout
float Temper() {
  analogRead(tempPin);                //Reads the pin used for temp
  sensors.requestTemperatures();      // Function requesting Temperature
  temp = sensors.getTempCByIndex(0);  //Call a fonction from the DallasTemp lib
  int fanSpeed = 0;                   //Initial value of fanSpeed is zero as a placeholder. Replaed with speed value


  //This is the logic for the fan control
  if (temp > 30) {

    fanSpeed = Hspeed;  //Fans at full speed

  } else if (temp > 25) {

    fanSpeed = Mspeed;  //Half speed when greater than 25 degrees C

  } else {

    fanSpeed = Lspeed;  //Puts the fans to a minimum speed
  }

  analogWrite(fanPin, fanSpeed);  //This is where the value is sent out to the pin
  return temp;                    //For use later
}


void Serialdisplay(float volt, float temp) {
  lcd.clear();  // Clear the LCD before displaying new values
  lcd.print("Temp:");
  lcd.print(temp);  //Pulls the vlaue
  lcd.print(" C ");
  lcd.setCursor(0, 1);  // Move to the second line
  lcd.print("Voltage: ");
  lcd.print(volt);  //Pulls the value
  lcd.print(" V ");
}

void loop() {
  float currentVoltage = Voltage();     // Get the current voltage
  float currentTemperature = Temper();  // Get the current temperature
  Serial.print("Voltage:");
  Serial.println(currentVoltage);  // Print voltage to Serial Monitor
  Serial.print("Temperature:");
  Serial.println(currentTemperature);                 // Print temperature to Serial Monitor
  Serialdisplay(currentVoltage, currentTemperature);  // Display on LCD
  delay(500);                                         // Delay for half a second
}
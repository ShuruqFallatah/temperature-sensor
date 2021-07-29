

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
#include "max6675.h"
//first thermo
int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;
//sec thermo
#include "max6675.h"
int SthermoDO = 8;
int SthermoCS = 9;
int SthermoCLK = 10;


MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
MAX6675 Sthermocouple(SthermoCLK, SthermoCS, SthermoDO);
void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("deta logger");
  delay(5000);
}


void loop() {
  // basic readout test, just print the current temp
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cold C = ");
  lcd.print(thermocouple.readCelsius());
 
  lcd.setCursor(0, 1);
  lcd.print("Hot  C = ");
  lcd.print(Sthermocouple.readCelsius());
  //y = myMultiplyFunction(SthermoCLK, SthermoCS, SthermoDO);
 // Serial.print(y);



// Serial.println(thermocouple.readFahrenheit());

// For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
delay(1000);

}

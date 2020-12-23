#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String row1;
String row2;
char character;
bool is2ndRow = false;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  while(Serial.available())
  {
    character = Serial.read();
    
    if(character == '#' && is2ndRow)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(row1);
      lcd.setCursor(0, 1);
      lcd.print(row2);
      row1 = "";
      row2 = "";
      is2ndRow = false;
    } else if(character == '#' && !is2ndRow) {
      is2ndRow = true;
    } else if (is2ndRow) {
      row2.concat(character);
    } else {
      row1.concat(character);
    }
  }  
}
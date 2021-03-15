

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin A0
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read
float voltage = 0.00; //Voltage sensed on analgPin
float varDelay = 1.0;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Analog Input");
  pinMode(rs, OUTPUT);

}

void loop() {  
  val = analogRead(analogPin);  // read the input pin
  voltage = (5.0*((double)val/1024.0));
  
  Serial.println(voltage, 2); 
  
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 10);
  
  lcd.print("V =  ");
  lcd.print(voltage);

  delay(250);

}

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);


#define TIME 5

bool previous_data_state = true;
bool current_data_state = true;
char buffer_data[64];
void setup() 
{
  lcd.init();
  
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
    

}

void loop()
{ 

  current_data_state = input_data(); 
  if(!current_data_state && previous_data_state)
  {
    sprintf(buffer_data, "%c", data_to_recieve());
    Serial.print(buffer_data);
        lcd.print(buffer_data);

  }
  previous_data_state = current_data_state;
//  lcd.blink();

}
bool input_data()
{

bool val = analogRead(A1) > 350 ? true : false;

  return val;
}

char data_to_recieve()
{
  char recieved_data_in_byte = 0;
  delay(TIME * 1.5);
  for(int i = 0; i < 8; i++)
  {
    recieved_data_in_byte = recieved_data_in_byte | (char)input_data() << i;
    delay(TIME);
  }
  return recieved_data_in_byte;
}
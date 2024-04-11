#define TRANSMIT_LED 11
#define BUTTON 3
#define SAMPLING_TIME 5


char* text = "Li-Fi project demostration.   ";

bool led_state = false;
bool transmit_data = true;
int bytes_counter = 20;
int total_bytes;
void setup() {
  pinMode(TRANSMIT_LED,OUTPUT);
   total_bytes = strlen(text);
}

void loop() {

 
 
   while(transmit_data)
   {
    transmit_byte(text[total_bytes - bytes_counter]);
    bytes_counter--;
      if(bytes_counter == 0)
      {
        transmit_data = false;
      }
     delay(100);
   }
   transmit_data = true;
   bytes_counter = total_bytes;
    delay(500);
 }

void transmit_byte(char data_byte)
{
  digitalWrite(TRANSMIT_LED,LOW); 
  delay(SAMPLING_TIME);
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(TRANSMIT_LED,(data_byte >> i) & 0x01); 
    delay(SAMPLING_TIME);
  }
 digitalWrite(TRANSMIT_LED,HIGH); //Return to IDLE state
 delay(SAMPLING_TIME);
}

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define FS1000A_DATA_PIN 12
#define Btn 7
#define LEDyellow 6

bool btn_state;

void setup() {
Serial.begin(9600);
pinMode(FS1000A_DATA_PIN, OUTPUT);
//this line will have to be tweaked based on your button setup: pinMode (Button1, INPUT);
vw_set_tx_pin(12); 
vw_setup(4000);// speed of data transfer in bps, can max out at 10000
  
}

void sendhexdigit(char c, uint16_t pulse){
  switch (c) {

         case '0':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 4);
         break;

         case '1':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 3);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         case '2':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         break;

         case '3':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         case '4':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 2);
         break;

         case '5':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         case '6':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         break;

         case '7':
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 3);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         case '8':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 3);
         break;

         case '9':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         case 'a':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         break;

         case 'b':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         case 'c':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 2);
         break;

         case 'd':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 2);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 1);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         case 'e':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 3);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         delayMicroseconds(pulse * 1);
         break;

         case 'f':
         digitalWrite(FS1000A_DATA_PIN, HIGH);
         delayMicroseconds(pulse * 4);
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;

         default:
         digitalWrite(FS1000A_DATA_PIN, LOW);
         break;
         
  };
}

void loop() {

  char sequence1[] = "f12010482080480480480480480480482012";
  char sequence2[] = "9008241040240240240240240240241009";
  uint16_t pulse = 958;
  uint8_t i;
  uint8_t j;
  
  btn_state=digitalRead(Btn);

  if(btn_state == LOW){
    digitalWrite(LEDyellow, HIGH);

    for (i = 0; i<sizeof(sequence1); i++)
    {
      sendhexdigit(sequence1[i], pulse);
    }

    delayMicroseconds(15603);

    for (j = 0; j<12; j++)
    {
  
        for (i = 0; i<sizeof(sequence2); i++) 
        {
          sendhexdigit(sequence2[i], pulse);
        }
        delayMicroseconds(15519);
    }
    delay(2000);
    } 
    
    else {
      digitalWrite(LEDyellow, LOW);
      delay(2000);
    }
}

//CIRCUIT :  https://123d.circuits.io/circuits/1828779-light-detection-circuit-buzz-alarm-and-lcd

//-------------------------------------CODE:


#define IRsensor A0
#define buzzPin A1

//********************************************************************************
//                              written by Mouzakitis Nikos.
//                     GitHub: https://github.com/NikosMouzakitis
//
//                                         MARCH 2016
//********************************************************************************

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,7,6,3,2);

void buzzer()
{
  	int k;
	for(k = 550; k< 2660; k++)
      	analogWrite(buzzPin,k);
 	analogWrite(buzzPin,LOW);	
  	lcd.clear();
  	lcd.print("Operating");
}


void setup()
{
  	Serial.begin(9600);
	pinMode(IRsensor,INPUT);
  	pinMode(buzzPin,OUTPUT);
	lcd.print("Operating");
}

void loop()
{
	int val;
  	val = analogRead(A0);
  	if(val == 0)
      ;
  	else
    {
     	lcd.clear();
      	lcd.print("Light detected");
      	buzzer();
      	delay(1000);
    
    }
  
}

//FIND THE CIRCUIT: https://123d.circuits.io/circuits/1828295-watering-system-2tmp_sensrs-2servos-1lcd

//written by Nikos Mouzakitis.
//CODE

#include <LiquidCrystal.h>


LiquidCrystal lcd(12,11,5,4,3,2); // initialize lcd object
// also set pin configuration (RS, E, D4, D5, D6, D7)

int d_time = 800;
int v1,v2;

void pump1()
{
   int i;
   lcd.print("Watering..");
   for(i=70; i<255 ; i++)
 	   {
		analogWrite(6,i) ; 
  		delay(20) ;
 	   }	
	 
	 
     for(i=255; i>70 ; i--)
 	   {
		analogWrite(6,i) ; 
  		delay(20) ;
 	   }	
  lcd.clear();
  
}

void pump2()
{
	int j;
  	lcd.print("Watering..");
    for(j=70; j<255 ; j++)
 	   {
		analogWrite(9,j) ; 
  		delay(20) ;
 	   }	
	 
	 
     for(j=255; j>70 ; j--)
 	   {
		analogWrite(9,j) ; 
  		delay(20) ;
 	   }	
  	lcd.clear();
}

void run()
{
	v1 = analogRead(A0);
  	v2 = analogRead(A1);
  
  	lcd.print("Humitidy1: ");
  	lcd.print(v1);
  	delay(2000);
  	lcd.clear();
  	if(v1>70)
      pump1();
  
  	lcd.print("Humitidy2: ");
  	lcd.print(v2);
  	delay(2000);
  	lcd.clear();
  	if(v2>70)
      pump2();
  
}

void setup()
{
  	Serial.begin(9600);
  	pinMode(6,OUTPUT);	
	pinMode(9,OUTPUT);	
}
void loop()
{
    run();	
    delay(d_time);
}

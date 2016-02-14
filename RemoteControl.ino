#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,10,5,4,3,2); // initializing lcd object.Your screen.
int RECV_PIN = 11;//receiver pin on Arduino.
int data_rc;//data received.
IRrecv irrecv(RECV_PIN);//Required declarations for communication.
decode_results results;//our decoded results.

struct attributes {
    int volume = 10;//volume starts at 10.
    int channel = 1;//program 1.
    int state = 0;//state starts at OFF(0).
    int eq_conf = 0; // index of eq's choices.
    bool stopped = false ; // checks if stopped by remote control command.
} p_attr ;

char *eq[4] = {"stereo lover's","Dialog conf.","Dance & Party","5.1 Surround"} ;

void info() {
	lcd.print("Remote: ON CH: ");	
}

void  on() {
    lcd.print("Remote: ON CH: ");
  	lcd.print(p_attr.channel);
}

void off() {
    lcd.clear();
    p_attr.volume = 10;
    p_attr.state = 0;
    p_attr.channel = 1;
    p_attr.stopped = false;
}

void setup()
{
    Serial.begin(9600); // specifing serial ratio.
    irrecv.enableIRIn(); // Start the IR-receiver
  	
}

void loop() {
    data_rc = irrecv.decode(&results);

    if (data_rc)
    {

        switch(results.value) {
        case 16580863 :
        {
            p_attr.state++ ;
            if(p_attr.state % 2 )
                on();
            else
                off();
            break;
        }
        default :
            break;
        }

        if(p_attr.state % 2 ) // p_attr.state % 2 is true while it was pressed ON. so only when "machine" is on we need the functionality.
        {
            if((results.value != 16621663) && p_attr.stopped == true)
                ;
            else
            {



                switch(results.value)
                {
                case 16613503 :
                {
                    Serial.println("VOLUME +1");
                    p_attr.volume++ ;
                    lcd.clear() ;
                    lcd.print("volume : ");
                    lcd.print(p_attr.volume);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16580863:
                    Serial.println("TURN ON/OFF");
                    break;
                case 16597183:
                {
                    Serial.println("FUNCTION/STOP");
                    lcd.clear();
                    lcd.print("No function ");
                    delay(100);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16589023:
                {
                    Serial.println("REWIND");
                    lcd.clear();
                    lcd.print("Rewind 10 secs.");
                    delay(100);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16621663:
                {
                    Serial.println("PLAY/STOP");
                    if(p_attr.stopped == false)
                    {
                        lcd.clear();
                        lcd.print("Remote stopped.");
                        p_attr.stopped = true;
                    }
                    else
                    {
                        lcd.clear();
                        lcd.print("Remote: ON CH: ");
                        lcd.print(p_attr.channel);
                        p_attr.stopped = false;
                    }
                    break;
                }
                case 16605343:
                {
                    Serial.println("FORWARD");
                    lcd.clear();
                    lcd.print("Forward 10 secs.");
                    delay(100);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16584943:
                {  
                    Serial.println("DOWN");
                 	p_attr.channel--;
                  	if(p_attr.channel < 0)
                      	p_attr.channel = 0;
                  	lcd.clear();
                  	info();
                  	lcd.print(p_attr.channel);
                  	break;
                }
                case 16617583:
                {
                    Serial.println("VOLUME -1");
                    p_attr.volume-- ;
                    lcd.clear() ;
                    lcd.print("volume : ");
                    lcd.print(p_attr.volume);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16601263:
                {
                    Serial.println("UP");
                 	p_attr.channel++;
                  	lcd.print(p_attr.channel);
                  	if(p_attr.channel > 9)
                      	p_attr.channel = 9;
                  	lcd.clear();
                  	info();  
                  	lcd.print(p_attr.channel);
                  	break;
                }
                case 16593103:
                {
                    Serial.println("0");
                 	p_attr.channel =0;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                  	break;
                }
                case 16625743:
                {
                    Serial.println("EQ");
                    lcd.clear();
                    p_attr.eq_conf++ ;
                    lcd.print(eq[p_attr.eq_conf % 4 ]);
                    delay(250);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16609423:
                {
                    Serial.println("ST/REPT");
                    lcd.clear();
                    lcd.print("No function ");
                    delay(100);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16603303:
                {
                    Serial.println("9");
                    p_attr.channel =9;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16582903:
                {
                    Serial.println("1");
                    p_attr.channel =1;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16615543:
                {
                    Serial.println("2");
                    p_attr.channel =2;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16599223:
                {
                    Serial.println("3");
                    p_attr.channel =3;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16591063:
                {
                    Serial.println("4");
                    p_attr.channel =4;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16623703:
                {
                    Serial.println("5");
                    p_attr.channel =5;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case  16607383:
                {
                    Serial.println("6 ");
                    p_attr.channel =6;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16586983:
                {
                    Serial.println("7");
                    p_attr.channel =7;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                case 16619623:
                {
                    Serial.println("8");
                    p_attr.channel =8;
                    lcd.clear();
                    lcd.print("CHANNEL ");
                    lcd.print(p_attr.channel);
                    delay(200);
                    lcd.clear();
                    info();
                  	lcd.print(p_attr.channel);
                    break;
                }
                default :
                    Serial.println("Transmiting error");
                    break;
                }
            }
        }
        else
            ;

        irrecv.resume(); // Receive the next value
    }
}
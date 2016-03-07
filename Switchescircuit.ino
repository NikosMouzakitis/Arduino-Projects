Prototyping some curcuits on Arduino board.
SWITCHES.

https://123d.circuits.io/circuits/1661806-arduino-some-curcuits-with-switches-pushbutton-dspt-leds

CODE:




void setup() {
  
	pinMode(12,OUTPUT);
  

}

void loop() {
	digitalWrite(12,HIGH);
  	delay(800);	
  	digitalWrite(12,LOW);
  	delay(800);
}


/* Reads a character from the Serial monitor
 *  and prints it on Serial.
 */
int a;
char b ;

void setup() { 
  Serial.begin(9600);
}

void loop() {

  if(Serial.available() > 0) {
    a = Serial.read();
    b = char(a);
    Serial.print(b);
   
  }
  
 
}

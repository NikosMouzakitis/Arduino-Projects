/*
 Traffic lights 1.
               NS
          
              | |
              | |
              | |
              | |
    ----------| |----------- EW
EW  ----------   ------------
              | |
              | |
              | |
              | |
              | |

              NS
   1.No pedestrians passing
   2.Just two streams of moving
       a) North-South (NS)
       b) East-West   (EW)

  Will be having two lights one for NS,and one for EW stream.
  
  Written by Mouzakitis Nikolaos,2016.
  SerialDemonstration.
*/

int ns_light,ew_light;

void traffic_lights(void)
{
  ns_light = 0;  // green
  ew_light = 2;  //red

  print_lights(ns_light,ew_light);
  delay(7000);
  
  ns_light = 1;  // yellow
  ew_light = 2;  //red

  print_lights(ns_light,ew_light);
  delay(3000);

  ns_light = 2;  // red
  ew_light = 0;  // green

  print_lights(ns_light,ew_light);
  delay(7000);

  ns_light = 2;  // red
  ew_light = 1;  // yellow

  print_lights(ns_light,ew_light);
  delay(3000);

  
}

void print_lights(int arg1,int arg2)
{
  String l1="";
  String l2="";

  switch(arg1)
  {
    case 0:
            l1 += "Green";
            break;
    case 1:
            l1 += "Yellow";
            break;
    case 2: l1 += "Red";
            break;   
  }

  switch(arg2)
  {
    case 0:
            l2 += "Green";
            break;
    case 1:
            l2 += "Yellow";
            break;
    case 2: l2 += "Red";
            break;   
  }

  Serial.println("North/South:\t" + l1+"\n");
  Serial.println("East/West:\t" + l2+"\n\n\n");
}

void setup() {
  
  
  Serial.begin(9600);
  

}

void loop() {
  traffic_lights();
}

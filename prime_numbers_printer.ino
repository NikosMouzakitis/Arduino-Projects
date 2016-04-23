// isPrime() is a function from my C libray "biblioteca.h"
//written April 2016,Mouzakitis Nikolaos.

int i = 2;
int d_time = 10;

void setup()
{
  Serial.begin(9600);
  Serial.println("PRIME NUMEBERS");
  
}

int isPrime(int n)
{
    int i, count = 0;

    for(i = 2; i < n; i++)

        if(n % i )
            count += 1;
    if(count == n - 2)
        return (n);
    else
        return (0) ;
}



void loop()
{
  int result = isPrime(i);
  
  if(result)
    Serial.println(i);
  delay(d_time);
  i++;
}

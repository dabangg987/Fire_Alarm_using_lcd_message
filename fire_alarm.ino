#include<LiquidCrystal.h>
#include<Servo.h>

Servo s1;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, ct=9;
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);

int fireSensorPin = 13;

int green = 7;
int red= 6;

int trig_pin = 10;
int echo_pin = 1;

long duration ;
int distance;

void setup()
{

  Serial.begin(9600);
  pinMode(fireSensorPin, INPUT);

  pinMode(green, OUTPUT);
  pinMode(red,OUTPUT);
  
   pinMode(trig_pin,OUTPUT);
   pinMode(echo_pin,INPUT);
   Serial.begin(9600);

   s1.attach(8);
}

void loop()
{ 
  int fireValue = digitalRead(fireSensorPin);
  if(fireValue==0)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    analogWrite(ct,30);
    mylcd.begin(16, 2);
    mylcd.print("FIRE!!!");
    
    s1.write(90);
    Serial.println(fireValue);
  }
  else
  {
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    analogWrite(ct,50);
    mylcd.begin(16, 2);
    mylcd.print("NO FIRE!!!");
   
    s1.write(0);
    Serial.println(fireValue);
  }
}

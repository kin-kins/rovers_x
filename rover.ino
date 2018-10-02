#include <Servo.h>//Using servo library to control ESC
Servo esc1,esc2,esc3,esc4; //Creating a servo class with name as esc

void setup()
{
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
}
int val1,val2,val3,val4;
int motor1,motor2,motor3,motor4;

void getpulse()
{
val1= pulseIn(4,HIGH,25000);
Serial.println("channel 1");
Serial.println(val1);//Read input from analog pin a0 and store in val
/*val2= pulseIn(5,HIGH,25000);
Serial.println("channel 2");
Serial.println(val2);//Read input from analog pin a0 and store in val
delay(1000);*/
val3= pulseIn(6,HIGH,25000);//channel 3 throttle 
Serial.println("channel 3");
Serial.println(val3);//Read input from analog pin a0 and store in val

/*val4= pulseIn(7,HIGH,25000);
Serial.println("channel 4");
Serial.println(val4);//Read input from analog pin a0 and store in val
delay(500);*/
}
void forward()
{
 
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(11,1);
  digitalWrite(12,0);
}

void back()
{
  digitalWrite(8,0);
  digitalWrite(9,1);
  digitalWrite(11,0);
  digitalWrite(12,1);
}


void left()
{
  digitalWrite(8,0);
  digitalWrite(9,1);
  digitalWrite(11,1);
  digitalWrite(12,0);
}

void right()
{
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(11,0);
  digitalWrite(12,1);
}
void loop()
{
  
getpulse();
if(val3>1600)
{forward();
Serial.println("forward");
digitalWrite(13,HIGH);
}
if (val3<1400)
{
  back();
Serial.println("backward");
digitalWrite(13,LOW);
}
if(val1>1500)
{
right();
Serial.println("right");
}
if(val1<1380)
{ left();
Serial.println("left");
}
delay(2000);
}

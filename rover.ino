#include <Servo.h>//Using servo library to control ESC
Servo esc1,esc2,esc3,esc4; //Creating a servo class with name as esc

void setup()
{
pinMode(12,INPUT);
pinMode(13,INPUT);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}
int val1,val2,val3,val4;
int motor1,motor2,motor3,motor4;

void getpulse()
{
val1= pulseIn(12,HIGH,25000);
Serial.println("channel 1");
Serial.println(val1);//Read input from analog pin a0 and store in val
/*val2= pulseIn(5,HIGH,25000);
Serial.println("channel 2");
Serial.println(val2);//Read input from analog pin a0 and store in val
delay(1000);*/
val3= pulseIn(13,HIGH,25000);//channel 3 throttle 
Serial.println("channel 3");
Serial.println(val3);//Read input from analog pin a0 and store in val

/*val4= pulseIn(7,HIGH,25000);
Serial.println("channel 4");
Serial.println(val4);//Read input from analog pin a0 and store in val
delay(500);*/
}
void forward()
{
 
  digitalWrite(3,1);
  digitalWrite(5,0);
  digitalWrite(6,1);
  digitalWrite(11,0);
}

void back()
{
  digitalWrite(3,0);
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(11,1);
}


void left()
{
  digitalWrite(3,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(11,0);
}

void right()
{
  digitalWrite(3,1);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(11,1);
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
if(val1>1600)
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

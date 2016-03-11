#include <Servo.h> 
int green = 2;
int red = 3;
int left = 11;
int claw =9;
int right = 6;
int flex = A0;

int button = 12;

int flexstore=0;
int garbagecount = 0;
int shouldmove = 1;

Servo leftservo;
Servo rightservo;
Servo clawservo;


void setup() 
{ 
  leftservo.attach(left);
  rightservo.attach(right);
  clawservo.attach(claw);
  pinMode(button,INPUT_PULLUP);
  pinMode(flex,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);
  clawservo.write(90);

leftservo.write(92);
rightservo.write(92);

digitalWrite(red,1);
digitalWrite(green,1);
delay(1000);
digitalWrite(red,0);
delay(1000);
digitalWrite(red,1);
digitalWrite(green,1);



  
  
    // set servo to mid-point
} 
  
int isflexed (int input)
{
    if (input > 170)
      return 0;
    return 1;
  
 }
void loop() 
{
 //if (digitalRead(button,HIGH){
   // shouldmove = 1;    }
  if (shouldmove>0)
    {
      leftservo.write(0);
      rightservo.write(180);
    }
  
  if (isflexed(analogRead(flex))>0)
   {
      while (garbagecount < 200){
        Serial.println(garbagecount);
        if (isflexed (analogRead(flex))==0)
          garbagecount++;
        else
          garbagecount = 0;
      }
      leftservo.write(92);
      rightservo.write(92);
      delay(5000);
      clawservo.write(12);
    }  
   /*if (garbagecount>9)
    {
    
      delay(2000);
      
      leftservo.write(0);
      rightservo.write(180);
      delay(2000);
    }*/
  
  
   
  
 
 


}


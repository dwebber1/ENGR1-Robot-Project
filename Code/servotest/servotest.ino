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
boolean hascan = false;
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
digitalWrite(green,0);
delay(1000);
digitalWrite(red,1);
digitalWrite(green,1);
while (digitalRead(button))
{}
delay (1500);
leftservo.write(0);
rightservo.write(180);

  
  
    // set servo to mid-point
} 
  
boolean isflexed ()
{
    
    return (analogRead(flex) <= 170);
    
  
 }
void loop() 
{
 //if (digitalRead(button,HIGH){
   // shouldmove = 1;    }
 
  
  if (!hascan && isflexed())
  {
    while (garbagecount < 200)
    {
      Serial.println(garbagecount);
      if (!isflexed ())
        garbagecount++;
      else
        garbagecount = 0;
    }
      closeclaw();
  }
  if(hascan && isflexed())
  {
    openclaw();

  }

  
}

void closeclaw()
{
      leftservo.write(92);
      rightservo.write(92);
      delay(1000);
      clawservo.write(12);
      delay(1000);
      leftservo.write(0);
      rightservo.write(180);
      hascan = true;

}

void openclaw()
{
      leftservo.write(92);
      rightservo.write(92);
      delay(1000);
      clawservo.write(90);
      delay(1000);
      

}




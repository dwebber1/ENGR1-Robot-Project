#include <Servo.h>

int green = 3;
int red = 2;
int left = 6;
int claw = 9;
int right = 11;
int flex = A0;
int button = 12;
int flexstore = 0;
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
  pinMode(button, INPUT_PULLUP);
  pinMode(flex, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  //Serial.begin(9600);
  rightservo.write(93);
  leftservo.write(90);
  clawservo.write(90);
  delay(1500);



  //digitalWrite(red,1);
  digitalWrite(green, 1);
  delay(1000);
  digitalWrite(red, 0);

  delay(1000);

  //digitalWrite(green,1);
  while (digitalRead(button))
  {}

  digitalWrite(green, 0);
  digitalWrite(red, 1);

  rightservo.write(85);
  leftservo.write(99);




  // set servo to mid-point
}

boolean isflexed ()
{

  return (analogRead(flex) <=190 );


}
void loop()
{
  //if (digitalRead(button,HIGH){
  // shouldmove = 1;    }
  //Serial.println(analogRead(flex));

  if (!hascan && isflexed())
  {
    while (garbagecount < 130)
    {
      //Serial.println(garbagecount);
      if (!isflexed ())
        garbagecount++;
      else
        garbagecount = 0;
    }
    closeclaw();
  }
  if (hascan && isflexed())
  {
    openclaw();

  }


}

void closeclaw()
{
  leftservo.write(90);
  rightservo.write(93);

  delay(1000);

  clawservo.write(20);

  delay(1000);
  leftservo.write(99);
  delay(100);
  rightservo.write(85);
  

  hascan = true;
  delay(2000);

}

void openclaw()
{

  leftservo.write(90);
  rightservo.write(93);
  delay(1000);
  clawservo.write(90);
  delay(1000);


}




//importing code for the servos
#include <Servo.h>
// Setting Variables for all devices
int green = 3;
int red = 2;
int left = 6;
int claw = 9;
int right = 11;
int flex = A0;
int button = 12;
int flexstore = 0;
int garbagecount = 0;
// Creating a boolean for if the system has the can or not
boolean hascan = false;
//Creating servos
Servo leftservo;
Servo rightservo;
Servo clawservo;
void setup()
{
  //Attaching Servos
  leftservo.attach(left);
  rightservo.attach(right);
  clawservo.attach(claw);
  //Setting pinmodes
  pinMode(button, INPUT_PULLUP);
  pinMode(flex, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  //Setting the robot to stop and open the claw
  rightservo.write(93);
  leftservo.write(90);
  clawservo.write(90);
  delay(1500);
  //setting led to green
  digitalWrite(green, 1);
  delay(1000);
  digitalWrite(red, 0);
  //wait
  delay(1000);
  //creating a while loop to hold until the button is pushed
  while (digitalRead(button))
  {}
  // Starting movement
  digitalWrite(green, 0);
  digitalWrite(red, 1);
  rightservo.write(85);
  leftservo.write(99);
}
//if the flex is larger less than 190 set isFlexed to "true"
boolean isflexed ()
{
  return (analogRead(flex) <= 190 );
}
void loop()
{
  //checking if it doesn't have the can and if is flex is true
  if (!hascan && isflexed())
  {
    //increment count to check if the flex is real
    //if the count is less than 130 and the flex doesn't continue
    //we reject it and start over
    while (garbagecount < 130)
    {
      if (!isflexed ())
        garbagecount++;
      else
        garbagecount = 0;
    }
    closeclaw();
  }
  // if it has the can and is flexed or hitting the wall it calls for the claw to close
  if (hascan && isflexed())
  {
    openclaw();
  }
}
//function to close claw
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
//function to open claw
void openclaw()
{
  leftservo.write(90);
  rightservo.write(93);
  delay(1000);
  clawservo.write(90);
  delay(1000);
}

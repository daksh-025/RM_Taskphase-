#include <Servo.h>
int servopin=6;
int servopos=0;
Servo myservo;
#include <Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(2,3);
//
void setup()
{
  myservo.attach(servopin);
  Serial.begin(9600);
  ps2.begin(115200);
}

void loop()
{  if (ps2.readButton(PS2_UP)==0){
  myservo.write(179);
  delay(15);}
  if(ps2.readButton(PS2_DOWN)==0){
  myservo.write(0)
  delay(15);

   Serial.println("enter servo pos");
   servopos = Serial.parseInt(); 
   myservo.write(servopos);  
		  
  
}

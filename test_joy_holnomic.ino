#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(2,3);

//pin Numbers
int tl=8;
int tr=4;
int br=5;
int bl=11;
int tlspeed=6;
int trspeed=9;
int brspeed=7;
int blspeed=10;



//horizontal and verticle speeds
int speedverticle;
int speedhorizontal;

//degree input by user
//at what degree the bot has to move
int degree; 

void setup() {
 pinMode(tl, OUTPUT);
 pinMode(tlspeed, OUTPUT);
 pinMode(tr, OUTPUT);
 pinMode(trspeed, OUTPUT);
 pinMode(bl, OUTPUT);
 pinMode(blspeed, OUTPUT);
 pinMode(br, OUTPUT);
 pinMode(brspeed, OUTPUT);
 ps2.begin(9600);
 
 Serial.begin(9600); 
}

void loop() {
  int val1=ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS==0)-132;
  int val2=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS==0)-123;
  int motorspeed=100;
  
  Serial.println("Enter a number between 0-360");
  
  int degree=atan2(val2,val1)+1.57;
  
 
  if(val1==0 && val2==0){
    motorspeed=0;}

 digitalWrite(tl,HIGH);
 digitalWrite(tr, HIGH);
 digitalWrite(bl, HIGH);
 digitalWrite(br, HIGH);
 

  int arrwheel[]{tl,tr,bl,br};
  int wspeed[]{45,135,315,225};
  int v[]={};
  digitalWrite(arrwheel[0],HIGH);
  digitalWrite(arrwheel[1], HIGH);
  digitalWrite(arrwheel[2], HIGH);
  digitalWrite(arrwheel[3], HIGH);

  
  for (int i=0; i<4; i++){
    v[i]=motorspeed*sin(wspeed[i]*(3.14/180))*sin(degree)+motorspeed*cos(wspeed[i]*(3.14/180))*cos(degree);
  }
  //giving speed input to the wheels
  for (int j=0;j<4;j++){
    analogWrite(arrwheel[j],v[j]);
  }
  for(int i=0;i<4;i++){
    if(v[i]<0)
      digitalWrite(arrwheel[i],LOW);
      
}
}

//pin numbers
#define leftdir 2;
#define leftspeed 3;
#define rightdir 4 ;
#define rightspeed 5;
#define frontdir=6;
#define frontspeed=9;
#define backdir=8;
#define backspeed=10;
#define motorspeed 255
void setup() {
 pinMode(leftdir, OUTPUT);
 pinMode(leftspeed, OUTPUT);
 pinMode(rightdir, OUTPUT);
 pinMode(rightspeed, OUTPUT);
 pinMode(frontdir, OUTPUT);
 pinMode(frontspeed, OUTPUT);
 pinMode(backdir, OUTPUT);
 pinMode(backspeed, OUTPUT);
 Serial.begin(9600);

}

void loop() {
  Serial.println("Enter degree value ");
  if(Serial.available())
  {
    int degree=Serial.parseInt();
  }
  int arrdir[]{leftdir,rightdir,frontdir,backdir};
  int arrspeeds[]{leftspeed,rightspeed,frontspeed,backspeed};


  int vertical=sin(degree)*motorspeed;
  int horizontal=cos(degree)*motorspeed;
  void move(){
  if (vertical > 0 && horizontal >0){
  digitalWrite(arrdir[0],HIGH);
  digitalWrite(arrdir[1], HIGH);
  digitalWrite(arrdir[2], HIGH);
  digitalWrite(arrdir[3], HIGH);
  } 
  if (vertical<0){
    digitalWrite(arrdir[2],LOW);
    digitalWrite(arrdir[3],LOW);
  }
  if (horizontal<0){
  digitalWrite(arrdir[0],LOW);
  digitalWrite(arrdir[1],LOW);

  }
   
 analogWrite(arrspeeds[2], horizontal);analogWrite(arrspeeds[3], horizontal);
 analogWrite(arrspeeds[0], horizontal;analogWrite(arrspeeds[3], horizontal);
  }
  move()

}

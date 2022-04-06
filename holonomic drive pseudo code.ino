
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

  int vertical=sin(degree)*motorspeed;
  int horizontal=cos(degree)*motorspeed;
  if (vertical > 0 && horizontal >0){
  digitalWrite(leftdir,HIGH);
  digitalWrite(rightdir, HIGH);
  digitalWrite(frontdir, HIGH);
  digitalWrite(backdir, HIGH);
  } 
  if (vertical<0){
    digitalWrite(frontdir,LOW);
    digitalWrite(backdir,LOW);
  }
  if (horizontal<0){
  digitalWrite(leftdir,LOW);
  digitalWrite(rightdir,LOW);

  }
   
 analogWrite(frontspeed, horizontal);analogWrite(backspeed, horizontal);
 analogWrite(leftspeed, horizontal;analogWrite(backspeed, horizontal);


}

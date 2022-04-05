#define trigpin 12
#define echopin 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,INPUT);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  }

void loop() {
    // put your main code here, to run repeatedly:
int one=digitalRead(9);
int two=digitalRead(8);
int three=digitalRead(7);
int four=digitalRead(6);
int five=digitalRead(5);
int six=digitalRead(4);
int seven=digitalRead(3);
int eight=digitalRead(2);
if(four==HIGH||five==HIGH)
{Serial.println("moving forward");
}

if (one==HIGH || two==HIGH||three==HIGH)
{Serial.println("moving left");
digitalWrite(10,HIGH);
analogWrite(11,255);
}

if (six==HIGH || seven==HIGH || eight==HIGH)
{Serial.println("moving right");
digitalWrite(10,LOW);
analogWrite(11,255);
}
int duration ;
int distance ;
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration=pulseIn(echopin,HIGH);
distance=(duration/2)/29.1;
Serial.println(distance);
if (distance>0 && distance <15)
    digitalWrite(LED_BUILTIN,LOW);
if (distance>15 && distance<50)
    digitalWrite(LED_BUILTIN,HIGH);



}

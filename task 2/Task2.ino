#include <Stepper.h>
Stepper fan_motor(64,A5,A3,A4,A2);
Stepper move1(64,6,4,5,3);
Stepper move2(64,10,8,9,7);
int S_ON=0;
const byte interruptpin=2;
const byte ledpin=1;
bool ledstate=false;
int fanstate = 0;
int motor1state=1;
int motor2state=1;
int m1,m2;
unsigned long time,previousMillis=0;
int fire_begin=0;
const byte echopin1 = 12 ;
const byte echopin2 = 11 ;
const byte echopin3 = 13 ;
const byte trigPin = A1 ;
void setup()
 {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT );
  pinMode(echopin1, INPUT );
  pinMode(echopin2, INPUT );
  pinMode(echopin3, INPUT );
  fan_motor.setSpeed(300);
  move1.setSpeed(300);
  move2.setSpeed(300);
  pinMode(S_ON,INPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(interruptpin,INPUT) ;
  attachInterrupt(digitalPinToInterrupt(interruptpin), ActiveFan,CHANGE);
  }
 void loop()
 {   
   if((unsigned long)(millis()-previousMillis)>=1000)
   {
    ledstate = !ledstate ;
    digitalWrite(ledpin,ledstate) ;
    previousMillis = millis() ;}
     if(digitalRead(S_ON)==HIGH){  
      if(getdistance(echopin1) < 100 )
   {
    if(getdistance(echopin2) < 100)
    {
      if( getdistance(echopin3) < 100  )
      {
        m2 =-1 ;
        m1 = -1 ; 
      }
      else
       {
        m2 =8 ;
        m1 = 0 ; 
       }}
    else{  
        m2 = 0 ;
        m1 = 8 ; 
        }}
    else{
      m1=motor1state;
      m2=motor2state;
      }
      
    fan_motor.step(fanstate);
    move1.step(m1);
    move2.step(m2); 
  }
 else
 {
  fan_motor.step(0);
  move1.step(0);
  move2.step(0);
  }}
 void ActiveFan()
 {
if(digitalRead(interruptpin) == HIGH   )
  {
    fire_begin = millis();
      motor1state = 1 ;
      motor2state=1;
      fanstate = 0 ;
  }
  if(digitalRead(interruptpin)==LOW  )
  {
     if((millis()-fire_begin)>=500)
     {
      motor1state = 0 ;
      motor2state=0;
      fanstate = 1 ;
     }
     else
     {
      motor1state = 1 ;
      motor2state=1;
      fanstate = 0 ;
      } 
  }}
float getdistance(const byte echoPin)
{
  digitalWrite( trigPin, HIGH ); 
  while(micros()% 10 !=0)
  {}
  digitalWrite( trigPin, LOW );
 float duration = 0;
  while( 1 )
  {
  if( digitalRead(echoPin) & 1 ) 
  {
   time = micros();
    break;
  }}
  while( 1 )
  {
  if( (digitalRead(echoPin) & 1)==0 ) 
  {
   duration = micros()-time;
    break;
  }}
return(( duration/2 ) * 0.0344);    
}

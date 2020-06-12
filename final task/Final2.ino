int change=0;
int counter=0;
int toggle=0;
void setup() {
  Serial.begin(9600);
for(int i=0;i<14;i++)
{pinMode(i,OUTPUT);}
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A5,OUTPUT);
pinMode(A4,OUTPUT);
 move_servo(10,2000,250);
 move_servo(10,1000,250);
for(int i=0;i<19;i++)
{
  move_stepper(2,3,2000);
  if(i==4)
  {
    move_servo(12,2000,50);
    move_servo(12,1000,50);
  }
  if(i==8)
  {
    move_servo(11,2000,100);
    move_servo(11,1000,100);
  }
}
for(int i=0;i<12;i++)
{
move_stepper(2,3,4000);
if(i==3 || i==7 || i==11)
{
  move_servo(13,2000,50);
 move_servo(13,1000,50);
  }
}
  
move_stepper(A5,A4,15000);
digitalWrite(0,HIGH);
delay(1000);
digitalWrite(0,LOW);
move_stepper(A5,A4,15000);
delay(1000);

}
void loop()
{
if(digitalRead(A0)==HIGH)
decorate1();
else if(digitalRead(A1)==HIGH)
decorate2();
else if(digitalRead(A2)==HIGH)
decorate3();
else if(digitalRead(A3)==HIGH)
decorate4();
else;
}
/////////////////////////////////////////
void move_servo(int pin,int time_,int play)
{
  digitalWrite(pin,HIGH);
  delayMicroseconds(time_);
  digitalWrite(pin,LOW);
  delay(play);
  }
////////////////////////////////////////////////////
void move_stepper(int plus,int minus, int delaytime)
{  for (int i = 0; i < 51 ; i++) 
  {if(change==1)
  {
    digitalWrite(plus, HIGH);
    digitalWrite(minus, LOW);
    delayMicroseconds(delaytime);
    change=0;
    }
    else
    {digitalWrite(plus, LOW);
    digitalWrite(minus, HIGH);
    delayMicroseconds(delaytime);
    change=1;}
  }
  }
 /////////////////////////////////////////////////////
 void decorate1()
  {
  digitalWrite(1,HIGH);
  delayMicroseconds(1300);
  digitalWrite(1,LOW);
  digitalWrite(6,HIGH);
     for (int i = 0; i < 16 ; i++) 
  {if(toggle==1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    toggle=0;
    }
    else
    {digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    toggle=1;}
  }
  digitalWrite(6,LOW);
  digitalWrite(1,HIGH);
  delayMicroseconds(1400);
  digitalWrite(1,LOW);
  digitalWrite(7,HIGH);
    for (int i = 0; i < 16 ; i++) 
  {if(toggle==1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    toggle=0;
    }
    else
    {digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    toggle=1;}
  }
  digitalWrite(7,LOW);
  digitalWrite(1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(1,LOW);
  }
//////////////////////////////////////////////////////////
  void decorate2()
  {  
  digitalWrite(1,HIGH);
  delayMicroseconds(1300);
  digitalWrite(1,LOW);
  digitalWrite(6,HIGH);
  for (int i = 0; i < 16 ; i++) 
  {if(toggle==1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    toggle=0;
    }
    else
    {digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    toggle=1;}
    if(i==2 ||i==6 ||i==10 || i==14)
    digitalWrite(6,LOW);
    else if(i==4 || i==8 ||i==12)
    digitalWrite(6,HIGH);
    else;
    }
  digitalWrite(1,HIGH);
  delayMicroseconds(1400);
  digitalWrite(1,LOW);
  digitalWrite(7,LOW);
  for (int i = 0; i < 16 ; i++) 
  {if(toggle==1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    toggle=0;
    }
    else
    {digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    toggle=1;}
    if(i==2 ||i==6 ||i==10 || i==14)
    digitalWrite(7,HIGH);
    else if(i==4 || i==8 ||i==12)
    digitalWrite(7,LOW);
    else;
    }
    digitalWrite(7,LOW);
      digitalWrite(1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(1,LOW);
    }
//////////////////////////////////////////////////////////////
    void decorate3()
    {
      digitalWrite(1,HIGH);
  delayMicroseconds(1300);
  digitalWrite(1,LOW);
  for (int i = 0; i < 16 ; i++) 
  {if(toggle==1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    digitalWrite(6,HIGH);
    toggle=0;
    }
    else
    {digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(6,LOW);
    toggle=1;}
  }
  digitalWrite(6,LOW);
  digitalWrite(1,HIGH);
  delayMicroseconds(1500);
  digitalWrite(1,LOW);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
      }
////////////////////////////////////////////////////////////////////////////
void decorate4()
{ digitalWrite(1,HIGH);
  delayMicroseconds(1300);
  digitalWrite(1,LOW);
  for(int j=0;j<4;j++)
  {
  for (int i = 0; i < 4 ; i++) 
  { if(i==0)
    digitalWrite(6,HIGH);
    else if(i==2)
    digitalWrite(7,HIGH);
    else
    {digitalWrite(6,LOW);
      digitalWrite(7,LOW);}
    if(toggle==1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    toggle=0;
    }
    else
    {digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    toggle=1;}
    }
  }
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(1,HIGH);
  delayMicroseconds(1450);
  digitalWrite(1,LOW);
  digitalWrite(6,HIGH);
   for (int i = 0; i < 16 ; i++) 
  {if(toggle==1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(500);
    toggle=0;
    }
    else
    {digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(500);
    toggle=1;}
  }
  digitalWrite(6,LOW);
  digitalWrite(1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(1,LOW);
  }

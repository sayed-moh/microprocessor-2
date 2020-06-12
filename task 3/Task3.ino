//you have to download keypad library to work
#include <Stepper.h>
#include <Keypad.h>
Stepper motor(32,13,12,11,10);
int fire_begin=0;
int D0=5;
int D1=6;
int D2=7;
int D3=8;
int current=0;
int num,desired,dl,diff; 
int arrayofactivation[8]={0,0,0,0,0,0,0,0};
char keys[4][2] = {
  {48,49},
  {50,51},
  {52,53},
  {54,55}  
};
byte rowPins[4] = {0,1,8,9}; //connect to the row pinouts of the keypad
byte colPins[2] = {A1,A2}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, 4, 2 );
void setup() {
  motor.setSpeed(100);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),Active_switch,CHANGE);
}

void loop() {
int sensor = analogRead(A0);
if((sensor * (5.0 / 1023.0))>=3.5)
 {
  digitalWrite(4,HIGH);
 }
 else
 {
 digitalWrite(4,LOW);
 
 movemotor(getnearest(current));
 char key = keypad.getKey(); 
  if (key)
  {desired=key-48; 
    if(current==desired)
      {}
      else
      {
         
        arrayofactivation[key-48]=1;
      }
    }
 }
}
/////////////////////////////////////////////////////////////////////////////////////////
void Active_switch()
{ 

  if(digitalRead(2) == HIGH  )
  {
     fire_begin = millis();   
      D0=digitalRead(5);
      D1=digitalRead(6);
      D2=digitalRead(7); 
      
  }
  else if(digitalRead(2) == LOW)
  {
     if( (unsigned long)(millis()-fire_begin)>=200)
     { 
    if(D0==0 && D1==0 && D2==0)
    {desired=0;
      }
      
    else if(D0==1 && D1==0 && D2==0)
    {
      desired=1;
      }
      
    else if(D0==0 && D1==1 && D2==0)
    {
      desired=2;
      }
      
    else if(D0==1 && D1==1 && D2==0)
    {
      desired=3;
      }
      
    else if(D0==0 && D1==0 && D2==1)
    {
      desired=4;
      }
      
    else if(D0==1 && D1==0 && D2==1)
    {
      desired=5;
      }
      
    else if(D0==0 && D1==1 && D2==1)
    {
      desired=6;
      }
      
    else if(D0==1 && D1==1 && D2==1)
    {
      desired=7;
      }
      if(current==desired)
      {}
      else
      {
      arrayofactivation[desired]=1;
      }
     }
     else;
}
}

  ///////////////////////////////////////////////////////////////////
  void Read_seven_segment(int num)
{
 
  digitalWrite(A3,bitRead(num,0));
  digitalWrite(A4,bitRead(num,1));
  digitalWrite(A5,bitRead(num,2));

}
////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
void movemotor( int d)
{ 
  if(d>current)
  {
    for(int i=current;i<=d;i++)
    {//d=getnearest(current);
      if(current!=d)
    {   
        motor.step(32);
        Read_seven_segment(current);
        current++;
        getnearest(current);
        Read_seven_segment(current);       
      }
      else
      {
           motor.step(0);
           Read_seven_segment(current);
           arrayofactivation[i]=0;
          
         
          
        }
      }
    }
    else if(d<current)
    {
      for(int i=current;i>=d;i--)
      { //d=getnearest(current);  
        if(current!=d)
          {
            motor.step(-32);
            Read_seven_segment(current);
            current--;
            getnearest(current);
            Read_seven_segment(current); 
          }
          else
          { 
          motor.step(0);
          arrayofactivation[i]=0;
          Read_seven_segment(current);
          }
      }
    }
  }
  /////////////////////////////////////////
  int getnearest(int c)
  {
    int min=10;
    for(int i=0 ; i<8 ; i++)
    {
      if((i!=c) && arrayofactivation[i]==1 && (abs(i-c))<min)
      {
        min=abs(i-c);
        desired=i;
        }
      }
     // Serial.println("desired"); 
     // Serial.println(desired);
      return desired;
     }
  

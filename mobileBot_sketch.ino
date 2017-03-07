int motor_left[]={2,3};
int motor_right[]={4,5};
int D3=8;
int D2=9;
int D1=10;
int D0=11;
int r1;
int r2;
int r3;
int r4;
void setup()
{ Serial.begin(9600);
for(int i=0;i<2;i++)
{
pinMode(motor_left[i],OUTPUT);
pinMode(motor_right[i],OUTPUT);
}
pinMode(D3,INPUT);
pinMode(D2,INPUT);
pinMode(D1,INPUT);
pinMode(D0,INPUT);
r1=0;
r2=0;
r3=0;
r4=0;
} //end of void setup
void loop()
{
r1=digitalRead(D3); //r1 to r4 get the values of D3 to D0 respectively
r2=digitalRead(D2);
r3=digitalRead(D1);
r4=digitalRead(D0);
if(r1==LOW&&r2==LOW&&r3==HIGH&&r4==LOW) // Binary 0010 ; Decimal 2
{ Serial.println("Moving Forward");
moveforward();
}
if(r1==LOW&&r2==HIGH&&r3==LOW&&r4==LOW) // Binary 0100 ; Decimal 4
{ Serial.println("Moving Left");
moveleft();
}
if(r1==LOW&&r2==HIGH&&r3==LOW&&r4==HIGH) // Binary 0101 ; Decimal 5
{ Serial.println("Not moving");
nomove();
}
xi
if(r1==LOW&&r2==HIGH&&r3==HIGH&&r4==LOW) // Binary 0110 ; Decimal 6
{ Serial.println("Moving Right");
moveright();
}
if(r1==HIGH&&r2==LOW&&r3==LOW&&r4==LOW) // Binary 1000 ; Decimal 8
{ Serial.println("Moving Backward");
movebackward();
}
} //end of void loop
void moveforward()
{
digitalWrite(motor_left[0],HIGH);
digitalWrite(motor_left[1],LOW);
digitalWrite(motor_right[0],HIGH);
digitalWrite(motor_right[1],LOW);
}
void movebackward()
{
digitalWrite(motor_left[0],LOW);
digitalWrite(motor_left[1],HIGH);
digitalWrite(motor_right[0],LOW);
digitalWrite(motor_right[1],HIGH);
}
void moveleft()
{
digitalWrite(motor_left[0],LOW);
digitalWrite(motor_left[1],HIGH);
digitalWrite(motor_right[0],HIGH);
digitalWrite(motor_right[1],LOW);
}
void moveright()
{
digitalWrite(motor_left[0],HIGH);
digitalWrite(motor_left[1],LOW);
digitalWrite(motor_right[0],LOW);
digitalWrite(motor_right[1],HIGH);
}
void nomove()
{
digitalWrite(motor_left[0],LOW);
digitalWrite(motor_left[1],LOW);
digitalWrite(motor_right[0],LOW);
digitalWrite(motor_right[1],LOW);
}
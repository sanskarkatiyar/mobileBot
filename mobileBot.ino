int motor_left[]={2,3};
int motor_right[]={4,5};

int D[4] = {11,10,9,8};
int r[4] = {0,0,0,0};

void setup()
{
    Serial.begin(9600);
    for(int i=0;i<2;i++)
    {
        pinMode(motor_left[i],OUTPUT);
        pinMode(motor_right[i],OUTPUT);
    }

    for(int i=0;i<4;i++)
    {
        pinMode(D[i],INPUT);
    }

} //end of void setup

void loop()
{
    //r[0]=digitalRead(D[3]); //r1 to r4 get the values of D3 to D0 respectively
    //r[1]=digitalRead(D[2]);
    //r[2]=digitalRead(D[1]);
    //r[3]=digitalRead(D[0]);
    
    for(int i=0;i<4;i++)
    {
      r[i] = digitalRead(D[3-i]);
    }

    if(r[0]==LOW&&r[1]==LOW&&r[2]==HIGH&&r[3]==LOW) // Binary 0010 ; Decimal 2
    { 
        Serial.println("Moving Forward");
        moveforward();
    }

    if(r[0]==LOW&&r[1]==HIGH&&r[2]==LOW&&r[3]==LOW) // Binary 0100 ; Decimal 4
    { 
        Serial.println("Moving Left");
        moveleft();
    }

    if(r[0]==LOW&&r[1]==HIGH&&r[2]==LOW&&r[3]==HIGH) // Binary 0101 ; Decimal 5
    { 
        Serial.println("Not moving");
        nomove();
    }

    if(r[0]==LOW&&r[1]==HIGH&&r[2]==HIGH&&r[3]==LOW) // Binary 0110 ; Decimal 6
    { 
        Serial.println("Moving Right");
        moveright();
    }

    if(r[0]==HIGH&&r[1]==LOW&&r[2]==LOW&&r[3]==LOW) // Binary 1000 ; Decimal 8
    { 
        Serial.println("Moving Backward");
        movebackward();
    }

}

//function declarations
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

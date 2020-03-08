char j;
String iS="";
#include<AFMotor.h>
#include<SoftwareSerial.h>
SoftwareSerial bt(9,10);

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor3(3, MOTOR12_64KHZ); // create motor #3, 64KHz pwm
AF_DCMotor motor4(4, MOTOR12_64KHZ); // create motor #4, 64KHz pwm

//const



void setup()
{
   if(bt.available())
   {
    char k = (char)bt.read();
   }
 
  if ( k == "Q" )
  {
    
  }
  if ( k == "U" )
  {
   
    bt.begin(9600);
    Serial.begin (9600);
  } 
  
    motor1.setSpeed(190);//Can be set from 0-255
    motor2.setSpeed(190);//Can be set from 0-255
    motor3.setSpeed(190);//Can be set from 0-255
    motor4.setSpeed(190);//Can be set from 0-255
    
  
}

void loop()
{
  
  if(bt.available())
    {
      char iC = (char)bt.read();
      iS = iC; 
      //Serial.println(iS);
      bt.println(iS);  
          
    }
    else
    {
      //Serial.println(iS);
      bt.println(iS);
    }
    
    
    while (bt.available() > 0)  
    { j = bt.read() ; }     
    if(iS == "F"){  //To move forward      
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
    }else if(iS == "B"){ //To move backward 
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
    }
     else if(iS == "L"){  //To move left
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
    }
    else if(iS == "R"){//To move right 
     motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
    else if(iS == "S"){  //To stop
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
    else if (iS == "I") // RIGHT FORWARD
    {
      motor1.run(RELEASE);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(RELEASE);
    }
      else if (iS == "G") // LEFT FORWARD
    {
      motor1.run(BACKWARD);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(BACKWARD);
    }
    
    delay(100);
   //iS = "";

}

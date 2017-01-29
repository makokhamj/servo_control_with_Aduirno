// THIS SECTION FOR THE JOYSTICK
//__________________________________________________________________________________________

// Joystick's x- and y- axes are connected to A0 and A1 analog pins of Arduino.
// By Explore Labs

// include the SoftwareSerial library so you can use its functions:
#include <SoftwareSerial.h>
#include <Servo.h>



SoftwareSerial mySerial(9,10);  // Rx, Tx

//int xPosition = 0;
//int yPosition = 0;
int outPin9 = 9;   // first output set to pin 9
int outPin10 = 10;   // second outpiut set to pin 10
int val9 = 0;     // variable to store the read value
int val10 = 0;     // variable to store the read value
int buttonState = 0;

int joyX = A0; // analog pin used to connect the X - axis of Joystick
int joyY = A1; // analog pin used to connect the Y - axis of Joystick
int x, y; // variables to read the values from the analog pins 

 
void setup()
{ 
  Serial.begin(9600);   // initialize serial communications at 9600 bps:
}


void loop()
{  
  x = analogRead(joyX);
  //xPosition = map(x, 0, 1023, 0, 5); // scale it to use with the servo b/w 900 usec to 2100 usec
  y = analogRead(joyY);
  //yPosition = map(y, 0, 1023, 0, 5);
  
  digitalWrite(outPin9, x);    // sets the LED to the button's value
  digitalWrite(outPin10, y);    // sets the LED to the button's value

  
  buttonState = digitalRead(buttonState);

 // USE THIS TO VIEW IN/OUT VALUES 
    
  Serial.print("X: ");
  Serial.print(x); 
  Serial.print(" | X-Pos: ");
  Serial.print(xPosition);
  Serial.print(" | | Y: ");
  Serial.print(y);
  Serial.print(" | | | Y-Pos: ");
  Serial.print(yPosition);
  Serial.print(" | | | | Button: ");
  Serial.println(buttonState);
  delay(500); // add some delay between reads

  
 // delay(15); // waits for the servos to get there 
}


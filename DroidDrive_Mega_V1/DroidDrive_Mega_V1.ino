/*******************************************************************************
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
 * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 ********************************************************************************
 * DESCRIPTION:
 *
 * This example shows how to drive 2 motors using the PWM and DIR pins with
 * 2-channel motor driver.
 * 
 * 
 * CONNECTIONS:
 * 
 * Arduino D3  - Motor Driver PWM 1 Input
 * Arduino D4  - Motor Driver DIR 1 Input
 * Arduino D9  - Motor Driver PWM 2 Input
 * Arduino D10 - Motor Driver DIR 2 Input
 * Arduino GND - Motor Driver GND
 *
 *
 * AUTHOR   : Kong Wai Weng
 * COMPANY  : Cytron Technologies Sdn Bhd
 * WEBSITE  : www.cytron.io
 * EMAIL    : support@cytron.io
 *
 *******************************************************************************/

 #include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD motor1(PWM_DIR, 3, 4);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 9, 10); // PWM 2 = Pin 9, DIR 2 = Pin 10.

//Setup RC Channels
int pin1 = 6;  // This is input for RC (tank mixed) drive 1
int pin2 = 7;  // This is input for RC (tank mixed) drive 2
int pin3 = 5;  // This in input for RC Speed select

int duration1 = 1500; // Duration of the pulse from the RC
int duration2 = 1500; // Duration of the pulse from the RC
int duration3 = 1500; // Duration of the pulse from the RC

int motorspeed1 = 0;
int motorspeed2 = 0;

float time;

int speedselect = 255;

// The setup routine runs once when you press reset.
void setup() {

  // Serial.begin(9600); // ** uncomment to allow debugging**
  
  time = millis(); ///////////////STARTS COUNTING TIME IN MILLISECONDS/////////////

  duration1 = pulseIn(pin1, HIGH); //Measures the input from rc drive 1
  duration2 = pulseIn(pin2, HIGH); //Measures the input from rc drive 2

  
  while ( duration1 >2200||duration1<800) {
  duration1 = pulseIn(pin1, HIGH); //Measures the input from rc drive 1  //this loops until it get a signal from RC, nothing will run
  }
  while ( duration2 >2200||duration2<800) {                               //this loops until it get a signal from RC, nothing will run
  duration2 = pulseIn(pin2, HIGH); //Measures the input from rc drive 1  
  }
  
}


// The loop routine runs over and over again forever.
void loop() {

duration1 = pulseIn(pin1, HIGH); //Measures the input from rc drive 1
duration2 = pulseIn(pin2, HIGH); //Measures the input from rc drive 2
duration3 = pulseIn(pin3, HIGH); //Measures the input from rc speed select

motorspeed1 = map (duration1,1100,1900,-255,255); //Maps the duration to the motorspeed from the stick
motorspeed2 = map (duration2,1100,1900,-255,255); //Maps the duration to the motorspeed from the stick

// Sets Speed based in Switch/Channel 9
// Default sets speed to 0
// Position 1 sets speed to 1/6th the max
// Position 3 sets speed to 1/4th the max

if (duration3 < 1000) {
   speedselect = 255;
  }

if ((duration3 > 1000) && (duration3 < 1600)){
   speedselect = 6;
  }

if ((duration3 > 1600) && (duration3 < 2000)){
   speedselect = 4;
  }

// Set Motor Speeds
  motor1.setSpeed(motorspeed1/speedselect);  // Motor 1 runs at RC input.
  motor2.setSpeed(motorspeed2/speedselect);   // Motor 2 runs RC Input.

//** Debugging below

//Serial.print (motorspeed1/speedselect);
//Serial.print (" ");
//Serial.print (motorspeed2/speedselect);
//Serial.print (" ");
//Serial.print (duration1);
//Serial.print (" 8");
//Serial.print (duration2);
//Serial.print (" ");
//Serial.print (duration3);
//Serial.print (" ");
//Serial.print (speedselect);
//Serial.print (" ");
//Serial.println (**);
//delay(100);
  

}
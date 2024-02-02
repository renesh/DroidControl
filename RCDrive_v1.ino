// #include <Wire.h>

////////////////VARIABLE DEFINATION///////////////
int dir1pin =13; //Motor Direction pin (goes to DIR1)
int spe1pin =12; //Motor Speed pin (goes to PWM1)
int dir2pin =11; //Motor Direction pin (goes to DIR2)
int spe2pin =10; //Motor Speed pin (goes to PWM2)
int mspeed = 10; 
int turnspeed=50; 

int pin1 = 3;  // This is input for RC (tank mixed) drive 1
int pin2 = 4;  // This is input for RC (tank mixed) drive 2
int duration1 = 1500; // Duration of the pulse from the RC
int duration2 = 1500; // Duration of the pulse from the RC
int motorspeed1 = 0;
int motordirection1 = HIGH;
int motorspeed2 = 0 ;
int motordirection2 = HIGH;

float time;

void setup() {
// Wire.begin(); /////////////TO BEGIN I2C COMMUNICATIONS///////////////
//   Wire.beginTransmission(0x68);
//   Wire.write(0x6B);
//   Wire.write(0);
//   Wire.endTransmission(true);
  ////////////////PIN MODE DEFINATIONS//////////////////////
  pinMode(dir1pin,OUTPUT);
  pinMode(spe1pin,OUTPUT);
  pinMode(dir2pin,OUTPUT);
  pinMode(spe2pin,OUTPUT);
  
  Serial.begin(9600); // ** uncomment to allow debugging**
  
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

void loop() {
  // put your main code here, to run repeatedly:
duration1 = pulseIn(pin1, HIGH); //Measures the input from rc drive 1
duration2 = pulseIn(pin2, HIGH); //Measures the input from rc drive 2

motorspeed1 = map (duration1,1000,2000,-255,255); //Maps the duration to the motorspeed from the stick
motorspeed2 = map (duration2,1000,2000,-255,255); //Maps the duration to the motorspeed from the stick



if (motorspeed1<0) {
  motordirection1 = LOW;
  motorspeed1=-motorspeed1;
}

else if (motorspeed1>0) {
 motordirection1 = HIGH;  
}

if (motorspeed2<0) {
  motordirection2 = LOW;
  motorspeed2=-motorspeed2;
}

else if (motorspeed2>0) {
 motordirection2 = HIGH;  
}

if (motorspeed1 >254){
  motorspeed1=255;
}

if (motorspeed2 >254){
  motorspeed2=255;
}

Serial.print (motorspeed1);
Serial.print (" ");
Serial.print (motorspeed2);
Serial.println (" ");

digitalWrite(dir1pin,motordirection1);
analogWrite(spe1pin,motorspeed1); //increase the speed of the motor from 0 to 255
digitalWrite(dir2pin,motordirection2);
analogWrite(spe2pin,motorspeed2); //increase the speed of the motor from 0 to 255



}


//Setup for RC Switch 7 and 8 to control Persicope and Doors/Arms animation

#include <PololuMaestro.h>
#include <SoftwareSerial.h>



// ** Animations

// Define pins
int pin7 = 10;
int pin8 = 11;

// PWM Durations
int duration7 = 1500;
int duration8 = 1500;

// Setup Channels
int chn7 = -10;
int chn8 = -10;

SoftwareSerial maestroSerial(7, 8); //Pin 7 RX, Pin 8 TX
MiniMaestro maestroHead(maestroSerial);

void setup() {

//Serial.begin(19200); //** Uncomment for debugging
maestroSerial.begin(9600);

}

void loop() {

// ** RC

duration7 = pulseIn(pin7, HIGH); 
duration8 = pulseIn(pin8, HIGH); 

chn7 = map (duration7,1000,2000,-255,255);
chn8 = map (duration8,1000,2000,-255,255);


// ** Debugging
 //Serial.print ("chn7: ");
 //Serial.print (chn7);
 //Serial.print (" | ");
 //Serial.print ("chn8: ");
 //Serial.print (chn8);
 //Serial.print (" | ");
 //Serial.println();  // Move to the next line for better readability
 //delay(200);  // Adjust the delay based on your desired update rate


// ** Trigger Animations
// Add BEGIN and QUIT to POLOLU CONTROL AFTER SEQUENCE/SCRIPT IS GENERATED

//Switch 7 - Periscope - 
  if (chn7 > 0) {
   maestroHead.restartScript(0); //Activate Periscope 
   //delay(13200); // Add a delay if necessary
   //maestroHead.stopScript();
  }

//Switch 8 - Doors and Arms - 
 if (chn8 > 0) {
   maestroHead.restartScript(2); //Activate Doors and Arms 
   //delay(1000); // Add a delay if necessary
 }


}

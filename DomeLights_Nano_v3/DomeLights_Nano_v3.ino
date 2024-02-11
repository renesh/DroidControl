// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// ** Lights **
// Which pin on the Arduino is connected to the NeoPixels?

#define PIN1        4 //  Left Eye
#define PIN2        5 //  Ladder Light
#define PIN3        6 // Mid Eye
const int ledPin = 13; //right eye - 220ohm resistor needed

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS1 9 // Left Eye
#define NUMPIXELS2 16 // Dual Ladder
#define NUMPIXELS3  9 // Mid Eye

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.

Adafruit_NeoPixel pixel1(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800); // left eye
Adafruit_NeoPixel pixel2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800); //ladder
Adafruit_NeoPixel pixel3(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800); //mid eye

#define DELAYVAL 180 // Time (in milliseconds) to pause between pixels default 280


void setup() {

Serial.begin(9600);
//maestroSerial.begin(9600);

pixel1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
pixel2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
pixel3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
pinMode(ledPin, OUTPUT); // INITIALIZE LED output)

}

void loop() {

// ** Lights

digitalWrite(ledPin, HIGH);

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
 for(int i=0; i<NUMPIXELS1; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately blue color:
   
 
        pixel1.setPixelColor(i, pixel1.Color(0, 0,90));
        pixel3.setPixelColor(i, pixel3.Color(0, 0,90));
    

    pixel1.show();   // Send the updated pixel colors to the hardware.
    pixel3.show();
    
  }

  for(int i=0; i<NUMPIXELS2; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a red color:
    // Ladder Light
   
    pixel2.setPixelColor(i, pixel2.Color(125, 0,0));
       pixel2.setPixelColor(i-1, pixel2.Color(50, 0,0));
       pixel2.setPixelColor(i-2, pixel2.Color(5, 0,0));

    pixel2.show();   // Send the updated pixel colors to the hardware.

   delay(DELAYVAL); // Pause before next pass through loop
  }

  for(int i=16; i>-1; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a red color:
 
    pixel2.setPixelColor(i, pixel2.Color(125, 0,0));
    pixel2.setPixelColor(i+1, pixel2.Color(50, 0,0));
        pixel2.setPixelColor(i+2, pixel2.Color(5, 0,0));
    pixel2.show();   // Send the updated pixel colors to the hardware.

   delay(DELAYVAL); // Pause before next pass through loop
  }

}

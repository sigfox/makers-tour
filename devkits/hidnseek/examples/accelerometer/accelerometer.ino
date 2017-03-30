#include <SoftwareSerial.h>
#include "Wire.h"
#include "MMA8653.h"

MMA8653 accelerometer;

#define ACCEL_HIGHRES false
#define ACCEL_SCALE 2
#define ACCEL_DELAY 10
#define ACCEL_SENSITIVITY 2

#define SIGFOX_RX 8
#define SIGFOX_TX 5

#define BLUE_LED 6
#define RED_LED 7
//Communication with the Sigfox-ready TD1207 module
SoftwareSerial sigfox(SIGFOX_TX, SIGFOX_RX);

//time buffers
unsigned long previousMillis = 0;

//accel buffers
int8_t x, y, z;
void setup() {
  //turn the lights off
  turnLEDOff(BLUE_LED);
  turnLEDOff(RED_LED);
  
  //Init accel
  accelerometer.begin(ACCEL_HIGHRES, ACCEL_SCALE);
  sigfox.begin(9600);
  delay(500);
  x = accelerometer.getX();
  y = accelerometer.getY();
  z = accelerometer.getZ();
  
  flashLED(BLUE_LED, 10);
}  

void loop(){
  listenToSigfoxModule();
  if (millis() - previousMillis >= ACCEL_DELAY) {
//  flashLED(RED_LED, 3);
    if (didItMove()){
      
      flashLED(BLUE_LED, 3);
      sigfox.write("AT$SB=1\r");
      delay(60000);
    }
  }
}
void listenToSigfoxModule(){
  while(sigfox.available()){
    sigfox.read();
    flashLED(BLUE_LED,1);
  }

}
bool didItMove(){
 bool moved =  ((uint8_t)(abs((int8_t)(accelerometer.getX() - x))) > ACCEL_SENSITIVITY) ? true :
                ((uint8_t)(abs((int8_t)(accelerometer.getY() - y))) > ACCEL_SENSITIVITY) ? true :
                ((uint8_t)(abs((int8_t)(accelerometer.getZ() - z))) > ACCEL_SENSITIVITY) ? true : false;
                
  x = accelerometer.getX();
  y = accelerometer.getY();
  z = accelerometer.getZ();
  
  
//  sigfox.write("AT$SB=");
//  sigfox.write(moved ? "1" : "0");
//  sigfox.write("\r");
  return true;
  return moved;
}
//Play with onboard LEDs
//// Colours : 6=blue, 7=red
void turnLEDOn(int color){
    PORTD |= (1 << color);
}
void turnLEDOff(int color){
    PORTD &= ~(1 << color);
}
//Flash LED a given number of times
void flashLED(int color, int num){
  while (num > 0) {
        turnLEDOn(color);
        delay(50);
        turnLEDOff(color);
        if (--num)
            delay(50);
    }
}


/**
*
* This sample simply sends a single-bit message through the sigfox network
* It relies on AT command to send the sigfox message
* No underlying libs, to have a good understanding of what's at stake when it comes to enabling sigfox communication
* AT commands reference available here : https://github.com/Telecom-Design/Documentation_TD_RF_Module/blob/master/TD1207%20Reference%20Manual.pdf
*
*/

#include <SoftwareSerial.h>
#define SIGFOX_RX 8
#define SIGFOX_TX 5
#define BLUE_LED 6
#define RED_LED 7
//Communication with the Sigfox-ready TD1207 module
SoftwareSerial sigfox(SIGFOX_TX, SIGFOX_RX);
void setup() {
  //turn the lights off
  turnLEDOff(BLUE_LED);
  turnLEDOff(RED_LED);
  
  sigfox.begin(9600);
  delay(500);
  flashLED(RED_LED,10);
  //Send AT command to the Sigfox-ready TD1208 module
  // AT$SB : send single bit (AT$SB=0|1)
  // AT$SF : send frame AT$SF=A012 (hex, up to 12bytes)
  // AT$SF=1234,2,1 : send 0x12 0x34 and request downlink response
  sigfox.write("AT$SF=12ABCAFE,2,1\r");


}  

void loop() {
  while(sigfox.available()){
    sigfox.read();
    flashLED(BLUE_LED,1);
  }

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


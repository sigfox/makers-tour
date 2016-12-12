#include "HidnSeek.h"

HidnSeek HidnSeek(txSigfox, rxSigfox); // HidnSeek talks to the Sigfox Module via Serial

void setup() {
  HidnSeek.begin(); // Initialises the Device
  uint8_t rev = HidnSeek.getRev(); // Retreives Board Version
  delay(1000);
}

void loop() {
   HidnSeek.sendMessage("AT$SF=1234cafe"); // AT Command to the Sigfox Module to transmit the payload '1234cafe'
   HidnSeek.flashRed(10);
   HidnSeek.NoflashRed();
   delay(600000); // Required to meet ETSI Regulation regarding duty cycle of Sigfox Broadcasts
}

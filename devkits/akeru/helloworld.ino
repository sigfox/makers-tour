#include <SoftwareSerial.h>

SoftwareSerial sigfox(5,4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sigfox.begin(9600);
  
  delay(300);
  
  sigfox.write("AT$SB=1\r");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  while (sigfox.available()){
    Serial.write(sigfox.read());
  }
  
}

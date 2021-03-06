<p align="center"><img src ="./sigfox.png" width="300"></p>

# Copenhagen Makers Tour 2017

Here you'll find information about the Sigfox Makers Tour in Copenhagen.  
We'll help you get started with understanding how Sigfox works, get your Dev Kits setup and provide you with the ideas to get started building your own projects.

### Presentation

You can find the Makers Tour presentation [here](http://www.slideshare.net/nicolsc-slides/sigfox-makers-tour-copenhagen). This covers everything we've spoken about, examples of sigfox use cases and gives you the chance to follow along with what we're talking about!

### Development Kits

The Development Kit we are using for this event is the [Akeru](//www.akeru.cc/). You can find out more by visiting the [Snootlab](//snootlab.com) website.  
The Akeru is basically an [Arduino](//arduino.cc) Uno board, extended with a Sigfox-verified communication module.  
Out of the box, you will have :

* An Atmega328 µC, with the Arduino bootloader. No extra library to install to use it with the Arduino IDE
* A [TD Next](//www.td-next.com/) [TD1208](//github.com/Telecom-Design/Documentation_TD_RF_Module/blob/master/TD1208%20Datasheet.pdf) module, which itself includes
  * A []() transceiver
  * An ARM Cortex-M3 CPU that you could flash with your own firmware using the [TD Next SDK](http://rfmodules.td-next.com/sdk/) if you want to push further your experimentations
  
### Getting Started

#### Setting Up Your Sigfox Account

To get started you'll need the ID and PAC number associated with your Dev Kit. You should have received this in an email from 'devrelations@sigfox.com'.

Once you have these, head to the Sigfox [activate](//backend.sigfox.com/activate) platform. Select `Snootlab` for your dev kit provider and `IoT DK` as your Sigfox operator.

You'll then be asked to enter the ID and PAC of the device that you were given earlier, and then your personal information: name, email, company info, ... 

You should receive an automated email from Sigfox asking you to verify you account. Click the link and accept the terms & conditions to start using the platform.

Congratulations! You're all ready to go! Now let's get you sending your first message...!

#### Sending Your First Message

Sample codes are available [here](https://github.com/sigfox/makers-tour/tree/master/devkits/akeru)

Here is the basic "Hello World" sample, which is fact sending `1`, using the `AT$SB` command

```
#include <SoftwareSerial.h>
//The TD1208 is hardwired to pins 5 & 4
SoftwareSerial sigfox(5,4);
void setup() {
  //Setup serial communications
  Serial.begin(9600);
  sigfox.begin(9600);
  
  delay(300);
  
  //Send a Single Bit over the Sigfox Network
  sigfox.write("AT$SB=1\r");
  

}

void loop() {
  //Debug: Forward  module output to serial monitor
  while (sigfox.available()){
    Serial.write(sigfox.read());
  }
  
}
```



### Additional Resources

* [Sigfox Developer Portal](https://makers.sigfox.com)
* [Sigfox Q&A](//ask.sigfox.com)
* [Sigfox Github](//github.com/sigfox)
* [Hackster.io](https://hackster.io/sigfox)

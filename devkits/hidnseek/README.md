<p align="center"><img src ="./sigfox.png" width="300"></p>
# HidnSeek Development Kit

This folder contains the documentation for the HidnSeek to be used as a Sigfox Development Kit. Much of the core device functionality such as its sports mode and low power loops have been abstracted away to allow for a developer to call these methods into their own projects.

Built on the ATMega328P chip (same as the Arduino Uno), the HidnSeek makes for a great kit to start developing your own Sigfox projects. The device consists of user accessible -

* TD 1207 Sigfox Module
* MMA8653 Accelerometer
* BMP180 Barometer/Pressure Sensor
* MTK MT3339 GPS
* MCP7383 1/2 LiPo Charging Circuit
* UART and I2C Interfaces

You can find documentation outlining all of the accessible methods for the HidnSeek as well as example sketches and templates to get started with the device.

### Getting Started

To send your first Sigfox message, follow along to install the correct libraries/boards within the Arduino IDE.

#### Arduino IDE Setup

The first thing you will need to do is to download the latest release of the Arduino IDE. You will need to be using version **1.6.4** or higher for this guide.

[Arduino IDE v1.6.x](http://www.arduino.cc/en/Main/Software)

After you have downloaded and installed **v1.6.4**, you will need to start the IDE and navigate to the **Preferences** menu. You can access it from the **File** menu in Windows/Linux or the **Arduino** menu on OS X.

A dialog will pop up and you will need to add a URL to the new **Additional Boards Manager URLs** option. The list of URLs is comma separated and you will only have to add each URL once. New HidnSeek board and updates to existing boards will automatically be picked up by the Board Manager each time it is opened.

To find the most up to date list of URLs you can add, you can visit the list of [third party board URLs](https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls#list-of-3rd-party-boards-support-urls) on the Arduino IDE wiki. We will only need to add one URL to the IDE in this example but you can add multiple URLS by separating them with commas. Copy and paste the link below into the **Additional Boards Manager URLs** option in the Arduino IDE preferences.

[https://hidnseek.github.io/hidnseek/package_hidnseek_boot_index.json](https://hidnseek.github.io/hidnseek/package_hidnseek_boot_index.json)

Click **OK** to save the new settings. Next we will look at installing the new boards within the Board Manager.

##### Installing Boards

Now that you have added the appropriate URLs to the Arduino IDE preferences, you can open the **Boards Manager** by navigating to the **Tools->Board** menu. Find and install **USBaspLoader HidnSeek** board.

Then, **quit and reopen the Arduino IDE** to ensure that all of the boards are properly installed. You should now be able to select and upload to the new boards listed in the **Tools->Board** menu.

##### USBasp Drivers for Windows
* **Windows up to 7.x** : [usbasp-windriver.2011-05-28.zip](https://github.com/hidnseek/hidnseek/blob/master/Drivers/usbasp-windriver.2011-05-28.zip)
* **Windows 8.1 to 10.x** : [USBasp-win-driver-x86-x64-v3.0.7.zip](https://github.com/hidnseek/hidnseek/blob/master/Drivers/USBasp-win-driver-x86-x64-v3.0.7.zip)

The USBASP windows driver was previously based on libusb-win32. The certificate on the base drivers have expired and the library has now been superseded by libusbK. You can now download the new version from the location below.

 [http://www.protostack.com/download/USBasp-win-driver-x86-x64-v3.0.7.zip] (http://www.protostack.com/download/USBasp-win-driver-x86-x64-v3.0.7.zip)

This driver should work with any version of Windows XP right through to 8.1 and 10 (both 32 and 64 bit editions). As the driver is signed, there should be no need to disable driver certificate enforcement.

#### Installing the Required libraries

In order to use all of the included sensors (including Sigfox!), you will need to **install the required libraries**. To do this, navigate to the [Library](../hidnseek/library) folder. Here you will find a .zip file called 'hidnseek.zip'. Extract the HidnSeek-libs.zip file and install each of the contained libraries into your Arduino IDE (*Sketch->Include Library->Add .zip Library*). Include the required libraries with your .ino sketch. If required, you can access the uncompressed versions of the library from here as well.

#### Flashing the HidnSeek (DFU Mode)

To upload your arduino sketches to the HidnSeek, ensure that you have the correct board selected in the **Board Manager** and that you are using the **USBasp** programmer.

In order to actually upload the code to the arduino, the device must be placed into DFU mode (Direct Firmware Update). There are two methods to prepare HidnSeek for DFU mode.

1. You can put the device in DFU mode by using the series of accelerometer that is specified in the HidnSeek's [manual](https://github.com/hidnseek/hidnseek/blob/master/docs/Manual_en_A.pdf).

2. **Create a short circuit between R & G pins**. *Be aware you will lose anything stored in the EEPROM*. Once you have done this, you can plug a USB cable into you computer and the HidnSeek board. You will then see between 30 and 60 red flashes of device's LED to notify you that you are in DFU mode. Click on the upload button within the Arduino IDE. Uploading a sketch should take less than 4 seconds. Ignore the warnings about the clk speed. Your sketch will start after the booting up period (0-30 seconds).

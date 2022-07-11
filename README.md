# Instructions for connecting to Blynk
First, an account needs to be created and the template needs to be created for the device.

https://user-images.githubusercontent.com/61054742/178245816-6d789653-511f-4851-b10d-da3028e63053.mp4

Next, the device can be created from the template. It is reccomended to give the device the name ESP8266 as that is the name of the model of the actual WiFi chip.

https://user-images.githubusercontent.com/61054742/178246284-8c174537-407d-4bce-8562-e044831bb400.mp4

Also add the datastream from a "Virtual pin" in the code to the Blynk service with same parrameters as below.

https://user-images.githubusercontent.com/61054742/178246493-479287f8-048b-451b-beab-f56cbcc1e800.mp4

To connect the device to Blynk services, edit the section of the code with the apropriate template name, device name and authentification code.

```c++
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_DEVICE_NAME           ""
#define BLYNK_AUTH_TOKEN            ""
```

This can be directly replaced by the code in the Blynk.Console web app in the devices -> device info section.

<img width="1280" alt="image" src="https://user-images.githubusercontent.com/61054742/178246928-ddb60d85-0f43-454c-a82d-4b16e174e3e8.png">

The WiFi name (SSID) and password can also be added.

```c++
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";
BlynkTimer timer;
```

Everything mentioned above can be found in the "../esp8266/esp8266.ino" file under section in code:

```c++
/*************************************************************
  BLYNK STUFF
 *************************************************************/
```
Arduino IDE can be used to upload the code. There are many quality tutorials on YouTube and web on how to prepare the IDE for upload to ESP8266. <br />
For example: https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/ <br />
IMPORTANT: To upload the code to the ESP8266 it is necesarry to first pull out the two jumpers present on the "controll board" near the on/off switch. These jumpers are responsible for completing the serial conections between the Arduino UNO and ESP8266. They need to be severed before uploading the code. <br />
To debug the connection to Blynk use the Serial Monitor in Arduino IDE while the ESP8266 is selected as the current device.

To view the data on a smarthphone, first the Blynk IoT app needs to be downloaded. <br />

Android app: <br />
<img width="111" alt="image" src="https://user-images.githubusercontent.com/61054742/178236788-df0333b9-3734-495c-8088-5d98f2c5cd31.png">
 <br />
 <br />
iOS app: <br />
<img width="114" alt="image" src="https://user-images.githubusercontent.com/61054742/178236907-0429ac34-dd39-448d-af86-f860b52e4b4e.png">
<br />
<br />
*NOTE: The guide focuses on setting up the Android application. There might be a few differences betwen this and iOS version.*

Turn on the developer mode and press the newly created template. Add the SuperChart widget and also select the newly created datastream.

https://user-images.githubusercontent.com/61054742/178247035-affe4084-2c7c-4d0d-8932-72f034eedab5.mp4

To view the graph just tap on the newly created device in the main menu.
# LICENSE
GNU GPL: https://gnu.org/licenses/gpl.html <br />
Capacitance calculation code: https://github.com/codewrite/arduino-capacitor <br />
Cloud readout service: https://blynk.io/ <br />
ESP8266 Arduino IDE plugin: https://github.com/esp8266/Arduino

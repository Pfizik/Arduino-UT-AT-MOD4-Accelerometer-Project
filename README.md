# Instructions for connecting to Blynk
First, an account needs to be created and the template needs to be created for the device.

<img src="https://media.giphy.com/media/QinG8WsTdw6d6pSvZY/giphy.gif"/>

Next, the device can be created from the template. It is reccomended to give the device the name ESP8266 as that is the name of the model of the actual WiFi chip.

<img src="https://media.giphy.com/media/2HAIhLqkaxUukvK3ET/giphy.gif"/>

To connect the device to Blynk services, edit the section of the code with the apropriate template name, device name and authentification code.

```c++
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_DEVICE_NAME           ""
#define BLYNK_AUTH_TOKEN            ""
```

This can be directly replaced by the code in the Blynk.Console web app in the devices -> device info section.

<img width="799" alt="image" src="https://user-images.githubusercontent.com/61054742/178225154-4a498ba0-1ec6-43db-80c5-c64a5ea24fef.png">

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

To view the data on a smarthphone, first the Blynk IoT app needs to be downloaded. <br />
Android app:
<img width="111" alt="image" src="https://user-images.githubusercontent.com/61054742/178236788-df0333b9-3734-495c-8088-5d98f2c5cd31.png">

iOS app:
<img width="114" alt="image" src="https://user-images.githubusercontent.com/61054742/178236907-0429ac34-dd39-448d-af86-f860b52e4b4e.png">

# LICENSE
GNU GPL: https://gnu.org/licenses/gpl.html <br />
Capacitance calculation code: https://github.com/codewrite/arduino-capacitor <br />
Cloud readout service: https://blynk.io/ <br />
ESP8266 Arduino IDE plugin: https://github.com/esp8266/Arduino

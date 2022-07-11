# Instructions for connecting to Blynk
First, an account needs to be created and the template needs to be created for the device.

<img src="https://media.giphy.com/media/QinG8WsTdw6d6pSvZY/giphy.gif"/>

To connect the device to Blynk services, edit the section of the code with the apropriate template name, device name and authentification code.

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_DEVICE_NAME           ""
#define BLYNK_AUTH_TOKEN            ""

This can be directly replaced by the code in the Blynk.Console web app in the devices -> device info section.

<img width="799" alt="image" src="https://user-images.githubusercontent.com/61054742/178225154-4a498ba0-1ec6-43db-80c5-c64a5ea24fef.png">

# LICENSE
GNU GPL: https://gnu.org/licenses/gpl.html <br />
Capacitance calculation code: https://github.com/codewrite/arduino-capacitor <br />
Cloud readout service: https://blynk.io/ <br />
ESP8266 Arduino IDE plugin: https://github.com/esp8266/Arduino

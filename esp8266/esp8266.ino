

/*************************************************************
  BLYNK STUFF
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_DEVICE_NAME           ""
#define BLYNK_AUTH_TOKEN            ""


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <EEPROM.h>
#define EEPROM_SIZE 12
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";
BlynkTimer timer;

/*************************************************************
  BLYNK STUFF
 *************************************************************/


/*************************************************************
  VARIABLES
 *************************************************************/
float c1, c2;
float a1, a2, a;
float levelC1, levelC2;
float maxC1, maxC2;
float dC1, dC2;
float coeffC1, coeffC2;
String calText;
int checkLevel = 0;
int checkC1 = 0;
int checkC2 = 0;
float dataSample[10];
/*************************************************************
  VARIABLES
 *************************************************************/

/*
  float avg(int cNumber)
  {
  if (cNumber == 1)
  {
    float sum = 0;
    for (int i = 0; i < 10; i++)
    {
      sum = +c1;
    }
    return (sum / 10);
  } else
  {
    float sum = 0;
    for (int i = 0; i < 10; i++)
    {
      sum = +c2;
    }
    return (sum / 10);
  }
  }

  BLYNK_WRITE(V0)
  {
  levelC1 = c1;
  levelC2 = c2;
  Serial.print(levelC1);
  Serial.print(",");
  Serial.println(levelC2);
  checkLevel = 1;
  Blynk.virtualWrite(V3, checkLevel);
  }

  BLYNK_WRITE(V5)
  {
  if (c1 > c2)
  {
    maxC1 = c1;
  } else
  {
    maxC2 = c2;
  }
  checkC1 = 1;
  Blynk.virtualWrite(V8, checkC1);
  }

  BLYNK_WRITE(V6)
  {
  if (c1 > c2)
  {
    maxC1 = c1;
  } else
  {
    maxC2 = c2;
  }
  checkC2 = 1;
  Blynk.virtualWrite(V9, checkC2);
  }

  BLYNK_WRITE(V7)
  {
  Serial.print(maxC1);
  Serial.print(",");
  Serial.println(maxC2);

  dC1 = maxC1 - levelC1;
  dC2 = maxC2 - levelC2;

  coeffC1 = 9.81 / dC1;
  coeffC2 = 9.81 / dC2;

  Serial.print(dC1);
  Serial.print(",");
  Serial.println(dC2);

  Serial.print(coeffC1);
  Serial.print(",");
  Serial.println(coeffC2);

  int adress = 0;
  EEPROM.put(adress, coeffC1);
  adress += sizeof(coeffC1);
  EEPROM.put(adress, coeffC2);
  EEPROM.commit();

  checkLevel = 0;
  Blynk.virtualWrite(V3, checkLevel);
  checkC1 = 0;
  Blynk.virtualWrite(V8, checkC1);
  checkC2 = 0;
  Blynk.virtualWrite(V9, checkC2);

  calText = "Calibration complete!";
  Blynk.virtualWrite(V1, calText);
  delay(2000);
  calText = "Calibrate each side of the device.";
  Blynk.virtualWrite(V1, calText);
  }

  BLYNK_WRITE(V4)
  {
  checkLevel = 0;
  Blynk.virtualWrite(V3, checkLevel);
  checkC1 = 0;
  Blynk.virtualWrite(V8, checkC1);
  checkC2 = 0;
  Blynk.virtualWrite(V9, checkC2);
  int adress = 0;
  coeffC1 = 1.11;
  coeffC2 = 1.11;
  EEPROM.put(adress, coeffC1);
  adress += sizeof(coeffC1);
  EEPROM.put(adress, coeffC2);
  EEPROM.commit();
  calText = "Device needs calibration! Calibrate each side of the device.";
  Blynk.virtualWrite(V1, calText);
  }

*/

void getData()
{
  Blynk.virtualWrite(V2, a);
  /*
    c1 = Serial.parseFloat();
    c2 = Serial.parseFloat();
    Serial.print(c1);
    Serial.print(c2);

    a1 = (c1 - levelC1) * coeffC1;
      /
    Blynk.virtualWrite(V2, a);
    /*
      a2 = (c2 - levelC2) * coeffC2;
      Blynk.virtualWrite(V11, (a2/9.81));
  */
}


void setup()
{
  //EEPROM.begin(EEPROM_SIZE);
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  /*
    int adress = 0;
    EEPROM.get(adress, coeffC1);
    adress += sizeof(coeffC1);
    EEPROM.get(adress, coeffC2);
    Serial.print(coeffC1);
    Serial.print(",");
    Serial.println(coeffC2);
    checkLevel = 0;
    Blynk.virtualWrite(V3, checkLevel);
    checkC1 = 0;
    Blynk.virtualWrite(V8, checkC1);
    checkC2 = 0;
    Blynk.virtualWrite(V9, checkC2);

    if (coeffC1 == 1.11)
    {
      calText = "Device needs calibration! Calibrate each side of the device.";
      Blynk.virtualWrite(V1, calText);
    } else if (coeffC2 == 1.11)
    {
      calText = "Device needs calibration! Calibrate each side of the device.";
      Blynk.virtualWrite(V1, calText);
    } else
    {
      calText = "Calibrate each side of the device.";
      Blynk.virtualWrite(V1, calText);
    }
  */
  timer.setInterval(100L, getData);
}


void loop()
{
  Blynk.run();
  timer.run();
  a = Serial.parseFloat();
  Serial.println(a);
  /*
    while (Serial.available() > 0)
    {
    a = Serial.parseFloat();
    if (Serial.read() == '\n')
    {
      Serial.print(a);
      Serial.print('\n');
    }
  */
}

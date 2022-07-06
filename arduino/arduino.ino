

/* USB UP (1g)
    C1 = 8.75,
    C2 = 6
*/

/*USB DOWN (-1g)
   C1 = 5
   C2 = 8.75
*/

/*Level
   C1 = 6.35
   C2 = 7.10
*/





/*PREV CODE
     /
  dc1 = cap1.Measure() - level1;
  dc2 = cap2.Measure() - level2;

  a1 = dc1 * slope1;
  a2 = dc2 * slope2;


    c1 = c11 * 100;
    c2 = c21 * 100;

    /*
  Serial.print(a1/9.81);
  Serial.print(",");
  Serial.println(-(a2/9.81));

  /*
    a = (-k * d * (c1 - c2)) / (m * (c1 + c2)) ;

    /*
    c[0] = c1;
    c[1] = c2;

    byte *p = (byte)c;
    for (byte i = 0; i < sizeof(c); i++) {
     Serial.write(p[i]);
     Serial.print('\n');
    }
*/

//#include <EasyTransfer.h>
#include <Capacitor.h>
Capacitor cap1(7, A0);
Capacitor cap2(7, A1);
//EasyTransfer ET;

float c1, c2, dc1, dc2, a1, a2, ar, a;
float level1 = 6.79;
float level2 = 5.20;
float maxC1 = 8.95;
float maxC2 = 7.25;
float slope1, slope2;
float d_0 = 0.018;
float k = 343;
float m = 0.148;
float constant;
float offset = 5;


/*
  struct SEND_DATA_STRUCTURE
  {
  float c1 = 0;
  float c2 = 0;
  };

  SEND_DATA_STRUCTURE mydata;
*/
void setup() {
  Serial.begin(115200);
  constant = d_0 * (k / m);
  //ET.begin(details(mydata), &Serial);
}



void loop()
{
  /*
    Serial.print("\n");
    Serial.print(cap1.Measure());
    Serial.print("\n");
    Serial.println(cap2.Measure());
  */
  //Serial.print(((cap1.Measure()-6.4)*5.3)/9.81);
  //Serial.print(((cap2.Measure()-7.12)*6.02)/9.81);
  //slope1 = 9.81 / (maxC1 - level1);
  //slope2 = 9.81 / (maxC2 - level2);


  c1 = cap1.Measure();
  c2 = cap2.Measure();

  /*
    dc1 = cap1.Measure() - level1;
    dc2 = cap2.Measure() - level2;

    a1 = dc1 * slope1;
    a2 = -(dc2 * slope2);
    if (abs(a1) < 1 || abs(a2) < 1)
    {
      a = 0;
    }
    else if (abs(a1) > abs(a2))
    {
      a = a1;
    }
    else
    {
      a = a2;
    }
  */
  ar = ((c1 - c2) / (c1 + c2)) * constant;
  a = ar - offset;
  Serial.println(a);
  /*
    Serial.print(cap1.Measure());
    Serial.print(",");
    Serial.println(cap2.Measure());
  */


  /*
    Serial.print(a1/9.81);
    Serial.print(",");
    Serial.println(-(a2/9.81));
    /*
    if (c2 <= c1)
    {
    Serial.print(c1);
    Serial.print('\n');
    } else
    {
    Serial.print(-c2);
    Serial.print('\n');
    }
  */
  //ET.sendData();
  delay(100);
}

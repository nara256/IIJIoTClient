#include <LTE.h>
#include "IIJIoTClient.h"

#define LTE_APN       "apn"      // replace your APN
#define LTE_USER_NAME "user"     // replace with your username
#define LTE_PASSWORD  "password" // replace with your password

LTE lteAccess;
IIJIoTClient c;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  delay(3000);

  while (true) {
    if (lteAccess.begin() == LTE_SEARCHING) {
      if (lteAccess.attach(LTE_APN, LTE_USER_NAME, LTE_PASSWORD) == LTE_READY) {
        Serial.println("attach succeeded.");
        break;
      }
      Serial.println("An error occurred, shutdown and try again.");
      lteAccess.shutdown();
      sleep(1);
    }
  }

  randomSeed(lteAccess.getTime());
  c.setDebugSerial(Serial);
}

void loop()
{
  float value = (float)random(10000) / 100.;

  Serial.println("-----");

  // send data by http
  int s = c.sendByHttp("NAMESPACE", "NAME", value, "KEY", "VALUE");
  if (s == 200)
    Serial.println("OK");
  else
    Serial.println("NG status=" + String(s));

  // send data by UDP
  /*
  if (c.sendByUdp("NAMESPACE", "NAME", value, "KEY", "VALUE")) 
    Serial.println("OK");
  else
    Serial.println("NG");
  */
  
  sleep(60);
}

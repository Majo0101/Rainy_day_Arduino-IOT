#include <NTPClient.h>
#include <WiFiUdp.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org");

void setUpTime(){
  timeClient.begin();
  timeClient.setTimeOffset(7200); // GMT+2 summer
}

String timeActual(){
  timeClient.update();

  int hodina = timeClient.getHours();
  int minuta = timeClient.getMinutes();

  return String(hodina) + ":" + String(minuta);
}

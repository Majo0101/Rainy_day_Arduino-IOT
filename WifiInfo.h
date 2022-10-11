#include "ESP8266WiFi.h"

const int RSSI_MAX =-50;// define maximum strength of signal in dBm
const int RSSI_MIN =-100;// define minimum strength of signal in dBm

bool checkConnection(){
   if(WiFi.status() != WL_CONNECTED){
      return false;
    }else{
      return true;
    }
}

int dbmWifiSignal(){
  return WiFi.RSSI();
}

int percentWifiSignal(int dBm){
  int quality = 0;
    
   if(dBm <= RSSI_MIN){
      quality = 0;
   }else if(dBm >= RSSI_MAX){  
    quality = 100;
   }else{
      quality = 2 * (dBm + 100);
   }
   return quality;
}

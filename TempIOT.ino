#include <Wire.h>

#include "thingProperties.h"
#include "Screen.h"
#include "Led.h"
#include "Sensor.h"
#include "Timers.h"
#include "Time.h"
#include "WifiInfo.h"

int viewCounter = 1;

void CloudColor(){
  int hue = 15;
  int bri = 20;
  int sat = 50;
}

void setup()
{
  Serial.begin(9600);
  delay(1500);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  setUpSensor();
  setUpOled();
  setUpLed();
  setUpTime();
}

void loop()
{
  ArduinoCloud.update();  
  ledColor(tempCelsius());

  if(secClock()){
    serialPrintSensor();
    serialPrintColor();
    
    if(checkConnection()){
      Serial.print("Time: ");
      Serial.print(timeActual());
      Serial.print(", ");
      Serial.print("WiFi signal: ");
      Serial.print(percentWifiSignal(dbmWifiSignal()));
      Serial.println(" %");
    }else{
      Serial.println("Disconnected...");
    }
    
    printScreen(viewCounter, tempCelsius(), humPercent(), heatIndex(), checkConnection(), timeActual());
    viewCounter++;
      if(viewCounter > 4){
        viewCounter = 1;
      }
      if(tempCelsius() != "ERR"){tempServer = tempCelsius().toFloat();}else{tempServer = -127;}
      if(humPercent() != "ERR"){humServer = humPercent().toFloat();}else{humServer = -127;}
      if(heatIndex() != "ERR"){indexServer = heatIndex().toFloat();}else{indexServer = -127;}

   }
}

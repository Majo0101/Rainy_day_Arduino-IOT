#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char THING_ID[]           = "";
const char DEVICE_LOGIN_NAME[]  = "";

const char SSID[]               = "";            // Network SSID (name)
const char PASS[]               = "";                // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]         = "";    // Secret device password

CloudColor colorServer;
float tempServer;
float humServer;
float indexServer;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(colorServer, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(humServer, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(tempServer, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(indexServer, READ, ON_CHANGE, NULL);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

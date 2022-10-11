#include <DHT.h>

#define DHTPIN 14
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);


void setUpSensor(){
  dht.begin();
}

String tempCelsius(){
  float temp = dht.readTemperature();

  if(isnan(temp)){
    return "ERR";
  }else{
   return String(temp - 1, 1); 
  }
}

String humPercent(){
  float hum = dht.readHumidity();
 
  if(isnan(hum)){
    return "ERR";
  }else{
   return String(hum, 1); 
  }
}

String heatIndex(){
  float index = 0;
  
  if(tempCelsius() != "ERR" || humPercent() != "ERR"){
    float temp = tempCelsius().toFloat();
    float hum = humPercent().toFloat();
    index = dht.computeHeatIndex(temp, hum, false);
    return String(index, 1);
  }else{
    return "ERR";
  }
}

void serialPrintSensor(){
    Serial.print("Humidity: ");
    Serial.print(humPercent());
    Serial.print("%, Temperature: ");
    Serial.print(tempCelsius());
    Serial.print("°C, ");
    Serial.print("Heat Index: ");
    Serial.print(heatIndex());
    Serial.println("°C");
}

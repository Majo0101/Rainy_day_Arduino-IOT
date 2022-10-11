#include <FastLED.h>

#define LED_PIN     12
#define NUM_LEDS    1

CRGB leds[NUM_LEDS];

int colorArr[] = {0,0,0};


void setUpLed(){
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

int red(float temp){
  if(temp <= 22){
    return 0;
  }else if(temp >= 27){
    return 50;
  }else{
    return int((temp - 22) * 10);
  }
}

int green(float temp){
  int tmp = 0;

  if(temp < 17 || temp > 27){
    return 0;
  }else{
    tmp = int((22 - temp) * 10);
    return 50 - abs(tmp); 
  }
}

int blue(float temp){
  if(temp >= 22){
    return 0;
  }else if(temp <= 17){
    return 50;
  }else{
   return int((22 - temp) * 10); 
  }
}

void ledColor(String temp){
  float tempNumber = 0;
  
  if(temp != "ERR"){
    tempNumber = temp.toFloat();
    colorArr[0] = red(tempNumber);
    colorArr[1] = green(tempNumber);
    colorArr[2] = blue(tempNumber);
    leds[0] = CRGB(red(tempNumber),green(tempNumber),blue(tempNumber));
    FastLED.show();
  }else{
    leds[0] = CRGB(50,50,50);
    FastLED.show();
  }
}

void serialPrintColor(){
  Serial.print("Color RGB: ( ");
  Serial.print(colorArr[0]);
  Serial.print(", ");
  Serial.print(colorArr[1]);
  Serial.print(", ");
  Serial.print(colorArr[2]);
  Serial.println(" )");
}

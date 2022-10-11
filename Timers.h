unsigned long setClockMillis = 0;

bool secClock(){
  unsigned long currentMillis = millis();
  int interval = 2000;

  if (currentMillis - setClockMillis > interval){
    setClockMillis = currentMillis;
    return true;
  }else{
    return false;
  }
}

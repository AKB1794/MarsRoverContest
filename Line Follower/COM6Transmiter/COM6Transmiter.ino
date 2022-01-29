#include<SoftwareSerial.h>
char incomingbyte;
SoftwareSerial aBluetooth(10,11);
void setup() {
  Serial.begin(38400);
  aBluetooth.begin(38400);
}

void loop() {
  if(Serial.available()){
    incomingbyte=Serial.read();
    aBluetooth.write(incomingbyte);
    }
   
}

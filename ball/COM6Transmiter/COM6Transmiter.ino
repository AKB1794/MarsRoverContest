#include<SoftwareSerial.h>
char incomingbyte;
SoftwareSerial aBluetooth(10,11);
int x=1;
void setup() {
  Serial.begin(38400);
  aBluetooth.begin(38400);
  pinMode(12,OUTPUT);
}

void loop() {
  if(Serial.available()){
    incomingbyte=Serial.read();
    
    
    //Serial.println(incomingbyte);
    if(incomingbyte=='0' && x==0){
      aBluetooth.write(incomingbyte);
      x=1;
      }
    else if(incomingbyte=='1' && x==1){
      aBluetooth.write(incomingbyte);
      x=0;
      }
    }
   
}

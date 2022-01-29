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
  if(aBluetooth.available()){
    incomingbyte=aBluetooth.read();
    
    
    //Serial.println(incomingbyte);
    if(incomingbyte=='0' ){
      digitalWrite(12,LOW);
      }
    else if(incomingbyte=='1'){
      digitalWrite(12,HIGH);
      }
    }
   
}

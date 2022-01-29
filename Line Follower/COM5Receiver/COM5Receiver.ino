#include<SoftwareSerial.h>
char incomingbyte;
SoftwareSerial aBluetooth(10,11);
int x=0;
int a=255,b=255;
void setup() {
  
  Serial.begin(38400);
  pinMode(12,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  aBluetooth.begin(38400);
}
void loop() {
 if(aBluetooth.available()>0){ 
    incomingbyte = aBluetooth.read(); 
   Serial.println(incomingbyte);
   if(incomingbyte=='1'){
    digitalWrite(12,HIGH);
    }
    if(incomingbyte=='0'){
    digitalWrite(12,LOW);
    }
 }
}

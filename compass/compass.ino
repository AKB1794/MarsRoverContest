#include <Wire.h>
#include <math.h>
// Shift the device's documented slave address (0x3C) for write operation
// 1 bit right.This compensates for how the TWI library only wants the
// 7 most significant bits (with the high bit padded with 0)
#define HMC5883_WriteAddress 0x1E // i.e 0x3C >> 1
#define HMC5883_ModeRegisterAddress 0x02
#define HMC5883_ContinuousModeCommand 0x00
#define HMC5883_DataOutputXMSBAddress 0x03
int regb=0x01;
int regbdata=0x40;
int outputData[6];
int a=255;
int b=255;
void setup()
{
Serial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Wire.begin(); //Initiate the Wire library and join the I2C bus as a master
}
void loop() {
int i,x,y,z;
double angle;
Wire.beginTransmission(HMC5883_WriteAddress);
Wire.write(regb); Wire.write(regbdata);
Wire.endTransmission();
delay(1000);
Wire.beginTransmission(HMC5883_WriteAddress); //Initiate a transmission with HMC5883 (Write address).
Wire.write(HMC5883_ModeRegisterAddress); //Place the Mode Register Address in send-buffer.
Wire.write(HMC5883_ContinuousModeCommand); //Place the command for Continuous operation Mode in send-buffer.
Wire.endTransmission(); //Send the send-buffer to HMC5883 and end the I2C transmission.
delay(100);
Wire.beginTransmission(HMC5883_WriteAddress); //Initiate a transmission with HMC5883 (Write address).
Wire.requestFrom(HMC5883_WriteAddress,6); //Request 6 bytes of data from the address specified.
delay(500);
//Read the value of magnetic components X,Y and ZFuture Electronics Egypt Ltd. (Arduino Egypt).if(6 <= Wire.available()) // If the number of bytes available for reading be <=6.
{
for(i=0;i<6;i++)
{
 outputData[i]=Wire.read(); //Store the data in outputData buffer
}
}
 x=outputData[0] << 8 | outputData[1]; //Combine MSB and LSB of X Data output register
 z=outputData[2] << 8 | outputData[3]; //Combine MSB and LSB of Z Data output register
 y=outputData[4] << 8 | outputData[5]; //Combine MSB and LSB of Y Data output register
 angle= atan2((double)y,(double)x) * (180 / 3.14159265)
+ 180; // angle in degrees


Serial.println(angle);
if(angle>355 && angle <5 ){
    forword();
  }
else{
  leftturn();
  }
delay(100);
}

void stop(){     ///0
  digitalWrite(4,LOW);
  analogWrite(5,0);
  analogWrite(6,0);
  digitalWrite(7,HIGH);
  }
void forword(){   ///     8
  digitalWrite(4,LOW);
  analogWrite(5,a);
  analogWrite(6,b);
  digitalWrite(7,HIGH);
  }
void backword(){     ///  2 
  digitalWrite(4,HIGH);
  analogWrite(5,a);
  analogWrite(6,b);
  digitalWrite(7,LOW);
  }
void leftforword(){  ///  7
  digitalWrite(4,HIGH);
  analogWrite(5,0);
  analogWrite(6,b);
  digitalWrite(7,HIGH);
  }
void rightforword(){  /// 9
  digitalWrite(4,LOW);
  analogWrite(5,a);
  analogWrite(6,0);
  digitalWrite(7,LOW);
  }
void leftturn(){   /// 4
  digitalWrite(4,HIGH);
  analogWrite(5,a);
  analogWrite(6,b);
  digitalWrite(7,HIGH);
  }
void rightturn(){  /// 6
  digitalWrite(4,LOW);
  analogWrite(5,a);
  analogWrite(6,b);
  digitalWrite(7,LOW);
  }
void leftbackword(){   /// 1
  digitalWrite(4,HIGH);
  analogWrite(5,0);
  analogWrite(6,b);
  digitalWrite(7,LOW);
  }
void rightbackword(){   /// 3
  digitalWrite(4,HIGH);
  analogWrite(5,a);
  analogWrite(6,0);
  digitalWrite(7,LOW);
  }
  
  void rightbackword(){   /// 3
  digitalWrite(4,HIGH);
  analogWrite(5,0);
  analogWrite(6,a);
  digitalWrite(7,LOW);
  }

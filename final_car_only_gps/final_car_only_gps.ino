#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include "math.h"
#define pi acos(-1)
SoftwareSerial serial_connection(10, 11); //RX=pin 10, TX=pin 11
TinyGPSPlus gps;
int a=200;
int b=200;
float tarlat=22.462847;
float tarlon=91.969210;
float curlat;
float curlon;
float current_distance=0.0;
float temp_dis_bf=0.0;
float temp_dis_af=0.0;
float gps_distance=0.0;
void setup()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Start");
}
void loop()
{
  while(serial_connection.available()){
    gps.encode(serial_connection.read());}
  
  if(gps.location.isUpdated())
  {
     
     curlat=gps.location.lat();
     curlon=gps.location.lng();
     current_distance= distance(curlat,curlon,tarlat,tarlon);
    Serial.print("Latitude: ");Serial.println(curlat,8);Serial.print("Longitude: "); Serial.println(curlon,8);
     Serial.print("Distance: ");Serial.println(current_distance);Serial.println();
    }
//    current_distance=my_gps();
//    if (current_distance>=5)
//    {
//      temp_dis_bf = my_gps();
//      leftforword();
//      delay(200);
//      temp_dis_af = my_gps();
//      
//      if(temp_dis_af > temp_dis_bf)
//      { rightforword(); delay(200);stop(); delay(200);temp_dis_bf = my_gps();
//        rightforword(); delay(200);stop(); delay(200);temp_dis_af = my_gps();
//        if(temp_dis_af > temp_dis_bf) {leftforword(); delay(200);forword();}
//        else{ rightforword(); delay(200);stop(); delay(200);temp_dis_bf = temp_dis_af;temp_dis_af=my_gps();
//          
//          if(temp_dis_af > temp_dis_bf)
//          else
//        }
//      }
//      else{}
//    }
//    else{stop();}
}

float my_gps(){
  while(serial_connection.available()){
    gps.encode(serial_connection.read());}
    if(gps.location.isUpdated()){
      curlat=gps.location.lat();
      curlon=gps.location.lng();
      current_distance= distance(curlat,curlon,tarlat,tarlon);
      return gps_distance;
      }
    
  }
  
float distance(float tarlat, float tarlon,float curlat,float curlon)
  {
  float radius =6373*1000.0;
  float dlat =(tarlat-curlat)*pi/180;
  float dlon =(tarlon-curlon)*pi/180;
  float lat1 =curlat*pi/180;
  float lat2 =curlat*pi/180;
  float val =sin(dlat/2)*sin(dlat/2)+sin(dlon/2)*sin(dlon/2)*cos(lat1)*cos(lat2);
  float ang =2*atan2(sqrt(val),sqrt(1-val));
  float dist = radius*ang*100;
  return dist;
  }


void stop(){     ///0
  digitalWrite(4,LOW);
  analogWrite(5,0);
  analogWrite(6,0);
  digitalWrite(7,HIGH);
  }
void forword(){   ///     8
  digitalWrite(4,LOW);
  analogWrite(5,200);
  analogWrite(6,200);
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

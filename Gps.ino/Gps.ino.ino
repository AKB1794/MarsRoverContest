#include <TinyGPS.h>
#include <SoftwareSerial.h>

TinyGPS gps;
SoftwareSerial gpsSerial(10,11);

long lat ,lon;

void setup()
{
  Serial.begin(115200);
  gpsSerial.begin(9600);
  
  delay (100);
}


void loop()
{
  while (gpsSerial.available())
  {
    int c = gpsSerial.read();
    if (gps.encode(c))
    {
      gps.get_position(&lat, &lon);
      Serial.print(lat/1000000);
      Serial.print(".");
      Serial.print(lat%1000000);
      Serial.print("  ");
      Serial.print(lon/1000000);
      Serial.print(".");
      Serial.print(lon%1000000);
      Serial.print("  ");
     
    }
    delay(1000);
  }
  
}


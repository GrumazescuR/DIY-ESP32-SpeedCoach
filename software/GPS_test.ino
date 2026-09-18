#include <TinyGPSPlus.h>

TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

void setup() {
  Serial.begin(115200);

  gpsSerial.begin(
    9600,
    SERIAL_8N1,
    16,   // ESP32 RX <- GPS TX
    17    // ESP32 TX -> GPS RX
  );

  Serial.println("SpeedCoach GPS test starting...");
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {

    double speedKmph = gps.speed.kmph();
    double speedMps = speedKmph / 3.6;

    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value());

    Serial.print("Speed: ");
    Serial.print(speedKmph, 2);
    Serial.println(" km/h");

    if (speedMps > 0.2) {
      double splitSeconds = 500.0 / speedMps;

      int minutes = (int)(splitSeconds / 60);
      int seconds = (int)splitSeconds % 60;

      Serial.print("Split: ");
      Serial.print(minutes);
      Serial.print(":");

      if (seconds < 10) {
        Serial.print("0");
      }

      Serial.print(seconds);
      Serial.println(" /500m");
    }
    else {
      Serial.println("Split: --:-- /500m");
    }

    Serial.println("--------------------");
  }
}

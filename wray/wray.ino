#include <SoftwareSerial.h>
#include "src/Roomba/Roomba.h"

#define MAX_COUNT 1

#define RoombaSerial Serial2
Roomba roomba(&RoombaSerial);

void setup()
{
    Serial.begin(115200);
    Serial.println("WRAY");
    Serial.println("start");
    roomba.start();
    roomba.fullMode();
}

int count = 0;
void loop()
{
    count++;
    if (count > MAX_COUNT) {
        roomba.drive(0, Roomba::DriveStraight);
        delay(10000);
        return;
    }
    const int speed = 500;
    roomba.drive(speed, Roomba::DriveStraight);
    delay(1000);
    roomba.drive(0, Roomba::DriveStraight);
    delay(1000);
    roomba.drive(-speed, Roomba::DriveStraight);
    delay(1000);
    roomba.drive(0, Roomba::DriveStraight);
    delay(1000);
}

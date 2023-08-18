// #include <SoftwareSerial.h>

void setup()
{
    Serial.begin(115200);
    Serial.println("WRAY");
}

void loop()
{
    Serial.println("hi");
    delay(250);
}

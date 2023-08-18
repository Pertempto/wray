#include <SoftwareSerial.h>
#include "src/Roomba/Roomba.h"

const uint8_t eyes[][4] = {
    ' ', '0', '0', ' ',
    ' ', '-', '-', ' ',
};

// C - 39
// top line bottom line - 21

#define OPEN 0
#define BLINK 1

#define RoombaSerial Serial2
Roomba roomba(&RoombaSerial);

int led = LED_BUILTIN;  // the PWM pin the LED is attached to
int wakeUp = 5;

// the setup routine runs once when you press reset:
void setup() {

  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println("WRAY");
  Serial.println("start");
  roomba.start();
  roomba.fullMode();
  roomba.digitLedsASCII(' ', 'H', 'I', ' ');
  delay(500);
  // Load song 0
  RoombaSerial.write(140);
  RoombaSerial.write(0);
  RoombaSerial.write(3);
  RoombaSerial.write(31);
  RoombaSerial.write(64);
  RoombaSerial.write(32);
  RoombaSerial.write(64);
  RoombaSerial.write(33);
  RoombaSerial.write(64);
  // Load song 1
  RoombaSerial.write(140);
  RoombaSerial.write(1);
  RoombaSerial.write(3);
  RoombaSerial.write(105);
  RoombaSerial.write(64);
  RoombaSerial.write(106);
  RoombaSerial.write(64);
  RoombaSerial.write(107);
  RoombaSerial.write(64);
  // Load song 2
  RoombaSerial.write(140);
  RoombaSerial.write(2);
  RoombaSerial.write(4);
  RoombaSerial.write(31);
  RoombaSerial.write(128);
  RoombaSerial.write(107);
  RoombaSerial.write(128);
  RoombaSerial.write(32);
  RoombaSerial.write(128);
  RoombaSerial.write(106);
  RoombaSerial.write(128);

}

uint8_t ledSelect = 250;
void loop() {
  Serial.println(ledSelect);
  int eyeState = OPEN;
  if (random(20) == 0) {
      eyeState = BLINK;
  }
  roomba.digitLedsASCII(eyes[eyeState][0], eyes[eyeState][1], eyes[eyeState][2], eyes[eyeState][3]);
  roomba.leds(ledSelect, 0, 0);
  ledSelect += 1;
  delay(250);
}
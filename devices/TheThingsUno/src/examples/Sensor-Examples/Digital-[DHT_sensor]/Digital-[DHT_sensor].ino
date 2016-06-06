#include "TheThingsUno.h"

// Set your AppEUI and AppKey
const byte appEui[8] = { <insert AppEui> }; //for example: {0x70, 0xB3, 0xD5, 0x7E, 0xE0, 0xE0, 0x01, 0x4A1};
const byte appKey[16] = { <insert AppKey> }; //for example: {0x73, 0x6D, 0x24, 0xD2, 0x69, 0xBE, 0xE3, 0xAE, 0x0E, 0xCE, 0xF0, 0xBB, 0x6C, 0xA4, 0xBA, 0xFE};

#define debugSerial Serial
#define loraSerial Serial1

#define debugPrintLn(...) { if (debugSerial) debugSerial.println(__VA_ARGS__); }
#define debugPrint(...) { if (debugSerial) debugSerial.print(__VA_ARGS__); }

TheThingsUno ttu;

void setup() {
  debugSerial.begin(115200);
  loraSerial.begin(57600);

  delay(1000);
  ttu.init(loraSerial, debugSerial);
  ttu.reset();
  ttu.join(appEui, appKey);

  delay(4000);
  ttu.showStatus();

  debugPrintLn("Setup for The Things Network complete");
}

void loop() {

  //enable the send method of choice

  ttu.sendString("Hello world!");
  //ttu.sendBytes(data,sizeof(data));

  delay(20000);
}

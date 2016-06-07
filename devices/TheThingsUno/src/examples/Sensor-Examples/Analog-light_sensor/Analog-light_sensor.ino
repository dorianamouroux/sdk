#include "TheThingsUno.h"

// Set your AppEUI and AppKey
const byte appEui[8] = { <insert AppEui> }; //for example: {0x70, 0xB3, 0xD5, 0x7E, 0xE0, 0xE0, 0x01, 0x4A1};
const byte appKey[16] = { <insert AppKey> }; //for example: {0x73, 0x6D, 0x24, 0xD2, 0x69, 0xBE, 0xE3, 0xAE, 0x0E, 0xCE, 0xF0, 0xBB, 0x6C, 0xA4, 0xBA, 0xFE};

//define AnalogPin for sensor
#define LightPin A0

//data array for transmitting data
byte data[2];

#define debugSerial Serial
#define loraSerial Serial1

#define debugPrintLn(...) { if (debugSerial) debugSerial.println(__VA_ARGS__); }
#define debugPrint(...) { if (debugSerial) debugSerial.print(__VA_ARGS__); }

TheThingsUno ttu;

void setup() {
  debugSerial.begin(115200);
  loraSerial.begin(57600);

  pinMode(LightPin, INPUT);

  delay(1000);
  ttu.init(loraSerial, debugSerial);
  ttu.reset();
  ttu.join(appEui, appKey);

  delay(4000);
  ttu.showStatus();

  debugPrintLn("Setup for The Things Network complete");
}

void loop() {

  //transform the light voltage (float) into (uint16_t) [size = 2 bytes]
  uint16_t light = analogRead(LightPin)*100;
  //put data into the data array
  data[0] = lowByte(light);
  data[1] = highByte(light);
  //send data
  ttu.sendBytes(data,sizeof(data));

  delay(20000);
}

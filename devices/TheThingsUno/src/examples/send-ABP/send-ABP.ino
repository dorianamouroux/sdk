#include "TheThingsUno.h"

// Set your DevAddr
const byte devAddr[4] = { <insert DevAddr> }; //for example: {0x02, 0xDE, 0xAE, 0x00};

// Set your NwkSKey and AppSKey
const byte nwkSKey[16] = { <insert NwkSKey> }; //for example: {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};
const byte appSKey[16] = { <insert AppSKey> }; //for example: {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

// Set your message to send
String message = {"Hello world"}; //sending a string of chars "Hello world"

// set your bytes to send
byte data[2] = { 0x02, 0x12 }; //sending integers 2 and 18 in Heximals

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
  ttu.personalize(devAddr, nwkSKey, appSKey);

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

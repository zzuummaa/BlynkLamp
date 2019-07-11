/*************************************************************
  This is a DEMO. You can use it only for development and testing.
  You should open Setting.h and modify General options.

  If you would like to add these features to your product,
  please contact Blynk for Businesses:

                   http://www.blynk.io/

 *************************************************************/
#include <Arduino.h>

#define BLYNK_PRINT Serial // Enables Serial Monitor

#include "BlynkProvisioning.h"

uint8_t gpio0_pin = 0;
uint8_t gpio2_pin = 2;

void setup() {
    pinMode(gpio0_pin, OUTPUT);
    digitalWrite(gpio0_pin, LOW);
    BLYNK_PRINT.begin(115200);
    BlynkProvisioning.begin();
}

/**
 * Performs when user write value to V0. Set reset state if writen value is 1.
 * (Blynk and WIFI configuration will be reset in BlynkProvisioning.run() )
 *
 */
BLYNK_WRITE(V0) {
    bool isVirtualPinReset = param.asInt() == 1;
    if (isVirtualPinReset) {
        BlynkState::set(MODE_RESET_CONFIG);
    }
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

void loop() {
    // This handles the network and cloud connection
    BlynkProvisioning.run();
}


/**
 * @brief Demonstrate control of a relay.
 *
 * This sketch demonstrates using SimpleRelay library to control a relay.
 * In setup() phase, relay will be turned on and after a second it will be turned off.
 * In loop() phase, relay state will be periodically changed between "on" and "off" with
 * two-second period.
 *
 * Copyright 2019-2024 JSC TechMinds
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <SimpleRelay.h>

constexpr static byte RELAY_1_PIN = 10;
constexpr static byte RELAY_2_PIN = 11;
SimpleRelay relay1 = SimpleRelay(RELAY_1_PIN);          /* relay with noninverted (active high) logic */
SimpleRelay relay2 = SimpleRelay(RELAY_2_PIN, true);    /* relay with inverted (active low) logic */ 

void setup() {
    relay1.on();
    relay2.on();
    delay(1000);
    relay1.off();
    relay2.off();
}

void loop() {
    relay1.toggle();
    relay2.toggle();
    delay(2000);
}

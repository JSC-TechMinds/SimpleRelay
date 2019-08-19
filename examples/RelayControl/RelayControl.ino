/**
 * @brief Demonstrate control of a relay.
 *
 * This sketch demonstrates using SimpleRelay library to control a relay.
 * In setup() phase, relay will be turned on and after a second it will be turned off.
 * In loop() phase, relay state will be periodically changed between "on" and "off" with
 * two-second period.
 *
 * Copyright 2019 JSC electronics
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

constexpr static byte RELAY_PIN = 10;
SimpleRelay relay = SimpleRelay(RELAY_PIN);

void setup() {
    relay.on();
    delay(1000);
    relay.off();
}

void loop() {
    relay.toggle();
    delay(2000);
}

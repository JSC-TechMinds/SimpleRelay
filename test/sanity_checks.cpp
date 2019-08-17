/**
 *  Copyright (c) 2019 JSC electronics
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

#include <ArduinoUnitTests.h>
#include "../src/SimpleRelay.h"

constexpr static byte OUTPUT_PIN = 10;
GodmodeState* state = GODMODE();

unittest_setup() {
    state->reset();
}

unittest(pin_voltage_is_set_to_low_for_non_inverted_relay) {
    // Make sure this state is reset
    state->digitalPin[OUTPUT_PIN] = HIGH;

    SimpleRelay relay = SimpleRelay(OUTPUT_PIN);

    assertEqual(LOW, digitalRead(OUTPUT_PIN));
    assertEqual(false, relay.isRelayOn());
}

unittest(pin_voltage_is_set_to_high_for_inverted_relay) {
    // Make sure this state is reset
    state->digitalPin[OUTPUT_PIN] = LOW;

    SimpleRelay relay = SimpleRelay(OUTPUT_PIN, /* isInverted */ true);

    assertEqual(HIGH, digitalRead(OUTPUT_PIN));
    assertEqual(false, relay.isRelayOn());
}

unittest_main()
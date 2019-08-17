/**
 *  @file       SimpleRelay.cpp
 *  Project     SimpleRelay
 *  @brief      Relay library for Arduino
 *  @author     JSC electronics
 *  License     Apache-2.0 - Copyright (c) 2019 JSC electronics
 *
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

#pragma once

#include "SimpleRelay.h"

/**
 * @brief  Set relay to <code>ON</code> state.
 */
void SimpleRelay::on(void) {
    _rs = RELAY_ON;
    if (_sl == NONINVERTED) {
        digitalWrite(_relayPin, HIGH);
    } else {
        digitalWrite(_relayPin, LOW);
    }
}

/**
 * @brief  Set relay to <code>OFF</code> state.
 */
void SimpleRelay::off(void) {
    _rs = RELAY_OFF;
    if (_sl == NONINVERTED) {
        digitalWrite(_relayPin, LOW);
    } else {
        digitalWrite(_relayPin, HIGH);
    }
}

/**
 * @brief  Toggle relay state.
 */
void SimpleRelay::toggle(void) {
    if (_rs == RELAY_ON)
        off();
    else
        on();
}

/**
 * @brief Get current state of a relay.
 * @return State of relay.
 */
RelayState_TypeDef SimpleRelay::getState(void) {
    return _rs;
}

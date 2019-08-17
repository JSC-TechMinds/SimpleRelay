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

#include "SimpleRelay.h"

/**
 * @brief Constructor for the class.
 * @param pin an output pin to use for the relay control.
 * @param isInverted sets characteristic of a relay. A relay is non-inverted, when it will turn on after setting
 * voltage on output pin to <code>HIGH</code>. In contrary, inverted relay will turn on when output voltage
 * is set to <code>LOW</code>. This parameter is optional and defaults to <code>false</code>.
 */
SimpleRelay::SimpleRelay(uint8_t pin, bool isInverted) {
    m_pin = pin;
    m_relayOnLogicLevel = isInverted ? LOW : HIGH;
    pinMode(m_pin, OUTPUT);
    off();
}

/**
 * @brief Destructor for the class.
 */
SimpleRelay::~SimpleRelay() {
    // set pin to high impedance
    pinMode(m_pin, INPUT);
}

/**
 * @brief  Set relay to <code>ON</code> state.
 */
void SimpleRelay::on(void) {
    m_state = State::RELAY_ON;
    digitalWrite(m_pin, m_relayOnLogicLevel);
}

/**
 * @brief  Set relay to <code>OFF</code> state.
 */
void SimpleRelay::off(void) {
    m_state = State::RELAY_OFF;
    digitalWrite(m_pin, m_relayOnLogicLevel == HIGH ? LOW : HIGH);
}

/**
 * @brief  Toggle relay state.
 */
void SimpleRelay::toggle(void) {
    if (m_state == State::RELAY_ON) {
        off();
    } else {
        on();
    }
}

/**
 * @brief Get information if a relay is currently <code>ON</code>.
 * @return <code>true</code> if relay is on, false otherwise.
 */
bool SimpleRelay::isRelayOn(void) {
    return m_state == State::RELAY_ON;
}

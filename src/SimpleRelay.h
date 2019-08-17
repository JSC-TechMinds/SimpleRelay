/**
 *  @file       SimpleRelay.h
 *  Project     SimpleRelay
 *  @brief      Relay library for Arduino
 *  @author     JSC electronics
 *  License     Apache-2.0 - Copyright (c) 2019 JSC electronics
 *
 *  @section License
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

#include <Arduino.h>

class SimpleRelay {
public:
    SimpleRelay(uint8_t pin, bool isInverted = false);

    ~SimpleRelay();

    void on(void);

    void off(void);

    void toggle(void);

    bool isRelayOn(void);

private:
    uint8_t m_pin; /**< Output pin bound with this relay instance */

    /**
     * Signal levels as read from <code>digitalRead()</code> function, can be either <code>HIGH</code> or
     * <code>LOW</code>. When you create a new SimpleRelay instance, you specify <code>activeLow</code> boolean parameter.
     * This variable represents a mapping from the boolean to actual voltage level set on output.
     *
     * @see SimpleRelay(uint8_t pin, bool activeLow = true)
     */
    byte m_relayOnLogicLevel;

    /**
     * @brief States allowed for a Relay to transition into.
     */
    enum class State {
        RELAY_OFF,
        RELAY_ON
    };

    /**
     * This variable holds information on a current state of a relay.
     *
     * @see enum class State
     */
    State m_state = State::RELAY_OFF;
};

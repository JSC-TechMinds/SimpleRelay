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

typedef enum {
    RELAY_OFF,
    RELAY_ON
} RelayState_TypeDef;

typedef enum {
    NONINVERTED,
    INVERTED
} SwitchingLogic_TypeDef;

class SimpleRelay {
private:
    Relay *_pRelay;
    int _relayPin;
    RelayState_TypeDef _rs;
    SwitchingLogic_TypeDef _sl;

public:
    /* Constructors */
    inline SimpleRelay(char relayPin) {
        this->_relayPin = relayPin;
        this->_rs = RELAY_OFF;
        this->_sl = NONINVERTED;

        pinMode(_relayPin, OUTPUT);
        off();
    }

    inline SimpleRelay(char relayPin, SwitchingLogic_TypeDef logicLevel) {
        this->_relayPin = relayPin;
        this->_rs = RELAY_OFF;
        this->_sl = logicLevel;

        pinMode(_relayPin, OUTPUT);
        off();
    }

    inline SimpleRelay(char relayPin, SwitchingLogic_TypeDef logicLevel, RelayState_TypeDef relayState) {
        this->_relayPin = relayPin;
        this->_rs = relayState;
        this->_sl = logicLevel;

        pinMode(_relayPin, OUTPUT);

        if (_rs == RELAY_ON)
            on();
        else
            off();
    }

    /* Destructor */
    inline ~SimpleRelay() {
        // set pin to high impedance
        pinMode(_relayPin, INPUT);
    }

    // public functions declarations
    void on();

    void off();

    void toggle();

    RelayState_TypeDef getState(void);
};

/**
******************************************************************************
* @author	Arduino development
* @version	V1.0
* @date		8.5.2019
* @brief	Relay control
*		
*/

#ifndef _RELAY_H
#define _RELAY_H

#include <Arduino.h>

typedef enum
{
    RELAY_OFF,
    RELAY_ON
} RelayState_TypeDef;

typedef enum
{
    NONINVERTED,
    INVERTED
} SwitchingLogic_TypeDef;

class Relay
{
private:
    Relay *_pRelay;
    int _relayPin;
    RelayState_TypeDef _rs;
    SwitchingLogic_TypeDef _sl;

public:
    /* Constructors */
    inline Relay(char relayPin)
    {
        this->_relayPin = relayPin;
        this->_rs = RELAY_OFF;
        this->_sl = NONINVERTED;

        pinMode(_relayPin, OUTPUT);
        off();
    }
    inline Relay(char relayPin, SwitchingLogic_TypeDef logicLevel)
    {
        this->_relayPin = relayPin;
        this->_rs = RELAY_OFF;
        this->_sl = logicLevel;

        pinMode(_relayPin, OUTPUT);
        off();
    }
    inline Relay(char relayPin, SwitchingLogic_TypeDef logicLevel, RelayState_TypeDef relayState)
    {
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
    inline ~Relay()
    {
        // set pin to high impedance
        pinMode(_relayPin, INPUT);
    }

    // public functions declarations
    void on();
    void off();
    void toggle();
    RelayState_TypeDef getState(void);
};

#endif
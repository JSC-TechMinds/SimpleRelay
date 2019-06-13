/**
******************************************************************************
* @author	Arduino development
* @version	V1.1
* @date		13.6.2019
* @brief	Relay control
*		
*/

#include "relay.h"

/**
	@brief  Relay::on()
            sets relay to ON state
	@param  none
	@retval none
*/
void Relay::on(void)
{
    _rs = RELAY_ON;
    if (_sl == NONINVERTED)
    {
        digitalWrite(_relayPin, HIGH);
    }
    else
    {
        digitalWrite(_relayPin, LOW);
    }
}

/**
	@brief  Relay::off()
            sets relay to OFF state
	@param  none
	@retval none
*/
void Relay::off(void)
{
    _rs = RELAY_OFF;
    if (_sl == NONINVERTED)
    {
        digitalWrite(_relayPin, HIGH);
    }
    else
    {
        digitalWrite(_relayPin, LOW);
    }
}

/**
	@brief  Relay::toggle()
            toggles relay state
	@param  none
	@retval none
*/
void Relay::toggle(void)
{
    if (_rs == RELAY_ON)
        off();
    else
        on();
}

/**
	@brief  Relay::getState()
            relayState getter
	@param  none
	@retval RelayState_TypeDef
*/
RelayState_TypeDef Relay::getState(void)
{
    return _rs;
}

#ifndef LimitSwitch_h
#define LimitSwitch_h

#include "Arduino.h"

class LimitSwitch{
    public:
        LimitSwitch(int _pin = -1, bool _normalClosed = false);
        bool limitReached();
        void setPin(int _pin);
        void setNormalState(bool _normalClosed);
    
    private:
        int pin;
        bool normalClosed;
        void (*limitCallback)(void);
        int debouncedReading();
};

 #endif

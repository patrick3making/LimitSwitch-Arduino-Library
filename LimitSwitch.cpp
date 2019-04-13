#include "LimitSwitch.h"

LimitSwitch::LimitSwitch(int _pin = -1, bool _normalClosed = false){
    pin = _pin;
    normalClosed = _normalClosed;
    if (pin >= 0){
        pinMode(pin, INPUT_PULLUP);
    }
}

bool LimitSwitch::limitReached(){
    if (pin >= 0){              // if the pin is defined
        int state = debouncedReading();
        if(!normalClosed && state == LOW){
            return true;
        }
        else if (normalClosed && state == HIGH){
            return true;
        }
        else{
            return false;
        }
    }
}

int LimitSwitch::debouncedReading(){
    bool different = true;
    int initialReading = digitalRead(pin);
    int finalReading;
    while(different){
        delay(10);
        finalReading = digitalRead(pin);
        if (initialReading == finalReading){
            different = false;
        }
        else{
            initialReading = finalReading;
        }
    }
    return finalReading;
}

void LimitSwitch::setPin(int _pin){
    pin = _pin;
    pinMode(pin, INPUT_PULLUP);
}

void LimitSwitch::setNormalState(bool _normalClosed){
    normalClosed = _normalClosed;
}

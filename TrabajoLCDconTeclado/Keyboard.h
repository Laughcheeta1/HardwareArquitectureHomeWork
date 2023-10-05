#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "mbed.h"
#include "Keypad.h"
#include "TextLCD.h"
#include "iostream"
#include "string"
#include <cmath>
#include <cstdio>
#include <vector>

class keyboard
{
    private:
        char keyMap[4][4] = {
            {'1', '2', '3', 'A'},
            {'4', '5', '6', 'B'},
            {'7', '8', '9', 'C'},
            {'*', '0', '#', 'D'}
        };

        DigitalOut rowPins[4] = {DigitalOut(D8), DigitalOut(D9), DigitalOut(D10), DigitalOut(D11)};
        DigitalIn colPins[4] = {DigitalIn(D12), DigitalIn(D14), DigitalIn(D15), DigitalIn(PTB8)};

    public:
        int getPressedNumber();
        vector<int> getPressedNumber2();
};

#endif
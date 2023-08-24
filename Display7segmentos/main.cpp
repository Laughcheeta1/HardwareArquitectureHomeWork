/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>

BusOut leds(D2, D3, D4, D5, D6, D7, D8);

int getNumber();

int main()
{
    int number;
    while (true)
    {
        if ((number = getNumber()) != -1)
        {
            leds.write(number);
        }
    }
}

int getNumber()
{
    cout << "enter the number you desire";
    char number;
    cin >> number;

    if (isdigit(number))
    {
        if (number == '0')
            return 126;
        else if (number == '1')
            return 48;
        else if (number == '2')
            return 109;
        else if (number == '3')
            return 121;
        else if (number == '4')
            return 51;
        else if (number == '5')
            return 91;
        else if (number == '6')
            return 95;
        else if (number == '7')
            return 112;
        else if (number == '8')
            return 127;
        else if (number == '9')
            return 115;
    }
        
    cout << "enter a valid number";
    return -1;
    
}

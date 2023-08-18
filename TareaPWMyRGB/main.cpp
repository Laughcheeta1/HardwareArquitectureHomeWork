/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
#include <string>


using namespace std;

#define BLINKING_RATE 50ms

void turnOnOffLed();
void makeColors();
float getNumber(char firstNumber, char secondNumber); 

int main()
{
    // Initialise the digital pin LED1 as an output
    //turnOnOffLed();
    cout << "Commence the thing\n";
    makeColors();
}

void turnOnOffLed()
{
    PwmOut ledR(LED1);
    ledR.period(0.01);

    float pwm = 0.00;
    int multiplier = 1;

    while (true)
    {
        ledR.write(pwm);
        ThisThread::sleep_for(BLINKING_RATE);

        pwm += multiplier*0.05;

        if (pwm >= 1.00 || pwm <= 0.00)
        {
            multiplier = -1 * multiplier;
            cout << "entro: " << multiplier << "\n";
        }
    }
}

void makeColors()
{
    cout << "Format: #FFFFFF\n";

    PwmOut red(LED1);
    PwmOut green(LED2);
    PwmOut blue(LED3);

    red.period(0.01);
    green.period(0.01);
    blue.period(0.01);

    string input;

    while (true)
    {
        if (getline(cin, input))    
        {
            red.write(getNumber(input[1], input[2]));
            green.write(getNumber(input[3], input[4]));
            blue.write(getNumber(input[5], input[6]));
        }
    }
}

float getNumber(char firstNumber, char secondNumber)
{
    float result = 0;


    if (isdigit(firstNumber))
    {
        result += 16 * (firstNumber - '0');
    }
    else
    {
        result += 16 * (tolower(firstNumber) - 'a' + 10);
    }

    if (isdigit(secondNumber))
    {
        result += secondNumber - '0';
    }
    else
    {
        result += tolower(secondNumber) - 'a' + 10;
    }

    return result / 1000;
}
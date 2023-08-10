/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>

#define Red_Time 100;
#define Green_Time 160;
#define Blue_Time 240;

// Sebastian Ruiz Londoño y Santiago Yepes Mesa

UnbufferedSerial serial(USBTX, USBRX, 9600);

// Blinking rate in milliseconds
int main()
{
    int timeRed, timeGreen, timeBlue;

    cout << "timeRed: ";
    cin >> timeRed;

    cout << "timeGreen: ";
    cin >> timeGreen;

    cout << "timeBlue: ";
    cin >> timeBlue;

    // Initialise the digital pin LED1 as an output
    DigitalOut led1(LED1);
    DigitalOut led2(LED2);
    DigitalOut led3(LED3);
    long long time = 0;
    
    led1 = !led1;
    led2 = !led2;
    led3 = !led3;

    while (true) {
        if (time % timeRed == 0)
        {
            led1 = !led1;
            printf("led1 changed in time %lld\n", time);
            //cout << "led1 changed in time: " << time << "\n";
        }
        if (time % timeGreen == 0)
        {
            led2 = !led2;
            printf("led2 changed in time %lld\n", time);
            //cout << "led2 changed in time: " << time << "\n";
        }
        if (time % timeBlue == 0)
        {
            led3 = !led3;
            printf("led3 changed in time %lld\n", time);
            //cout << "led3 changed in time: " << time << "\n";
        }

        ThisThread::sleep_for(1);
      
        time++;
    }
}

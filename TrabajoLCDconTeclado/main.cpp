/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
#include "Keyboard.h"
#include "mbed.h"
#include "Keypad.h"
#include "TextLCD.h"
#include "iostream"
#include "string"
#include <cmath>
#include <cstdio>
#include <vector>


using namespace std;

// Methods we are going to use
void app1();
void app2();
void app3();

// Create the display and keyboard object
TextLCD display(D2, D3, D4, D5, D6, D7, TextLCD::LCD16x2);
keyboard k;

void greet()
{
    display.cls();
    ThisThread::sleep_for(10ms);
    display.printf("Bienvenido");
    ThisThread::sleep_for(2s);
    display.cls();
}

void main2()
{
        display.cls();
        ThisThread::sleep_for(10ms);
        display.printf("Select app: (1, 2, 3)");
        ThisThread::sleep_for(2s);
        display.cls();
        int c = k.getPressedNumber();

        while (c < 1 || c > 3)
        {
            display.cls();
            display.printf("Enter a valid app");
            ThisThread::sleep_for(2s);
            display.cls();
            c = k.getPressedNumber();
            
        }

        display.cls();
        display.printf("Selected app is %d", c);
        ThisThread::sleep_for(2s);
        display.cls();

        if (c == 1)
            app1();
        if (c == 2)
            app2();
        if (c == 3)
            app3();
}


int main() 
{
    ThisThread::sleep_for(10ms);
    display.printf("Hola mundo");
    ThisThread::sleep_for(2s);

    // greet();
    // while (true)
    // {
    //     main2();
    // }
    while (true);
}


void app3()
{
    display.cls();
    display.printf("app 3 selected");
    ThisThread::sleep_for(2s);
    display.cls();

    PwmOut red(LED1);
    PwmOut green(LED2);
    PwmOut blue(LED3);

    red.period(0.01);
    green.period(0.01);
    blue.period(0.01);

    display.cls();
    display.printf("ingrese numero rojo ");
    ThisThread::sleep_for(2s);
    display.cls();

    float number1 = (float)k.getPressedNumber();
    while (number1 > 255 || number1 < 0)
    {   
        display.cls();
        display.printf("numero no valido, de nuevo");
        ThisThread::sleep_for(2s);
        display.cls();
        number1 = k.getPressedNumber();
    }

    display.cls();
    display.printf("ingrese numero verde ");
    ThisThread::sleep_for(2s);
    display.cls();
    float number2 = (float)k.getPressedNumber();
    while (number2 > 255 || number2 < 0)
    {
        display.cls();
        display.printf("numero no valido, de nuevo");
        ThisThread::sleep_for(2s);
        display.cls();
        number2 = k.getPressedNumber();
    }

    display.cls();
    display.printf("ingrese numero azul");
    ThisThread::sleep_for(2s);
    display.cls();
    float number3 = (float)k.getPressedNumber();
    while (number3 > 255 || number3 < 0)
    {
        display.cls();
        display.printf("numero no valido, de nuevo");
        ThisThread::sleep_for(2s);
        display.cls();
        number3 = k.getPressedNumber();
    }

    red.write(1 - (number1 / 255));
    green.write(1 - (number2 / 255));
    blue.write(1 - (number3 / 255));

    display.cls();
    display.printf("Listo! App 3 terminada");
    ThisThread::sleep_for(2s);
    display.cls();
}


void app2()
{
    display.cls();
    display.printf("app 2 selected");
    ThisThread::sleep_for(2s);
    display.cls();

    display.cls();
    display.printf("Ingrese una nota del 0 al 10");
    ThisThread::sleep_for(2s);
    display.cls();

    int i = k.getPressedNumber();
    while (i > 10 || i < 0)
    {
        display.cls();
        display.printf("numero no valido, de nuevo");
        ThisThread::sleep_for(2s);
        display.cls();

        i = k.getPressedNumber();
    }

    display.cls();
    if (i <= 3 && i >= 0)
        display.printf("A");
    else if (i <= 4 && i > 3)
        display.printf("B");
    else if (i <= 5 && i > 4)
        display.printf("C");
    else if (i <= 7 && i > 5)
        display.printf("D");
    else if (i < 9 && i > 7)
        display.printf("E");
    else if (i <= 10 && i >= 9)
        display.printf("F");
    ThisThread::sleep_for(2s);
    display.cls();

    display.cls();
    display.printf("Listo! App 2 terminada");
    ThisThread::sleep_for(2s);
    display.cls();
}

void app1()
{
    display.cls();
    display.printf("app 1 selected");
    ThisThread::sleep_for(2s);
    display.cls();

    display.cls();
    display.printf("La forma del polinomio es: a*(x^2) + b*x + c");
    ThisThread::sleep_for(2s);
    display.cls();
    display.printf("ingrese por favor el valor de la a");
    ThisThread::sleep_for(2s);
    display.cls();
    int a = k.getPressedNumber();

    display.cls();
    display.printf("ingrese el valor de la b");
    ThisThread::sleep_for(2s);
    display.cls();
    int b = k.getPressedNumber();

    display.cls();
    display.printf("ingrese el valor de la c");
    ThisThread::sleep_for(2s);
    display.cls();
    int c = k.getPressedNumber();

    bool imaginary = false;

    int interRaiz = b*b - 4*a*c;

    if (interRaiz < 0)
        imaginary = true;

    interRaiz = abs(interRaiz);
    
    if (imaginary)
    {   display.cls();
        display.printf("resultado: (%d + %fi) / %d", -b, sqrt(interRaiz), 2*a);
        ThisThread::sleep_for(2s);
        display.cls();

        display.cls();
        display.printf("resultado: (%d - %fi) / %d", -b, sqrt(interRaiz), 2*a);
        ThisThread::sleep_for(2s);
        display.cls();
    }
    else 
    {
        display.cls();
        display.printf("resultados: %f o %f", (-b + sqrt(interRaiz)) / (2*a), (-b - sqrt(interRaiz)) / (2*a));
        ThisThread::sleep_for(2s);
        display.cls();
    }

    display.cls();
    display.printf("Listo! App 1 terminada");
    ThisThread::sleep_for(2s);
    display.cls();
}

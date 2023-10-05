#include "Keyboard.h"
#include <iostream>


int keyboard::getPressedNumber()
{
    TextLCD display(D2, D3, D4, D5, D6, D7, TextLCD::LCD16x2);
    vector<int> res = getPressedNumber2();
    int x = res.size();
    bool flag = false;

    if (res[0] == -1)
    {
        flag = true;
        res.erase(res.begin());
        x--;
    }

    int result = 0;
    for (int i = 0; i < x; i++)
    {
        result += res[i] * pow(10, x - i - 1);
    }

    if (flag)
        result *= -1;

    display.printf("Ingreso: %d", result);
    ThisThread::sleep_for(2s);
    display.cls();
    return result;
}

vector<int> keyboard::getPressedNumber2()
{
    TextLCD display(D2, D3, D4, D5, D6, D7, TextLCD::LCD16x2);
    display.cls();
    display.printf("* = menos, # = confirmar");
    ThisThread::sleep_for(2s);
    display.cls();
    vector <int> res;
    bool flag = true;
    while (true){
        for (int i = 0; i < 4; i++) {
            rowPins[i] = 0;
            
            for (int j = 0; j < 4; j++) {
                if (!colPins[j]) {
                    if (keyMap[i][j] == '*')
                    {
                        rowPins[i] = 1;
                        ThisThread::sleep_for(500ms);
                        return res;
                    }
                    else if (keyMap[i][j] == '#')
                    {
                        if (flag && res.size() == 0)
                        {
                            res.push_back(-1);
                            display.cls();
                            display.printf("Presiono -");
                            flag = false;
                        }
                        else
                        {
                            display.cls();
                            display.printf("- ignorado");
                        }
                    }
                    else
                    {
                        res.push_back(keyMap[i][j] - '0');
                        display.cls();
                        display.printf("pressed %c", keyMap[i][j]);
                    }

                    ThisThread::sleep_for(500ms);  // Evita lecturas múltiples mientras la tecla está presionada
                }
            }

            rowPins[i] = 1;
        }
    }
}
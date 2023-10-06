# Integrantes
1. Sebastian Ruiz Londoño
1. Santiago Yepes Mesa

# Descripcion Codigo
### Previo al Main
```
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

```
En el código previo al main se importan diferentes librerías para el correcto funcionamiento del programa: "Keypad.h" se importa para el teclado que se va a utilizar, "TextLCD.h" para la pantalla LCD y las otras librerías son propias de C++ y C.
Posteriormente se declaran las tres funciones principales del programa (Las tres aplicaciones que el usuario va a poder utilizar).
Por último se crean el objeto "display" para controlar la pantalla LCD y y el objeto "k" para el teclado. El constructor de TextLCD recibe pines como argumentos para configurar la pantalla LCD.


### greet()
```
void greet()
{
    display.cls();
    ThisThread::sleep_for(10ms);
    display.printf("Bienvenido");
    ThisThread::sleep_for(2s);
    display.cls();
}
```
La función greet() tiene como finalidad mostrar un mensaje de saludo en la pantalla y posteriormente borra lo que esta en pantalla.

### main2()
    
```
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
```
   
La función main2() inicialmente borra la pantalla y después le pide al usuario que ingrese un número para seleccionar la aplicación que desea utilizar(un número entre el 1 y el 3). El programa verifica con el while que el usuario ingrese un número válido, de lo contrario el programa le continúa pidiendo un número válido hasta que se ingrese uno. Una vez que se ingrese un número válido se muestra en pantalla la aplicación seleccionada y por último el programa llama a la función correspondiente a la aplicación seleccionada.



### app3()

```
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
```

Inicialmente la función app3() borra la pantalla y muestra "app 3 selected" para indicar que la aplicación 3 está seleccionada. Posteriormente configura tres LED (rojo, verde y azul) como salidas PWM para controlar su intensidad luminosa. Después le pide al usuario que ingrese un número del 0 al 255 para representar la intensidad del color rojo y verifica si el número ingresado es válido, de lo contrario le vuelve a pedir al usuario que ingrese un número válido hasta que se ingrese uno. La función repite este proceso para determinar la intensidad del color verde y el azul. Por último el método convierte estos valores ingresados al porcentaje con respecto a 255 y muestra el color que se da como resultado de la combianción de estos tres colores anteriormente mencionados y muestra en pantalla: "Listo! App 3 terminada".


### app2()

```
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

```
La función app2() inicialmente borra la pantalla y muestra en pantalla "app 2 selected" para indicar la aplicación seleccionada. Posteriormente le pide un número al usuario entre el 1 y el 10 (el método siempre revisa si el numero ingresado está entre 1 y 10, de lo contrario el metodo pide nuevamente el número hasta que se ingrese un número válido). Una vez ingresado el número el método le muestra al usuario una letra mayúscula (desde la A hasta la F) según el numero que se haya ingresado. Por último muestra: "Listo! App 2 terminada" para indicar que se terminó la operación de la función y borra la pantalla.

### app1()

```
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

```

La función app1() inicialmente borra la pantalla y muestra "app 1 selected" para indicar la aplicación seleccionada. Esta funcion permite al usuario ingresar coeficientes de un polinomio cuadrático y calcula sus raíces. Las respuestas que tengan números imaginarios se dejan indicadas.

El pide al usuario el valor de `a`, `b` y `c`, los cuales son las partes que componen un polinomio cuadrático (a*(x^2) + b*x + c).
Después declara una variable booleana `imaginary`, la cual guarda si la respuesta va a ser compleja (contener un imaginario) o no, e inicialmente se establece como falsa.

Se calcula el determinante (la parte interior de la raíz, `interRaiz`) de la formula de la solucion de una ecuación cuadrática y se verifica si este (`interRaiz`) es negativo. Si lo es, se establece `imaginary` en true, lo que indica que las raíces serán números complejos. Si `imaginary` es true, se imprime la solución en formato de número complejo. Si `imaginary` es false, se imprime la solución calculada. Para las soluciones se muestran ambas, cuando la formula es b + raiz y cuando es b - raiz.

Por último la función muestra: "Listo! App 1 terminada" para indicar que se terminó la operación y se borra la pantalla.



# Integrantes
1. Sebastian Ruiz Londoño
1. Santiago Yepes Mesa

# Descripcion Codigo
### Previo al Main
```
#include "mbed.h"
#include <iostream>
#include <string>

using namespace std;

#define BLINKING_RATE 50ms

void turnOnOffLed();
void makeColors();
float getNumber(char firstNumber, char secondNumber); 
```
En las linea previa al main vamo a importar la librerias que vamos a usar, el nombre del espacio, definimos una macro `BLINKING_RATE` la cual se encarga de reemplazar `50ms`, despues de esto declaramos los prototipos de las funciones que vamos a usar durante el codigo.


### main()
La funcion `main()` se encarga de ejecutar uno de los dos metodos `turnOnOffLed()` o `makeColors()`;

### turnOffLed()
Las lineas de codigo 29 a la 33:
    ```
    PwmOut ledR(LED1);
    ledR.period(0.01);

    float pwm = 0.00;
    int multiplier = 1;
    ```
    Estas se encargan de inicializar las cosas que vamos a utilizar para prender y apagar el led de forma progresiva; estos son, el objeto "ledR" el cual es el cual es el led rojo de la board, inmediatamente despues vamos a definir cual va a ser el periodo de este led, aparte de esto tememos dos variables:
        * pwm: es la que guarda la "potencia" de el led, va a ser usado para sobre escribir la potencia del led.
        * multiplier: esta variable se encarga de ser la que dicta si el pwm va a aumentar o bajar, esto debido a que esta va a ser sencillamente un "1" o un "-1", lo cual mas adelante veremos como afecta el pwm.
    
Las lineas 35 a la 47:
    ```
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
    ```
    Ocurre un ciclo infinito en el cual se va constantemente aumentando y decreciendo la "potencia" del led, esto se hace por medio de las siguientes lineas:
        ```
        ledR.write(pwm);
        ThisThread::sleep_for(BLINKING_RATE);

        pwm += multiplier*0.05;
        ```
        Estas lineas, las cuales estan al inicio del ciclo, se encargan de sobre escribir cual es la potencia actual del led, y parar el codigo por `BLINKING_RATE`` tiempo, esto con la finalidad de que se pueda apreciar de mejor manera el gradual aumento/decrecimiento de la intensidad, debajo de estas dos lineas se encuentra la linea de codigo la cual se encarga de sumarle al poder del led una cantidad `multiplier*0.05`, la cual dependiendo de si `multiplier` es un "1" o un "-1", va a sumar o a restarle en 0.05 a la intensidad del led.


        ```
        if (pwm >= 1.00 || pwm <= 0.00)
        {
            multiplier = -1 * multiplier;
            cout << "entro: " << multiplier << "\n";
        }        
        ```
        La finalidad de este if es que cuando la potencia (`pwm`) del Led llegue a 1 o a 0, el multiplicador cambie de signo, de esta manera si el poder llega a 1, el multiplicador pasara a ser "-1", por ende el poder empezara a bajar, debido a la multiplicacion mostrada anteriormente, a su vez, si la `pwm` llega a 0, el multiplicador pasara a ser "1", de esa manera en el ciclo sumando al `pwm`. La linea de abajo solo se encarga de mostrar en la terminal una confirmacion de que el `pwm` ha llegado a 0 o a 1.



### makeColors()
```
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
```

La linea 52 se encarga de informar por consola al usario el formato esperado de color, este formato corresponde a la forma hexadecimal de un color (ej: #F3A008):
    ```cout << "Format: #FFFFFF\n";```

Las lineas de la 54 a la 62:
    ```
    PwmOut red(LED1);
    PwmOut green(LED2);
    PwmOut blue(LED3);

    red.period(0.01);
    green.period(0.01);
    blue.period(0.01);

    string input;
    ```
    Se encarga de declarar una variable `input` la cual va a almacenar los colores que indica el usuario, declaramos los objetos de los tres leds, el rojo, verde y azul, y a su ves definimos cual va a ser el periodo de cada uno de estos.

las lineas 64 a la 72:
    ```
    while (true)
    {
        if (getline(cin, input))    
        {
            red.write(getNumber(input[1], input[2]));
            green.write(getNumber(input[3], input[4]));
            blue.write(getNumber(input[5], input[6]));
        }
    }
    ```
    Es donde se declara el ciclo infinito en el cual en todo momento se va a estar buscando por un input del usuario, y en caso de encontrarlo sobre escribe la potencia de cada led, para poder proyectar el color esperado por el usuario, la interpretacion de esots numeros hexadecimales a numeros de punto flotante, se hace por medio de la duncion `getNumber()`, la cual va a ser explicada mas abajo. Debido al formato hexadecimal del numero sabemos que siempre los dos primeros caracteres de este numero exadecimal van a corresponder a la intensidad del rojo, los dos siguientes a la intensidad del verde, y por ende los ultimos dos corresponden a la intensidad del azul, sin embargo al esperar que el usuario ingrese siempre un `#`, es por eso que empezamos a contar como primer numero hexadecimal a partir del caracter en la posicion 1 de `input`.



### getNumber()
```
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
```
Esta funcion se encarga de dado dos caracteres hexadecimales, siendo uno de ellos el correspondiente a los decenas (`firstNumber`) y el otro a las unidades (`secondNumber`), devuelva una variable en forma de punto flotante entre 0 y 1. 

Esto lo hace por medio de para cada una de las variables evaluar si es un numero, en cuyo caso sencillamente decimos que dicho caracter representa a ese numero, en caso de que sea una letra, encontrarmos el valor que representa esa letra, por medio de una simple operacion matematica, aprovechando los valores ASCII.

Primero declaramos una variable tipo float `result`, la cual se encarga de guardar el resultado, luego hacemos el proceso descrito anteriormente, y por ultimo una vez tenemos el resultado, este no esta entre 0 y 1, por ende al devolver el resultado, lo devolvemos dividiendolo por 1000, para que asi quede entre 0 y 1. Escogemos deividir por 1000 especificamente, devido a que en un sistema hexadecimal, el maximo numero que podemos alcanzar con dos numero es 255.

Para el caso de `firstNumber` el numero que representa lo multiplicamos por 16, devido a que representa las decenas y lo añadimos a resultado; por otro lado `secondNumber` no lo multiplicamos por nada debido a que representa las unidades, y lo sumamos a `resultado`.

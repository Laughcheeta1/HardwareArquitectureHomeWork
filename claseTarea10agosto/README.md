#Integrantes
Sebastian Ruiz Londoño y Santiago Yepes Mesa

##Descriptcion Codigo
En el coddigo previamente a la definicion del main, simplemente estamos importando <iostream> el cual nos servira para poder pedirle al usuario los tiempos a los cuales desea cambiar el parpadeo de los leds.
Ya dentro de main, primero declaramos las cariables "redTime", "blue"TIme" y "greenTime", las cuales seran las variables que guardaran el tiempo de prendido / apagado de los leds.
Desde la linea 18 a la 25 estamos simplemente pidiendole al usuario estos tiempos, y lo estamos guardando en las variables correspondientes.
De la linea 28 a la 30 estamos inicializando los 3 leds en cuestion como objetos.
Despues de eso incializamos una variable de tipo long long la cual se encarga de mantener el tiempo (en milisegundos), que ha pasado.
De la linea 33 a 35 sencillamente estamos prendiendo los leds (cambiarlos de su estado original, apagado, a el otro estado, prendido).

Siguientemente vene la parte que hace en verdad el trabajo. 
Ahi lo que estamos haciendo es hacer un loop infinito en donde lo que se busca es que cada vez que el tiempo transcurrido sea un multiplo de uno de los tiempos dados por el usuario, el led en cuestion, del cual el tiempo es multiplo, va a cambiar de estado. Una vez se chequeen estos tiempos, ponemos el programa a dormirse por un milisegundo (la cual es la unidad en la cual medimos el tiempo) y le sumamos 1 a el tiempo transcurrido (ya que pusimos a esperar el programa 1 milisegundo).



![](./resources/official_armmbed_example_badge.png)
# Blinky Mbed OS example

The example project is part of the [Arm Mbed OS Official Examples](https://os.mbed.com/code/) and is the [getting started example for Mbed OS](https://os.mbed.com/docs/mbed-os/latest/quick-start/index.html). It contains an application that repeatedly blinks an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

You can build the project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).
(Note: To see a rendered example you can import into the Arm Online Compiler, please see our [import quick start](https://os.mbed.com/docs/mbed-os/latest/quick-start/online-with-the-online-compiler.html#importing-the-code).)

## Mbed OS build tools

### Mbed CLI 2
Starting with version 6.5, Mbed OS uses Mbed CLI 2. It uses Ninja as a build system, and CMake to generate the build environment and manage the build process in a compiler-independent manner. If you are working with Mbed OS version prior to 6.5 then check the section [Mbed CLI 1](#mbed-cli-1).
1. [Install Mbed CLI 2](https://os.mbed.com/docs/mbed-os/latest/build-tools/install-or-upgrade.html).
1. From the command-line, import the example: `mbed-tools import mbed-os-example-blinky`
1. Change the current directory to where the project was imported.

### Mbed CLI 1
1. [Install Mbed CLI 1](https://os.mbed.com/docs/mbed-os/latest/quick-start/offline-with-mbed-cli.html).
1. From the command-line, import the example: `mbed import mbed-os-example-blinky`
1. Change the current directory to where the project was imported.

## Application functionality

The `main()` function is the single thread in the application. It toggles the state of a digital output connected to an LED on the board.

**Note**: This example requires a target with RTOS support, i.e. one with `rtos` declared in `supported_application_profiles` in `targets/targets.json` in [mbed-os](https://github.com/ARMmbed/mbed-os). For non-RTOS targets (usually with small memory sizes), please use [mbed-os-example-blinky-baremetal](https://github.com/ARMmbed/mbed-os-example-blinky-baremetal) instead.

## Building and running

1. Connect a USB cable between the USB port on the board and the host computer.
1. Run the following command to build the example project and program the microcontroller flash memory:

    * Mbed CLI 2

    ```bash
    $ mbed-tools compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

    * Mbed CLI 1

    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

Your PC may take a few minutes to compile your code.

The binary is located at:
* **Mbed CLI 2** - `./cmake_build/mbed-os-example-blinky.bin`</br>
* **Mbed CLI 1** - `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin`

Alternatively, you can manually copy the binary to the board, which you mount on the host computer over USB.

## Expected output
The LED on your target turns on and off every 500 milliseconds.


## Troubleshooting
If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.

## Related Links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html).
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html).
* [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html).
* [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see [CONTRIBUTING.md](./CONTRIBUTING.md) for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.

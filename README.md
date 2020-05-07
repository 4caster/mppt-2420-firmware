## Встроенно ПО для управления МРРТ контроллерами

Данное ПО предназначается для управления различными контроллерами заряда с алгоритмами поиска ТММ солнечных панелей на базе микроконтроллера STM32F334C4T6. ПО может управлять контроллером по топологии синхронный buck с любыми параметрами напряжения и тока. Настройки входных и выходных параметров задаются с помощью параметрирующих структур. 

## Совместимые проекты

* [Solar charge controller with MPPT: 20A 60V input max](https://github.com/gardarica/mppt-2420-hardware)

## Структура проекта

* **docs** - документация на проект
* **firmware** - исходный код проекта

## Инструменты

* [Visual Studio Code](https://code.visualstudio.com/)
    * [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
    * [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)
* [GNU MCU Eclipse ARM Embedded GCC](https://github.com/xpack-dev-tools/arm-none-eabi-gcc-xpack/releases)
* [GNU MCU Eclipse Windows Build Tools](https://github.com/gnu-mcu-eclipse/windows-build-tools/releases)
* [JLink](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)

## Лицензирование

Все исходные материалы для проекта распространяются по лицензии [MIT](./LICENSE "Описание лицензии"). Вы можете использовать проект в любом виде, в том числе и для коммерческой деятельности, но стоит помнить, что автор проекта не дает никаких гарантий на работоспособность устройства или частей проекта, а так же не несет никакой ответственности по искам или за нанесенный ущерб.

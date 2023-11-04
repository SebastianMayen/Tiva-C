#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

int i;

// Funciones para controlar los LEDs
void toggleRedLED(uint32_t index, bool state);
void toggleGreenLED(uint32_t index, bool state);

int main(void)
{
    // Configura el sistema para 40MHz
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Habilita los periféricos GPIO, los botones y los LEDs
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD) ||
           !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE) ||
           !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB) ||
           !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA) ||
           !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC)) {}

    // Configura los pines GPIO para los LEDs rojos en PD0, PD1, PD2 y PD3
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    // Configura los pines GPIO para los LEDs verdes en PE4, PE5, PB4 y PA5
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_5);

    // Configura los pines GPIO para los botones en PC4, PC5, PC6 y PC7
    GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
    GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    // Inicialmente, todos los LEDs verdes están encendidos
    toggleGreenLED(0, true);
    toggleGreenLED(1, true);
    toggleGreenLED(2, true);
    toggleGreenLED(3, true);

    // Variables para controlar el estado de los botones
    bool buttonState[4] = {true, true, true, true}; // Inicialmente, todos los botones están en estado soltado

    while (1)
    {
        // Evalúa el estado de los botones y controla los LEDs de forma independiente
        for (i = 0; i < 4; i++)
        {
            bool isPressed = GPIOPinRead(GPIO_PORTC_BASE, 1 << (i + 4)) == 0;
            if (isPressed && buttonState[i])
            {
                // Botón presionado
                buttonState[i] = false;
                toggleRedLED(i, true);
                toggleGreenLED(i, false);
            }
            else if (!isPressed && !buttonState[i])
            {
                // Botón soltado
                buttonState[i] = true;
                toggleRedLED(i, false);
                toggleGreenLED(i, true);
            }
        }
    }
}

// Función para controlar los LEDs rojos
void toggleRedLED(uint32_t index, bool state)
{
    if (state)
        GPIOPinWrite(GPIO_PORTD_BASE, 1 << index, 1 << index); // Enciende el LED rojo correspondiente
    else
        GPIOPinWrite(GPIO_PORTD_BASE, 1 << index, 0); // Apaga el LED rojo correspondiente
}

// Función para controlar los LEDs verdes
void toggleGreenLED(uint32_t index, bool state)
{
    switch (index)
    {
        case 0:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, state ? GPIO_PIN_4 : 0);
            break;
        case 1:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, state ? GPIO_PIN_5 : 0);
            break;
        case 2:
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, state ? GPIO_PIN_4 : 0);
            break;
        case 3:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, state ? GPIO_PIN_5 : 0);
            break;
        default:
            break;
    }
}

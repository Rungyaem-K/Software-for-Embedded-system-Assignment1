#include "mbed.h"

DigitalOut led(LED1);
DigitalIn button(PC_13);

int main()
{
    while(1) {
       if (button == 1) {
            led = 0;     // Turn led1 off.
        }

        else if (button == 0) {  
            led = 1;  
        }
    }
}

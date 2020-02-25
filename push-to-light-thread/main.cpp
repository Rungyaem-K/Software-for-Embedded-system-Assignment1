#include "mbed.h"
 
DigitalOut led1(LED1);
DigitalOut led2(PB_14);
InterruptIn button(USER_BUTTON);

Thread thread_led;
 
void button_action() 
{
    while(1) 
    {
        led2 = !button;
    }
}
 
int main() {
    thread_led.start(callback(button_action));
    while(1) 
    {
        led1 = 1; // LED is ON
        wait(0.2); // 200 ms
        led1 = 0; // LED is OFF
        wait(0.2); // 200 ms
    }
}
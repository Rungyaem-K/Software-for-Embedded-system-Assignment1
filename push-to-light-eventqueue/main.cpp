#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
InterruptIn button(PC_13);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t;

void toggle() {   
    led2=!led2;
}


int main() {
	led2=0;
	t.start(callback(&queue, &EventQueue::dispatch_forever));
    	button.rise(toggle);     					//push to light
   	button.fall(queue.event(toggle));	

	while(1) {
         led1 = 1; 							// LED is ON
         wait(0.2); 							// 200 ms
         led1 = 0; 							// LED is OFF
         wait(0.8); 							// 800 ms
     		}

}     
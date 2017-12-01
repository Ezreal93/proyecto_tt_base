#include "hld_uart.h"
#include "serial_stdio.h"

void delay_ms(int delay_time);

int main(){
    uart2_init(9600);
    while(1){
        serial_printf(uart2_puts, "Hello, world!\n");
        delay_ms(500);
    }
}

void delay_ms(int delay_time){
    for(int i = 0; i < delay_time; i++){
        for(int j = 0; j < 1000; j++){
        }
    }
}

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "include/display.h"

int main()
{
    stdio_init_all();
    screen_init();

    while (true) {
        printf("Hello, world!\n");
        screen_message("Hello, world!");
        sleep_ms(1000);
    }
}

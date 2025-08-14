#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "include/display.h"
#include "include/soloA.h"

int main(void) {
    stdio_init_all();
    screen_init();
    soloA_init();

    while (true) {
        const char* status_solo = soloA_status_solo();

        char status_str[20];
        sprintf(status_str, "Status: %s", status_solo);

        // Terminal
        printf("%s\n", status_str);

        // OLED
        screen_message(status_str);

        sleep_ms(1000);
    }
}
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "include/display.h"
#include "include/soloA.h"
#include "include/soloB.h"

int main(void) {
    stdio_init_all();
    screen_init();
    soloA_init();
    soloB_init();

    char linha1[16], linha2[16], linha3[16], linha4[16];

    while (true) {
        // Lê solo A
        const char* status_soloA = soloA_status_solo();

        // Lê solo B
        uint16_t valorB = soloB_read_raw_avg(30);
        float umidadeB = soloB_read_percent(valorB);

        // Prepara as linhas para o display
        sprintf(linha1, "SoloA: %s", status_soloA);
        sprintf(linha2, "SoloB: %.1f%%", umidadeB);
        sprintf(linha3, "ADC: %u", valorB);
        sprintf(linha4, "");  // Linha 4 vazia, pode usar para outra info

        // Mostra no terminal
        printf("%s | %s | %s\n", linha1, linha2, linha3);

        // Mostra no OLED
        screen_message_4lines(linha1, linha2, linha3, linha4);

        sleep_ms(1000);
    }
}
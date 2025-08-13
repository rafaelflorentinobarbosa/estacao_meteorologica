#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "include/display.h"
#include "include/soloA.h"

int main()
{
    stdio_init_all();
    screen_init();
    soloA_init();

    // Mensagem de Inicialização
    //printf("Hello, world!\n");
    //screen_message("Hello, world!");
    //sleep_ms(1000);

    while (true) {

        // Lê o status do solo e o valor analógico
        const char* status_solo = soloA_status_solo();

        // le o valor bruto do solo
        uint16_t valor_umidade_raw = soloA_ler_analogico();
        
        // Converte o valor bruto em uma porcentagem
        // float umidade_porcentagem = ((float)valor_umidade_raw / 4095.0f) * 100.0f;
        float umidade_porcentagem = 100 - (((float)valor_umidade_raw - 0) / (4095 - 0)) * 100;
        
        // Cria strings para o display e para o terminal
        char valor_bruto_str[20];
        char umidade_str[20];
        char status_str[20];

        // Exibe as mensagens na tela OLED
        sprintf(valor_bruto_str, "Valor: %d", valor_umidade_raw);
        sprintf(umidade_str, "Umidade: %.2f%%", umidade_porcentagem);
        sprintf(status_str, "Status: %s", status_solo);

        // Exibe as mensagens no terminal
        printf("%s\n", valor_bruto_str);
        printf("%s\n", umidade_str);
        printf("%s\n", status_str);

        screen_message_4lines("Dados Solo", valor_bruto_str, umidade_str, status_str);
        sleep_ms(1000);

    }
}

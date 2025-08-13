#include "include/soloA.h"
#include "hardware/gpio.h" // Adicionado para as funções gpio_init e gpio_get

void soloA_init() {
    // Inicializa o pino digital (D0) como entrada
    gpio_init(SENSOR_SOLO_PINO_DIGITAL_DO);
    gpio_set_dir(SENSOR_SOLO_PINO_DIGITAL_DO, GPIO_IN);

    // Inicializa o pino analógico (A0) para o ADC
    adc_init();
    adc_gpio_init(SENSOR_SOLO_PINO_ANALGICO_A0);
}

// retorna o valor bruto do solo 0-4095
uint16_t soloA_ler_analogico() {
    // Seleciona o canal do ADC para leitura
    adc_select_input(SENSOR_SOLO_CANAL_ADC);

    // Lê o valor bruto do ADC (0-4095)
    return adc_read();
}

bool soloA_ler_digital() {
    // Lê o estado do pino digital
    // O sensor D0 é HIGH (verdadeiro) quando o solo está seco
    return gpio_get(SENSOR_SOLO_PINO_DIGITAL_DO);
}

// Implementação da nova função usando a leitura digital
const char* soloA_status_solo() {
    bool solo_seco = soloA_ler_digital();
    
    // Compara o valor digital. A função soloA_ler_digital() retorna true quando o solo está seco.
    if (solo_seco) {
        return "Seco";
    } else {
        return "Umido";
    }
}
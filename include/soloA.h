#ifndef SOLOA_H
#define SOLOA_H

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdint.h>    // Adicionado para o tipo uint16_t
#include <stdbool.h>   // Adicionado para o tipo bool

// Define os pinos do sensor, conforme sua ligação na placa BitDogLab
#define SENSOR_SOLO_PINO_DIGITAL_DO 16
#define SENSOR_SOLO_PINO_ANALGICO_A0 28

// Define o canal do ADC. GP28 corresponde ao ADC 2 na Raspberry Pi Pico.
#define SENSOR_SOLO_CANAL_ADC 2

#define LIMIAR_UMIDADE_SECA 2000 // Exemplo de valor. Ajuste conforme sua calibração.

// Inicializa o sensor de solo, configurando os pinos e o ADC.
void soloA_init();

// Lê o valor analógico da umidade do solo (0-4095).
uint16_t soloA_ler_analogico();

// Lê o valor digital da umidade do solo (true = seco, false = úmido).
bool soloA_ler_digital();

// Retorna uma string que indica se o solo está seco ou úmido.
const char* soloA_status_solo();

#endif // SOLOA_H
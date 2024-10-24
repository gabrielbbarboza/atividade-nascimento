#include <stdio.h>
#include "nascimento.h"

int main() {
    data_t nascimento;
    nascimento.dia = 15;  // Altere para a data desejada
    nascimento.mes = 10;   // Altere para o mês desejado
    nascimento.ano = 2000; // Altere para o ano desejado

    int dias = dias_de_vida(nascimento);

    if (dias != -1) {
        printf("Dias de vida: %d\n", dias);
    } else {
        printf("Erro ao calcular os dias de vida.\n");
    }

    return 0;
}

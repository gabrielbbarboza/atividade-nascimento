#include "nascimento.h"
#include <stdio.h>
#include <time.h>

// Função que calcula a quantidade de dias de vida desde a data de nascimento
int dias_de_vida(data_t nasc) {
    time_t t = time(NULL);  // Obter o tempo atual em segundos desde 1970
    struct tm tm_atual = *localtime(&t);  // Converter para estrutura tm

    // Criar uma struct tm para a data de nascimento
    struct tm tm_nasc = {0};
    tm_nasc.tm_year = nasc.ano - 1900;  // tm_year conta a partir de 1900
    tm_nasc.tm_mon = nasc.mes - 1;      // tm_mon vai de 0 (janeiro) a 11 (dezembro)
    tm_nasc.tm_mday = nasc.dia;

    // Converter ambas as datas para time_t
    time_t time_nasc = mktime(&tm_nasc);
    time_t time_atual = mktime(&tm_atual);

    // Verificar se a conversão falhou
    if (time_nasc == -1 || time_atual == -1) {
        return -1;  // Erro ao converter as datas
    }

    // Calcular a diferença em segundos e converter para dias
    double segundos_de_vida = difftime(time_atual, time_nasc);
    int dias_de_vida = (int)(segundos_de_vida / (60 * 60 * 24));  // Converter de segundos para dias

    return dias_de_vida;
}

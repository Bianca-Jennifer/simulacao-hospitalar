#include "pacientes_tabela.h"
#include <stdio.h>


int main() {
    FILE *arquivo = fopen("pacientes.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    tabela_hash tabela;
    inicializar_tabela(&tabela);

    adicionar_pacientes(&tabela, arquivo);
    imprimir_tabela(&tabela);

    fclose(arquivo);
    return 0;
}



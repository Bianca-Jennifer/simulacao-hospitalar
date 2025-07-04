#include "pacientes_tabela.h"
#include "deque.h"
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));

    FILE *arquivo = fopen("pacientes.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo.");
        return 1;
    }

    tabela_hash tabela;
    inicializar_tabela(&tabela);

    adicionar_pacientes(&tabela, arquivo);
    imprimir_tabela(&tabela);

    Deque deque;
    inicia_deque(&deque);
    sortear(&tabela, &deque);
    sortear(&tabela, &deque);
    printf("\nSorteado\n");
    imprime_deque(&deque);

    fclose(arquivo);
    return 0;
}



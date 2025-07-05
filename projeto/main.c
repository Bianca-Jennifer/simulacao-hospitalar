#include "pacientes_tabela.h"
#include "deque.h"
#include "leito_lista.h"
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
    sortear(&tabela, &deque);
    printf("\nSorteado\n");
    imprime_deque(&deque);
    printf("\n");
    imprimir_tabela(&tabela);


    //remove_inicio(&deque);
    //printf("\nRemovido\n");
    //imprime_deque(&deque);
    //remove_final(&deque);
    //printf("\nRemovido\n");
    imprime_deque(&deque);
    printf("\n");

    Lista_de_leitos l;
    inicializa_lista(&l);
    inserir_leito(&l,&deque);
    printf("-----------\n\n");
    exibe_lista(&l);
    imprime_deque(&deque);
    printf("-------------\n");

    remover_leito(&l);
    printf("----------\n");
    exibe_lista(&l);

    /*printf("Removendo primeiro elemento...\n");
    remover_leito(&l,l.leitos[0]);
    exibe_lista(&l);*/


    //imprimir_tabela(&tabela);

    fclose(arquivo);
    return 0;
}



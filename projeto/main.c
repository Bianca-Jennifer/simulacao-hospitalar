#include "pacientes_tabela.h"
#include "deque.h"
#include "leito_lista.h"
#include "pilha.h"
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

    Lista_de_leitos l;
    inicializa_lista(&l);
    printf("Sorteado paciente para o leito!\n");
    inserir_leito(&l,&deque);
    printf("Pacientes no leito:\n");
    exibe_lista(&l);
    imprime_deque(&deque);
    printf("-------------\n");

    pilha *pilha = NULL;

    remover_leito(&l, &pilha);
    printf("----------\n");
    exibe_lista(&l);
    imprimir_pilha(pilha);

    fclose(arquivo);
    return 0;
}



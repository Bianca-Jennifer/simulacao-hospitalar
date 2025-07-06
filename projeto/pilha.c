#include "pilha.h"
#include "leito_lista.h"
#include "log.h"

#include <string.h>

int contador_pilha = 0; // variável global

int esta_vazia(pilha *topo){
    return topo == NULL;
}

void push(pilha **topo, Leito *paciente){
    pilha *novo = (pilha *)malloc(sizeof(pilha));

    if(novo == NULL){
        printf("ERRO!\n");
        return;
    }

    strcpy(novo->id, paciente->id);
    strcpy(novo->nome, paciente->nome);
    novo->idade = paciente->idade;
    strcpy(novo->sexo, paciente->sexo);
    strcpy(novo->cpf, paciente->cpf);
    novo->prioridade = paciente->prioridade;
    novo->atendido = paciente->atendido;

    novo->proximo = *topo;
    *topo = novo;
    contador_pilha++;
}

void imprimir_pilha(pilha *topo){
    if(esta_vazia(topo)){
        printf("A pilha está vazia!\n");
        return;
    }

    //printf("Pacientes que receberam alta:\n");
    int cont = 1;
    while(topo != NULL){
        printf("%d ALTA    - %s (%s)\n",cont,topo->id, topo->nome);
        fprintf(arquivo_log, "%d ALTA    - %s (%s)\n",cont,topo->id, topo->nome);
        topo = topo->proximo;
        cont++;
    }
}


#include "pilha.h"
#include "leito_lista.h"
#include <string.h>

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
}

void imprimir_pilha(pilha *topo){
    if(esta_vazia(topo)){
        printf("A pilha está vazia!\n");
        return;
    }

    printf("Pacientes que receberam alta:\n");
    while(topo != NULL){
        printf("ID: %s, Nome: %s, Idade: %d, Sexo: %s, CPF: %s, Prioridade: %d, Atendido: %d\n",topo->id, topo->nome, topo->idade, topo->sexo, topo->cpf, topo->prioridade, topo->atendido); 
        topo = topo->proximo;
    }
}


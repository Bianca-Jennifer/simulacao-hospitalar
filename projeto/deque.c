#include <string.h>
#include <stdio.h>
#include "deque.h"

void inicia_deque(Deque *d){
    d->inicio = NULL;
    d->final = NULL;
    d->tamanho = 0;
}

void insere_inicio(Deque *deque, No_d* no_tabela){
    No_d *no_deque = (No_d *)malloc(sizeof(No_d));

    if (no_deque == NULL) {
        printf("ERRO!\n");
        return;
    }

    strcpy(no_deque->id, no_tabela->id);
    strcpy(no_deque->nome, no_tabela->nome);
    no_deque->idade = no_tabela->idade;
    strcpy(no_deque->sexo, no_tabela->sexo);
    strcpy(no_deque->cpf, no_tabela->cpf);
    no_deque->prioridade = no_tabela->prioridade;
    no_deque->atendido = no_tabela->atendido;

    no_deque->proximo = deque->inicio;
    no_deque->anterior = NULL;

    if(deque->inicio != NULL){
        deque->inicio->anterior = no_deque;
    }

    deque->inicio = no_deque;

    if(deque->final == NULL){
        deque->final = no_deque;
    }

    deque->tamanho++;
    no_deque->atendido++;
}

void insere_final(Deque *deque, No_d* no_tabela){
    No_d *no_deque = (No_d *)malloc(sizeof(No_d));

    if (no_deque == NULL) {
        printf("Erro de alocação\n");
        return;
    }

    strcpy(no_deque->id, no_tabela->id);
    strcpy(no_deque->nome, no_tabela->nome);
    no_deque->idade = no_tabela->idade;
    strcpy(no_deque->sexo, no_tabela->sexo);
    strcpy(no_deque->cpf, no_tabela->cpf);
    no_deque->prioridade = no_tabela->prioridade;
    no_deque->atendido = no_tabela->atendido;

    no_deque->proximo = NULL;
    no_deque->anterior = deque->final;

    if(deque->final != NULL){
        deque->final->proximo = no_deque;
    }

    deque->final = no_deque;

    if(deque->inicio == NULL){
        deque->inicio = no_deque;
    }

    deque->tamanho++;
    no_deque->atendido++;
}

int remove_inicio(Deque *deque, No_d* paciente_removido) {
    if(deque->inicio == NULL){
        printf("Deque vazio!\n");
        return 1;
    }

    No_d *temp = deque->inicio;
    *paciente_removido = *temp;
    deque->inicio = deque->inicio->proximo;

    if(deque->inicio == NULL){
        deque->final = NULL;
    }else{
        deque->inicio->anterior = NULL;
    }

    free(temp);
    deque->tamanho--;

    return 0;
}

int remove_final(Deque *deque, No_d* paciente_removido){
    if(deque->inicio == NULL){
        printf("Deque vazio!\n");
        return 1;
    }

    No_d *temp = deque->final;
    *paciente_removido = *temp;
    deque->final = deque->final->anterior;

    if(deque->final == NULL){
        deque->inicio = NULL;
    }else{
        deque->final->proximo = NULL;
    }

    free(temp);
    deque->tamanho--;

    return 0;
}

int pega_prioridade_inicio(Deque *deque){
    if(deque->inicio == NULL){
        printf("Deque vazio!\n");
        return -1;
    }

    return deque->inicio->prioridade;
}

int pega_prioridade_final(Deque *deque){
    if(deque->final == NULL){
        printf("Deque vazio!\n");
        return -1;
    }

    return deque->final->prioridade;
}

int esta_vazio(Deque *deque){
    return deque->tamanho == 0;
}

void imprime_deque(Deque *deque){
    if(esta_vazio(deque)){
        printf("Deque vazio!\n");
        return;
    }

    No_d *paciente_atual = deque->inicio;

    //printf("Deque:\n");
    while(paciente_atual != NULL){
         /*printf("  ID: %s, Nome: %s, Idade: %d, Sexo: %s, CPF: %s, Prioridade: %d, Atendido: %d\n",
                   paciente_atual->id, paciente_atual->nome, paciente_atual->idade, paciente_atual->sexo,
                   paciente_atual->cpf, paciente_atual->prioridade, paciente_atual->atendido);*/
        printf("ESPERA    - %s (prioridade %d)\n",paciente_atual->id, paciente_atual->prioridade);    
        paciente_atual = paciente_atual->proximo;
    }
}

No_d* converter_para_deque(No *no) {
    No_d *novo = malloc(sizeof(No_d));

    if (novo == NULL) {
        printf("Erro de alocação\n");
        return NULL;
    }
    
    strcpy(novo->id, no->id);
    strcpy(novo->nome, no->nome);
    novo->idade = no->idade;
    strcpy(novo->sexo, no->sexo);
    strcpy(novo->cpf, no->cpf);
    novo->prioridade = no->prioridade;
    novo->atendido = no->atendido;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}
#include "pacientes_tabela.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inicializar_tabela(tabela_hash *tabela){
    for(int i = 0; i < TAMANHO; i++){
        tabela->tabela[i] = NULL;
    }
}

//Processo de preencher
int id_para_inteiro(char *id) {
    return atoi(id + 3);
}

int funcao_hash(int id){
  return id % TAMANHO;
}

void inserir_na_tabela(tabela_hash *tabela, No* novo_no){
  int indice = funcao_hash(id_para_inteiro(novo_no->id));
  

  if(tabela->tabela[indice] == NULL){
    tabela->tabela[indice] = novo_no;
  }else{
    novo_no->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novo_no;
  }
}


void adicionar_pacientes(tabela_hash *tabela, FILE* arquivo){

  char linha[256];
  fgets(linha, sizeof(linha), arquivo);

  while (fgets(linha, sizeof(linha), arquivo)) {
    No *novo_no = (No *)malloc(sizeof(No));
    sscanf(linha, "%6[^;];%19[^;];%d;%1[^;];%d;%d;%d", novo_no->id, novo_no->nome, &novo_no->idade, novo_no->sexo, &novo_no->cpf, &novo_no->prioridade, &novo_no->atendido);
    novo_no->proximo = NULL;
    inserir_na_tabela(tabela,novo_no);
  }
}


void imprimir_tabela(tabela_hash *tabela) {
    for (int i = 0; i < TAMANHO; i++) {
        printf("Índice %d:\n", i);
        No *paciente_atual = tabela->tabela[i];
        while (paciente_atual != NULL) {
            printf("  ID: %s, Nome: %s, Idade: %d, Sexo: %s, CPF: %d, Prioridade: %d, Atendido: %d\n",
                   paciente_atual->id, paciente_atual->nome, paciente_atual->idade, paciente_atual->sexo,
                   paciente_atual->cpf, paciente_atual->prioridade, paciente_atual->atendido);
            paciente_atual = paciente_atual->proximo;
        }
    }
}
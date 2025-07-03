#ifndef PACIENTES_TABELA_H
#define PACIENTES_TABELA_H

#include <stdio.h>

#define TAMANHO 50

typedef struct No {
  char id[7];
  char nome[20];
  int idade;
  char sexo[2];
  int cpf;
  int prioridade;
  int atendido;
  struct No *proximo;
} No;

typedef struct tabela_hash {
  No *tabela[TAMANHO];
} tabela_hash;

void inicializar_tabela(tabela_hash *tabela);
int id_para_inteiro(char *id);
int funcao_hash(int id);
void inserir_na_tabela(tabela_hash *tabela, No* novo_no);
void adicionar_pacientes(tabela_hash *tabela, FILE* arquivo);
void imprimir_tabela(tabela_hash *tabela);

#endif 

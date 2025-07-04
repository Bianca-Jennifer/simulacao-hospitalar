#ifndef PACIENTES_TABELA_H
#define PACIENTES_TABELA_H

#include <stdio.h>

#define TAMANHO 50

typedef struct No {
  char id[7];
  char nome[20];
  int idade;
  char sexo[2];
  char cpf[12];
  int prioridade;
  int atendido;
  struct No *proximo;
} No;

typedef struct tabela_hash {
  No *tabela[TAMANHO];
} tabela_hash;

typedef struct Deque Deque;

void inicializar_tabela(tabela_hash *tabela);
int id_para_inteiro(char *id);
int funcao_hash(int id);
void inserir_na_tabela(tabela_hash *tabela, No* novo_no);
void adicionar_pacientes(tabela_hash *tabela, FILE* arquivo);
void inserir_no_deque(No *tabela, Deque *deque);
void sortear(tabela_hash *tabela, Deque *deque);
int sortear_numero();



void imprimir_tabela(tabela_hash *tabela);

#endif 

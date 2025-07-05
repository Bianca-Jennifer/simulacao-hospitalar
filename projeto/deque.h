#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include "pacientes_tabela.h"

typedef struct No_d {
  char id[7];
  char nome[20];
  int idade;
  char sexo[2];
  char cpf[12];
  int prioridade;
  int atendido;
  struct No_d *proximo;
  struct No_d *anterior;
} No_d;

typedef struct Deque {
    No_d *inicio;
    No_d *final;
    int tamanho;
} Deque;

void inicia_deque(Deque *d);
void insere_inicio(Deque *deque, No_d* no_tabela);
void insere_final(Deque *deque, No_d* no_tabela);
int remove_inicio(Deque *deque, No_d* paciente_removido);
int remove_final(Deque *deque, No_d* paciente_removido);
int pega_prioridade_inicio(Deque *deque);
int pega_prioridade_final(Deque *deque);
int esta_vazio(Deque *deque);
void imprime_deque(Deque *deque);
No_d* converter_para_deque(No *no);

#endif
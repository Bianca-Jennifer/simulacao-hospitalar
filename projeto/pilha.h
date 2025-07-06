#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Leito Leito;

typedef struct pilha{
char id[7];
  char nome[50];
  int idade;
  char sexo[2];
  char cpf[12];
  int prioridade;
  int atendido;
  struct pilha *proximo;
}pilha;

int esta_vazia(pilha *topo);
void push(pilha **topo, Leito *paciente);
void imprimir_pilha(pilha *topo);

#endif
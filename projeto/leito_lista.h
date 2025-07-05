#ifndef LEITO_LISTA_H
#define LEITO_LISTA_H

#define MAX 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

typedef struct Leito{
  char id[7];
  char nome[50];
  int idade;
  char sexo[2];
  char cpf[12];
  int prioridade;
  int atendido;
}Leito;

typedef struct Lista_de_leitos{ 
    Leito leitos[MAX];
    int quant_elem;
} Lista_de_leitos;

void inicializa_lista(Lista_de_leitos *l);
int tamanho(Lista_de_leitos *l);
int busca(Lista_de_leitos *l, Leito leito_verificado);
void exibe_lista(Lista_de_leitos *l);
Leito criar_leito(No_d *no); 
bool inserir_leito(Lista_de_leitos *l, No_d *no);
bool remover_leito(Lista_de_leitos *l, Leito leito);
#endif 

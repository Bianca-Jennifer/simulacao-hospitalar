#include "pacientes_tabela.h"
#include "deque.h"
#include "log.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inicializar_tabela(tabela_hash *tabela){
    for(int i = 0; i < TAMANHO; i++){
        tabela->tabela[i] = NULL;
    }
    tabela->quant_de_nao_atendidos = 50;
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
    sscanf(linha, "%6[^;];%49[^;];%d;%1[^;];%11[^;];%d;%d", novo_no->id, novo_no->nome, &novo_no->idade, novo_no->sexo, novo_no->cpf, &novo_no->prioridade, &novo_no->atendido);
    novo_no->proximo = NULL;
    inserir_na_tabela(tabela,novo_no);
  }
}

void inserir_no_deque(tabela_hash *tabela_geral, No *tabela, Deque *deque){
  No_d *no_deque = converter_para_deque(tabela);
  if (no_deque == NULL) return;

  tabela_geral->quant_de_nao_atendidos--;

  if(no_deque->prioridade <= 3){
    insere_final(deque, no_deque);
    tabela->atendido++;
  } else if(no_deque->prioridade <= 5){
    insere_inicio(deque, no_deque);
    tabela->atendido++;
  }

}

void sortear(tabela_hash *tabela, Deque *deque){
  if(deque->tamanho == 20){
    return;
  }

  int tentativas_max = 100;
  int tentativas = 0;

  while(tentativas < tentativas_max){
    int indice = sortear_numero();

    if(tabela->tabela[indice] != NULL){
      if(tabela->tabela[indice]->atendido == 1){
        continue;;
      }
      inserir_no_deque(tabela,tabela->tabela[indice], deque);
      return;
    }

    tentativas++;

    if(deque->tamanho >= 20){
      return;
    }

    
  }

  for(int i = 0; i < TAMANHO; i++){
    if(tabela->tabela[i] != NULL){
      inserir_no_deque(tabela,tabela->tabela[i], deque);
      return;
    }
  }

}

// sorteio entre 0 e 49
int sortear_numero(){
  return rand() % 50; 
}

void imprimir_tabela(tabela_hash *tabela) {
    for (int i = 0; i < TAMANHO; i++) {
        printf("Índice %d:\n", i);
        No *paciente_atual = tabela->tabela[i];
        while (paciente_atual != NULL) {
            printf("  ID: %s, Nome: %s, Idade: %d, Sexo: %s, CPF: %s, Prioridade: %d, Atendido: %d\n",
                   paciente_atual->id, paciente_atual->nome, paciente_atual->idade, paciente_atual->sexo,
                   paciente_atual->cpf, paciente_atual->prioridade, paciente_atual->atendido);
            paciente_atual = paciente_atual->proximo;
        }
    }
}
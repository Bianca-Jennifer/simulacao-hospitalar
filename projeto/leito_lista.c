#include "leito_lista.h"
#include "deque.h"
#include <string.h>

void inicializa_lista(Lista_de_leitos *l){
    l -> quant_elem = 0;
}

int tamanho(Lista_de_leitos *l){
    return l -> quant_elem;
}

int busca(Lista_de_leitos *l, Leito leito){
    for(int i=0; i < l->quant_elem; i++){
        if(strcmp(l->leitos[i].id, leito.id) == 0){
            return i;
        }    
    }
    return -1;
}

void exibe_lista(Lista_de_leitos *l){
    int i;
    printf("Lista:\n");
    for(int i=0; i < l -> quant_elem; i++){
        printf("%s, ", l -> leitos[i].id);
    }
    printf("\n");
}

Leito criar_leito(No_d *no) {
    Leito leito;

    strcpy(leito.id, no->id);
    strcpy(leito.nome, no->nome);
    leito.idade = no->idade;
    strcpy(leito.sexo, no->sexo);
    strcpy(leito.cpf, no->cpf);
    leito.prioridade = no->prioridade;
    leito.atendido = no->atendido;

    return leito;
}

bool inserir_leito(Lista_de_leitos *l, Deque *deque) {
    if (l->quant_elem == MAX) {
        return false; 
    }

    int a = pega_prioridade_inicio(deque);
    int b = pega_prioridade_final(deque);

    No_d paciente_removido;

    if(a >= b){
        if(remove_inicio(deque, &paciente_removido) != 0){
            return false;
        }
    }else{
        if(remove_inicio(deque, &paciente_removido) != 0){
            return false;
        }
    }
    
    Leito novo_leito = criar_leito(&paciente_removido);

    l->leitos[l->quant_elem] = novo_leito; 
    l->quant_elem++;

    return true;
}

bool remover_leito(Lista_de_leitos *l, Leito leito){
    int pos, j;
    pos = busca(l, leito);

    if(pos == -1){
        return false;
    }    
    for(j=pos; j < l->quant_elem-1; j++){
        l->leitos[j] = l->leitos[j+1];
        l->quant_elem--;
        return true; 
    }
}


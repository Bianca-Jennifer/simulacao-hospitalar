#include "leito_lista.h"
#include "pilha.h"
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

//Sortear a quantidade de pacientes que vão receber alta
int sortear_quantidade(Lista_de_leitos *l){
    if(l->quant_elem == 0)
        return 0;

    if(l->quant_elem <= 4){
        return (rand() % 1) + 1; //Retorna apenas 1
    }else{
        return (rand() % 3) + 1; //Retorna 1,2 ou 3(dps mudar pra poder retornar 0 também)
    }
}

// sorteio entre 0 e a quantidade de elementos na lista
int sortear_indice(Lista_de_leitos *l){
    if (l->quant_elem == 0){ 
        return -1;
    }    

    return rand() % l->quant_elem; 
}


bool remover_leito(Lista_de_leitos *l, pilha **topo){
    int quantidade = sortear_quantidade(l);
    printf("Quantidade de pacientes que serão removidos:%d\n", quantidade);

    for(int cont = 0; cont < quantidade; cont++) {
        int pos, j;
        pos = sortear_indice(l);
        printf("Elemento sorteado: %s\n", l->leitos[pos].nome);

        if(pos == -1){
            return false;
        }
        
        push(topo, &l->leitos[pos]);
        
        for(j=pos; j < l->quant_elem-1; j++){
            l->leitos[j] = l->leitos[j+1];
        }
        l->quant_elem--;
    }
    return true; 
}


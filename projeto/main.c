#include "pacientes_tabela.h"
#include "deque.h"
#include "leito_lista.h"
#include "pilha.h"
#include "log.h"
#include <stdio.h>
#include <time.h>

extern int contador_pilha;

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(seconds) Sleep((seconds) * 1000)  // milissegundos no Windows
#else
    #include <unistd.h>
    #define SLEEP(seconds) sleep(seconds)          // segundos no Linux
#endif

int main() {
    srand(time(NULL));

    FILE *arquivo = fopen("pacientes_e_log/pacientes.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo.");
        return 1;
    }

    arquivo_log = fopen("pacientes_e_log/processamento.log", "a");
    if(arquivo_log == NULL){
        perror("Erro ao abrir o arquivo.");
        return 1;
    }

    tabela_hash tabela;
    inicializar_tabela(&tabela);
    adicionar_pacientes(&tabela, arquivo);


    Deque deque;
    inicia_deque(&deque);

    Lista_de_leitos l;
    inicializa_lista(&l);

    pilha *pilha = NULL;

    fclose(arquivo);
    int quantidade_de_ciclos = 1;

    while(contador_pilha <= 50){ //Enquanto não tem 50 pacientes com alta,executa os ciclos
        printf("\n");
        printf("[Ciclo %d]\n", quantidade_de_ciclos);
        fprintf(arquivo_log, "[Ciclo %d]\n", quantidade_de_ciclos);
        quantidade_de_ciclos++;

        if(contador_pilha == 50) {
            imprimir_pilha(pilha);
            break;//Só pra exibir o resultado final e sair do loop
        }

        imprimir_pilha(pilha);
        if(l.quant_elem != 0){ //Verifica se tem paciente no leito para receber alta(há sorteio da quan. e quem)
            remover_leito(&l,&pilha);
            
        }

        if(l.quant_elem != 10){//Verifica se tem espaço vazio nos leitos para receber mais no deque
            int quant_de_espacos_vazios_lista = 10 - l.quant_elem;
            int pacientes_do_deque = deque.tamanho;
            int pacientes_para_transferir_para_leito;

            if (quant_de_espacos_vazios_lista < pacientes_do_deque) {
                pacientes_para_transferir_para_leito = quant_de_espacos_vazios_lista;
            } else {
                pacientes_para_transferir_para_leito = pacientes_do_deque;
            }

            for(int cont1 = 0; cont1 < pacientes_para_transferir_para_leito; cont1++){
                inserir_leito(&l,&deque);
            }
           
            exibe_lista(&l);
        }

        if(deque.tamanho != 20 && tabela.quant_de_nao_atendidos != 0){//Verifica se há espaço vazio no deque e pacientes ainda não atendidos para receber da tabela 
            int espacos_vazios_deque = 20 - deque.tamanho;
            int maximo_para_enviar_ao_deque;

            if(espacos_vazios_deque < tabela.quant_de_nao_atendidos) {
                maximo_para_enviar_ao_deque = espacos_vazios_deque;
            }else{
                maximo_para_enviar_ao_deque = tabela.quant_de_nao_atendidos;
            }

            for(int cont2 = 0; cont2 < maximo_para_enviar_ao_deque; cont2++){
                sortear(&tabela, &deque);
            }

            imprime_deque(&deque);
        }
        printf("\n\n");
        printf("Resumo - Internados nos leitos: %d - Lista de espera: %d - Aguardando atendimento: %d - Altas: %d\n", l.quant_elem, deque.tamanho, tabela.quant_de_nao_atendidos, contador_pilha);
        printf("\n\n");
        fprintf(arquivo_log, "\n\n");
        fprintf(arquivo_log, "Resumo - Internados nos leitos: %d - Lista de espera: %d - Aguardando atendimento: %d - Altas: %d\n", l.quant_elem, deque.tamanho, tabela.quant_de_nao_atendidos, contador_pilha);
        fprintf(arquivo_log, "\n\n");

        SLEEP(2);
    }

    fclose(arquivo_log);

    return 0;
}
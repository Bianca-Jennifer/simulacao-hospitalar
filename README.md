# Simulação de Fluxo Hospitalar com Estruturas de Dados

Este projeto foi desenvolvido como **atividade avaliativa da disciplina Estruturas de Dados Básicas I (EDB 1)**, com o objetivo de aplicar, na prática, conceitos fundamentais de estruturas de dados por meio de uma simulação computacional.

A aplicação simula um **ambiente hospitalar automatizado**, controlando o fluxo de pacientes desde a triagem até a alta hospitalar, utilizando **tabela hash, deque e pilha**.

---

## Objetivo do Projeto

Implementar uma simulação automática do fluxo hospitalar a partir de um arquivo de entrada contendo os dados dos pacientes.  
O sistema gerencia:

- Triagem de pacientes  
- Fila de espera  
- Internamento em leitos  
- Alta hospitalar  
- Registro completo de eventos da simulação  

---

## Estruturas de Dados Utilizadas

- **Tabela Hash**  
  Armazena todos os pacientes carregados do arquivo `pacientes.csv`, permitindo sorteio aleatório de pacientes ainda não atendidos.

- **Deque (Fila de Espera)**  
  Controla a fila de pacientes aguardando internamento, permitindo inserções e remoções nas duas extremidades conforme a prioridade.

- **Pilha**  
  Armazena o histórico de pacientes que receberam alta hospitalar.

---

## Fluxo da Simulação (por ciclo)

A cada ciclo da simulação, as seguintes ações são executadas:

### Verificação de vagas nos leitos
- Se houver leito disponível, um paciente é removido do deque e internado.
- A escolha do paciente considera **as duas extremidades do deque**, priorizando aquele com maior prioridade.
- Em caso de empate, o paciente da frente do deque é escolhido.
- Quando ocorre alta, o paciente é removido da lista de leitos e inserido na pilha de histórico.

### Verificação da fila de espera (deque)
- Caso haja espaço no deque e ainda existam pacientes não sorteados na tabela hash:
  - Um paciente é sorteado aleatoriamente.
  - A inserção no deque segue a prioridade:
    - Prioridade **4 ou 5** → início do deque  
    - Prioridade **1, 2 ou 3** → fim do deque  

### Controle da tabela hash
- Pacientes já sorteados são marcados como atendidos.
- Quando todos os pacientes da tabela hash forem transferidos para o deque, não há novas entradas.

### Encerramento da simulação
- A simulação é encerrada automaticamente quando:
  - A tabela hash estiver vazia  
  - O deque estiver vazio  
  - Não houver pacientes internados nos leitos  

---

## Logs do Sistema

Todos os eventos da simulação são registrados:

- **Em tempo real no terminal**
- **Em arquivo de saída**: `processamento.log`

### Formato do log:
```text
[CICLO 05]
ALTA - PAC011 (Carlos Lima)
INTERNADO - PAC007 (prioridade 5)
ESPERA - PAC024 (prioridade 3)

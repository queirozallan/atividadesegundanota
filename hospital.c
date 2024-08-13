#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 100
#define NIVEIS_PRIORIDADE 4

typedef struct {
    char nomePaciente[100];
    int nivelGravidade; // 1 a 4, onde 1 é mais urgente
    int identificador;
    int tempoEspera;
    int duracaoInternacao;
} Paciente;

typedef struct {
    Paciente filaPacientes[LIMITE];
    int inicio, fim, quantidade;
} FilaCircular;

typedef struct Nodo {
    Paciente paciente;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo* inicio;
    Nodo* fim;
} ListaEncadeada;

void inicializaFila(FilaCircular* fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->quantidade = 0;
}

int filaVazia(FilaCircular* fila) {
    return fila->quantidade == 0;
}

int filaCheia(FilaCircular* fila) {
    return fila->quantidade == LIMITE;
}

void enfileira(FilaCircular* fila, Paciente p) {
    if (filaCheia(fila)) {
        printf("Fila cheia!\n");
        return;
    }
    fila->fim = (fila->fim + 1) % LIMITE;
    fila->filaPacientes[fila->fim] = p;
    fila->quantidade++;
}

Paciente desenfileira(FilaCircular* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    Paciente p = fila->filaPacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % LIMITE;
    fila->quantidade--;
    return p;
}

void inicializaLista(ListaEncadeada* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insereLista(ListaEncadeada* lista, Paciente p) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->paciente = p;
    novoNodo->proximo = NULL;
    if (lista->fim == NULL) {
        lista->inicio = lista->fim = novoNodo;
    } else {
        lista->fim->proximo = novoNodo;
        lista->fim = novoNodo;
    }
}

Paciente removeLista(ListaEncadeada* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia!\n");
        exit(1);
    }
    Nodo* temp = lista->inicio;
    Paciente p = temp->paciente;
    lista->inicio = lista->inicio->proximo;
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
    free(temp);
    return p;
}

void gerarRelatorio(FilaCircular* filaAtendimento, ListaEncadeada* listaInternacao) {
    printf("Relatório de Atendimento:\n");
    printf("Pacientes na fila de atendimento:\n");
    int i, totalPacientes = filaAtendimento->quantidade;
    for (i = 0; i < totalPacientes; i++) {
        Paciente p = filaAtendimento->filaPacientes[(filaAtendimento->inicio + i) % LIMITE];
        printf("ID: %d, Nome: %s, Gravidade: %d\n", p.identificador, p.nomePaciente, p.nivelGravidade);
    }
    
    printf("\nRelatório de Internação:\n");
    Nodo* atual = listaInternacao->inicio;
    while (atual != NULL) {
        Paciente p = atual->paciente;
        printf("ID: %d, Nome: %s, Tempo de Internação: %d\n", p.identificador, p.nomePaciente, p.duracaoInternacao);
        atual = atual->proximo;
    }
}

int main() {
    FilaCircular filaAtendimento;
    ListaEncadeada listaInternacao;

    inicializaFila(&filaAtendimento);
    inicializaLista(&listaInternacao);

    // Adiciona pacientes e simula atendimento (exemplo)
    Paciente p1 = {"Carlos", 2, 1, 50, 0};
    Paciente p2 = {"Ana", 1, 2, 40, 10};
    enfileira(&filaAtendimento, p1);
    enfileira(&filaAtendimento, p2);
    
    // Processa atendimento (exemplo simplificado)
    Paciente p = desenfileira(&filaAtendimento);
    p.duracaoInternacao = 30; // Simula internação
    insereLista(&listaInternacao, p);
    
    // Gera relatório
    gerarRelatorio(&filaAtendimento, &listaInternacao);

    return 0;
}

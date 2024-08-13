# atividadesegundanota
Sistemas de Informação - Disciplina: Estruturas de Dados – 3o Período  Atividade para a 2a nota

Sistema de Gerenciamento de Fila de Atendimento de Hospital
Este projeto simula o gerenciamento de pacientes em um hospital, incluindo o cadastro, atendimento, e internação dos pacientes. Utiliza estruturas de dados como filas circulares e listas encadeadas para gerenciar os diferentes aspectos do atendimento hospitalar.

Tabelas de Conteúdos
Objetivo
Estruturas de Dados
Como Executar
Detalhes das Funções
Exemplo de Uso
Licença
Objetivo
O sistema gerencia:

Cadastro de Pacientes: Inclui informações pessoais e níveis de gravidade.
Fila de Atendimento: Gerencia a ordem dos pacientes a serem atendidos.
Internação: Gerencia a fila de internação e o tempo de internação dos pacientes.
Relatórios: Gera relatórios sobre o estado atual das filas e internações.
Estruturas de Dados
Estrutura Paciente
Armazena informações sobre os pacientes, como:

nome: Nome do paciente.
gravidade: Nível de gravidade do paciente (1 a 4).
id: Identificador único do paciente.
tempoAtendimento: Tempo estimado para o atendimento.
tempoInternacao: Tempo de internação (se aplicável).
Estrutura FilaCircular
Gerencia a fila de atendimento e a fila de internação:

pacientes: Array que armazena pacientes.
frente: Índice do início da fila.
tras: Índice do próximo paciente a ser adicionado.
tamanho: Número atual de pacientes na fila.
Estrutura No e ListaEncadeada
Gerencia a lista de internação:

No: Estrutura que contém um paciente e um ponteiro para o próximo nó.
ListaEncadeada: Lista de pacientes internados com ponteiros para o início e fim da lista.
Como Executar
Requisitos
Compilador C: Certifique-se de ter um compilador C, como gcc, instalado no seu sistema.
Compilação
Salve o código fonte em um arquivo chamado hospital.c.

Compile o código usando o seguinte comando:
gcc -o hospital hospital.c
Execute o programa gerado:
./hospital
Detalhes das Funções
Funções da Fila Circular
inicializaFila: Inicializa uma fila circular vazia.
filaVazia: Verifica se a fila está vazia.
filaCheia: Verifica se a fila está cheia.
enfileira: Adiciona um paciente à fila.
desenfileira: Remove um paciente da frente da fila.
Funções da Lista Encadeada
inicializaLista: Inicializa uma lista encadeada vazia.
insereLista: Adiciona um paciente ao final da lista.
removeLista: Remove o paciente do início da lista.
Função de Relatório
gerarRelatorio: Gera e imprime um relatório sobre o estado atual das filas de atendimento e internação.
Exemplo de Uso
O programa adiciona pacientes, processa atendimentos e gera relatórios.

Cadastro e Atendimento:

Adiciona pacientes à fila de atendimento.
Processa o atendimento e simula a internação dos pacientes.
Relatório:

Gera um relatório com o estado atual das filas e pacientes internados.
Exemplo de saída:
Relatório de Atendimento:
Pacientes na fila de atendimento:
ID: 1, Nome: João, Gravidade: 2
ID: 2, Nome: Maria, Gravidade: 1

Relatório de Internação:
ID: 1, Nome: João, Tempo de Internação: 30

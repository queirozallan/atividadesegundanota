# atividadesegundanota

**Sistemas de Informação - Disciplina: Estruturas de Dados – 3º Período**  
**Atividade para a 2ª Nota**

## Sistema de Gerenciamento de Fila de Atendimento de Hospital

Este projeto simula o gerenciamento de pacientes em um hospital, incluindo o cadastro, atendimento e internação dos pacientes. Utiliza estruturas de dados como filas circulares e listas encadeadas para gerenciar os diferentes aspectos do atendimento hospitalar.

## Tabelas de Conteúdos

- [Objetivo](#objetivo)
- [Estruturas de Dados](#estruturas-de-dados)
- [Como Executar](#como-executar)
- [Detalhes das Funções](#detalhes-das-funções)
- [Exemplo de Uso](#exemplo-de-uso)
- [Licença](#licença)

## Objetivo

O sistema gerencia:

- **Cadastro de Pacientes**: Inclui informações pessoais e níveis de gravidade.
- **Fila de Atendimento**: Gerencia a ordem dos pacientes a serem atendidos.
- **Internação**: Gerencia a fila de internação e o tempo de internação dos pacientes.
- **Relatórios**: Gera relatórios sobre o estado atual das filas e internações.

## Estruturas de Dados

### Estrutura Paciente

Armazena informações sobre os pacientes, como:

- **nome**: Nome do paciente.
- **gravidade**: Nível de gravidade do paciente (1 a 4).
- **id**: Identificador único do paciente.
- **tempoAtendimento**: Tempo estimado para o atendimento.
- **tempoInternacao**: Tempo de internação (se aplicável).

### Estrutura FilaCircular

Gerencia a fila de atendimento e a fila de internação:

- **pacientes**: Array que armazena pacientes.
- **frente**: Índice do início da fila.
- **tras**: Índice do próximo paciente a ser adicionado.
- **tamanho**: Número atual de pacientes na fila.

### Estrutura No e ListaEncadeada

Gerencia a lista de internação:

- **No**: Estrutura que contém um paciente e um ponteiro para o próximo nó.
- **ListaEncadeada**: Lista de pacientes internados com ponteiros para o início e fim da lista.

## Como Executar
./hospital

### Requisitos

- **Compilador C**: Certifique-se de ter um compilador C, como `gcc`, instalado no seu sistema.

### Compilação

1. Salve o código fonte em um arquivo chamado `hospital.c`.
2. Compile o código usando o seguinte comando:
   ```sh
   gcc -o hospital hospital.c

#ifndef TYPES_H
#define TYPES_H

#define TAMANHO 100

// Tipo String
typedef char string[TAMANHO];

// Tipo Status do Jogador
typedef enum {INATIVO = 1, ATIVO = 2} status_t;

// Tipo Razão Inatividade do Jogador
typedef enum {REC_MED = 1, VENDIDO = 2} inatividade_t;

// Tipo Resultado Partida
typedef enum {DERROTA = 1, EMPATE = 2, VITORIA = 3} resultado_t;

typedef struct data {
    int dia;
    int mes;
    int ano;
} data_t;

// Tipo Jogadores da Partida


// JOGADORES 

// Tipo Dados Jogador
typedef struct dados_jogador {
    string nome_jogador;
    string posicao;
    int idade;
    float altura;
    float peso;
    float valor_passe;
    float valor_aquisicao;
    float salario;
    data_t admissao;
    data_t venda;
    status_t atividade;
    inatividade_t razao_inatividade;
} dados_jogador_t;

// Membro da Lista para Jogadores
typedef struct no_jogador {
    dados_jogador_t dados;
    struct no_jogador *proximo;
} no_jogador_t;

// Tipo Lista para Jogadores
typedef struct lista_jogador {
    no_jogador_t *cabeca;
    //int nr_nos_jogador;
} lista_jogador_t;

// PARTIDAS

// Tipo Dados Partida
typedef struct dados_partida {
    string nome_adversario;
    data_t data_partida;
    string local_partida;
    resultado_t resultado_partida;
    int qtd_substituicoes;
} dados_partida_t;

// Membro da Lista para Partidas
typedef struct no_partida {
    dados_partida_t dados;
    struct no_partida *proxima;
} no_partida_t;

// Tipo Lista para partidas 
typedef struct lista_partida {
    no_partida_t *cabeca;
    //int nr_nos_partida;
} lista_partida_t;

#endif
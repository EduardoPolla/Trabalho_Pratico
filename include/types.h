#ifndef TYPES_H
#define TYPES_H

#define TAMANHO 100

// Tipo String
typedef char string[TAMANHO];

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
    string atividade;
    string razao_inatividade;
} dados_jogador_t;

// Membro da Lista para Jogadores
typedef struct no_jogador {
    dados_jogador_t dados;
    struct no_jogador *proximo;
} no_jogador_t;

// PARTIDAS

// Tipo Dados Partida
typedef struct dados_partida {
    string nome_adversario;
    data_t data_partida;
    string local_partida;
    string resultado_partida;
    int qtd_substituicoes;
} dados_partida_t;

// Membro da Lista para Partidas
typedef struct no_partida {
    dados_partida_t dados;
    struct no_partida *proxima;
} no_partida_t;

#endif
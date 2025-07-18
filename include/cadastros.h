#ifndef CADASTROS_H
#define CADASTROS_H

#include <stdbool.h>
#include "types.h"

// Jogador
no_jogador_t *novo_registro_jogador();
void insere_novo_registro_jogador(no_jogador_t *novo_jogador, no_jogador_t **lista_jogador);
void inativar_jogador(no_jogador_t **lista_jogador, string nome);
void reativar_jogador(no_jogador_t **lista_jogador, string nome);

// Partida
no_partida_t *novo_registro_partida(no_jogador_t *lista_jogador);
void insere_novo_registro_partida(no_partida_t *novo_partida, no_partida_t **lista_partida);

// Verificadores
bool lista_vazia_jogador(no_jogador_t *lista_jogador);
bool lista_vazia_partida(no_partida_t *lista_partida);
int comparar_datas(data_t d1, data_t d2);
bool jogador_ativo_data(data_t data_partida, no_jogador_t *lista_jogador);
bool tem_data_venda(no_jogador_t *lista_jogador);

#endif
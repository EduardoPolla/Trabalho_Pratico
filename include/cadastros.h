#ifndef CADASTROS_H
#define CADASTROS_H

#include <stdbool.h>
#include "types.h"

// Jogador
bool lista_vazia_jogador(lista_jogador_t *lista_jogador);
void inicializa_lista_jogador(lista_jogador_t *lista_jogador);
no_jogador_t *novo_registro_jogador();
void insere_novo_registro_jogador(no_jogador_t *novo_jogador, lista_jogador_t *lista_jogador);

// Partida
bool lista_vazia_partida(lista_partida_t *lista_partida);
void inicializa_lista_partida(lista_partida_t *lista_partida);
no_partida_t *novo_registro_partida();
void insere_novo_registro_partida(no_partida_t *novo_partida, lista_partida_t *lista_partida);

#endif
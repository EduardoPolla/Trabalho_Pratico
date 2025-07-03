#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"

// Jogadores
void mostrar_dados_jogador(no_jogador_t *lista_jogador);
void relatorio_jogadores(no_jogador_t *lista_jogador);
void relatorio_jogadores_vendidos(no_jogador_t *lista_jogador);

// Partidas
void relatorio_partidas(no_partida_t *lista_partida);
void relatorio_partidas_adversario(no_partida_t *lista_partida, string nome);

// Time 
void mostrar_dados_partida(no_partida_t *lista_partida);
void valor_time(no_jogador_t *lista_jogador);
void indice_aproveitamento(no_partida_t *lista_partida);

#endif
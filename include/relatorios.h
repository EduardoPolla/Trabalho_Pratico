#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"

// Jogadores
void mostrar_dados_jogador(no_jogador_t *lista_jogador);
void relatorio_jogadores(no_jogador_t *ptr_lista_jogador);
void relatorio_jogadores_vendidos(no_jogador_t *ptr_lista_jogador);

// Partidas
void relatorio_partidas(no_partida_t *ptr_lista_partida);
void relatorio_partidas_adversatio(no_partida_t *ptr_lista_partida);

// Time 
void mostrar_dados_partida(no_partida_t *lista_partida);
void valor_time(no_jogador_t *ptr_lista_jogador);
void indice_aproveitamento(no_partida_t *ptr_lista_partida);

#endif
#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_jogadores_bin(no_jogador_t *lista_jogador, string nome_arq);
void carregar_jogadores_bin(no_jogador_t **lista_jogador, string nome_arq);
void salvar_partidas_bin(no_partida_t *lista_partida, string nome_arq);
void carregar_partidas_bin(no_partida_t **lista_partida, string nome_arq);

#endif
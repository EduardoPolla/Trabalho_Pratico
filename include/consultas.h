#ifndef CONSULTAS_H
#define CONSULTAS_H
    
#include "types.h"

void localizar_jogadores_nome(no_jogador_t *lista_jogador, string nome_jogador);
void localizar_jogadores_posicao(no_jogador_t *lista_jogador, string posicao);
void localizar_jogador_idade(no_jogador_t *lista_jogador, int de, int ate);
void localizar_jogador_salario(no_jogador_t *lista_jogador, float de, float ate);
void localizar_jogador_maior_salario(no_jogador_t *lista_jogador);

#endif
#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"
#include <stdio.h>

// Arquivos .bin
void salvar_jogadores_bin(no_jogador_t *lista_jogador, string nome_arq);
void carregar_jogadores_bin(no_jogador_t **lista_jogador, string nome_arq);
void salvar_partidas_bin(no_partida_t *lista_partida, string nome_arq);
void carregar_partidas_bin(no_partida_t **lista_partida, string nome_arq);

// Arquivos .csv
void abrir_arquivo_csv(string nome_arq);
void mostrar_dados_jogador_csv(no_jogador_t *lista_jogador, FILE *fp);
void mostrar_dados_lista_csv(no_partida_t *lista_partida, FILE *fp);
void exportar_dados_jogador_csv(no_jogador_t *lista_jogador, string nome_arq);
void exportar_dados_partida_csv(no_partida_t *lista_partida, string nome_arq);
void exportar_dados_vendidos_csv(no_jogador_t *lista_jogador, string nome_arq);
void exportar_adversario_csv(no_partida_t *lista_partida, string nome_adv, string nome_arq);
void exportar_info_time_csv(no_partida_t *lista_partida, no_jogador_t *lista_jogador, string nome_arq);

// Arquivos .txt
void mostrar_dados_jogador_txt(no_jogador_t *lista_jogador, FILE *fp);
void mostrar_dados_partida_txt(no_partida_t *lista_partida, FILE *fp);
void exportar_dados_jogador_txt(no_jogador_t *lista_jogador, string nome_arq);
void exportar_dados_partida_txt(no_partida_t *lista_partida, string nome_arq);
void exportar_dados_vendidos_txt(no_jogador_t *lista_jogador, string nome_arq);
void exportar_adversario_txt(no_partida_t *lista_partida, string nome_adv, string nome_arq);
void exportar_info_time_txt(no_partida_t *lista_partida, no_jogador_t *lista_jogador, string nome_arq);

// Arquivos .html
void exportar_dados_jogador_html(no_jogador_t *lista_jogador, string nome_arq);
void exportar_dados_partida_html(no_partida_t *lista_partida, string nome_arq);

#endif
#include "../include/consultas.h"
#include "../include/relatorios.h"
#include "../include/cadastros.h"
#include <string.h>
#include <stdio.h>

void localizar_jogadores_nome(no_jogador_t *lista_jogador, string nome_jogador)
{
    string nome_temp;
    char *token;

    if(lista_vazia_jogador(lista_jogador)) {
        printf("Nenhum jogador cadastrado!\n");
        return;
    }

    while(lista_jogador) {
        strcpy(nome_temp, lista_jogador->dados.nome_jogador);

        token = strtok(nome_temp, " ");

        while(token) {
            if(strcmp(nome_jogador, token) == 0) {
                mostrar_dados_jogador(lista_jogador);
            }

            token = strtok(NULL, " ");
        }

        lista_jogador = lista_jogador->proximo;
    }
}

void localizar_jogadores_posicao(no_jogador_t *lista_jogador, string posicao)
{
    string pos_temp;
    char *token;

    if(lista_vazia_jogador(lista_jogador)) {
        printf("Nenhum jogador cadastrado!\n");
        return;
    }

    while(lista_jogador) {
        strcpy(pos_temp, lista_jogador->dados.posicao);

        token = strtok(pos_temp, ",");

        while(token) {
            if(strcmp(posicao, token) == 0) {
                mostrar_dados_jogador(lista_jogador);
            }

            token = strtok(NULL, ",");
        }

        lista_jogador = lista_jogador->proximo;
    }
}

void localizar_jogador_idade(no_jogador_t *lista_jogador, int de, int ate)
{

}

void localizar_jogador_salario(no_jogador_t *lista_jogador, float de, float ate)
{

}

void localizar_jogador_maior_salario(no_jogador_t *lista_jogador)
{

}

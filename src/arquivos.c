#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include <stdio.h>
#include <stdlib.h>

void salvar_jogadores_bin(no_jogador_t *lista_jogador, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "wb");

    if(!fp) {
        printf("Erro ao criar arquvio %s!\n", nome_arq);
        return;
    }

    while(lista_jogador) {
        fwrite(lista_jogador, sizeof(no_jogador_t), 1, fp);
        lista_jogador = lista_jogador->proximo;
    }

    fclose(fp);
}

void carregar_jogadores_bin(no_jogador_t *lista_jogador, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("Erro ao abrir arquivo %s\n", nome_arq);
        return;
    }

    while(!feof(fp)) {
        no_jogador_t *aux = (no_jogador_t*)malloc(sizeof(no_jogador_t));
        fread(aux, sizeof(no_jogador_t), 1, fp);
        if(!feof(fp)) {
            aux->proximo = NULL;
            insere_novo_registro_jogador(aux, &lista_jogador);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arquivos .bin
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

void carregar_jogadores_bin(no_jogador_t **lista_jogador, string nome_arq)
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
            insere_novo_registro_jogador(aux, lista_jogador);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

void salvar_partidas_bin(no_partida_t *lista_partida, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "wb");

    if(!fp) {
        printf("Erro ao criar arquvio %s!\n", nome_arq);
        return;
    }

    while(lista_partida) {
        fwrite(lista_partida, sizeof(no_partida_t), 1, fp);
        lista_partida = lista_partida->proxima;
    }

    fclose(fp);
}

void carregar_partidas_bin(no_partida_t **lista_partida, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("Erro ao abrir arquivo %s\n", nome_arq);
        return;
    }

    while(!feof(fp)) {
        no_partida_t *aux = (no_partida_t*)malloc(sizeof(no_partida_t));
        fread(aux, sizeof(no_partida_t), 1, fp);
        if(!feof(fp)) {
            aux->proxima = NULL;
            insere_novo_registro_partida(aux, lista_partida);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

// Arquivos .csv
void mostrar_dados_jogador_csv(no_jogador_t *lista_jogador, FILE *fp) 
{
    fprintf(fp, "%s;", lista_jogador->dados.nome_jogador);
    fprintf(fp, "\"%s\";", lista_jogador->dados.posicao);
    fprintf(fp, "%i;", lista_jogador->dados.idade);
    fprintf(fp, "%.2f;", lista_jogador->dados.altura);
    fprintf(fp, "%.2f;", lista_jogador->dados.peso);
    fprintf(fp, "%.2f;", lista_jogador->dados.valor_passe);
    fprintf(fp, "%.2f;", lista_jogador->dados.valor_aquisicao);
    fprintf(fp, "%.2f;", lista_jogador->dados.salario);
    fprintf(fp, "%d/%d/%d;", lista_jogador->dados.admissao.dia, lista_jogador->dados.admissao.mes, lista_jogador->dados.admissao.ano);
    fprintf(fp, "%d/%d/%d;", lista_jogador->dados.venda.dia, lista_jogador->dados.venda.mes, lista_jogador->dados.venda.ano);
    fprintf(fp, "%s;", lista_jogador->dados.atividade);
    if(strcmp(lista_jogador->dados.atividade, "INATIVO") == 0) {
        fprintf(fp, "%s\n", lista_jogador->dados.razao_inatividade);
    }
    else {
        fprintf(fp, "\n");
    }
}

void mostrar_dados_partida_csv(no_partida_t *lista_partida, FILE *fp) 
{
    fprintf(fp, "%s;", lista_partida->dados.nome_adversario);
    fprintf(fp, "%s;", lista_partida->dados.local_partida);
    fprintf(fp, "%d/%d/%d;", lista_partida->dados.data_partida.dia, lista_partida->dados.data_partida.mes, lista_partida->dados.data_partida.ano);
    fprintf(fp, "%s;", lista_partida->dados.resultado_partida);
    for(int i = 0; i <= 11; i++) {
        if(i < 11) {
            fprintf(fp, "%s, ", lista_partida->dados.escalacao[i]);
        }
        else {
            fprintf(fp, "%s;", lista_partida->dados.escalacao[i]);
        }
    }
    fprintf(fp, "%i\n", lista_partida->dados.qtd_substituicoes);
}

void exportar_dados_jogador_csv(no_jogador_t *lista_jogador, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");

    if(lista_vazia_jogador(lista_jogador)) {
        printf("Nenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    if (!fp) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }
    
    fprintf(fp, "NOME;POSIÇÃO;IDADE;ALTURA;PESO;VALOR VENDA;VALOR COMPRA;SALÁRIO;DATA ADMISSAO;DATA VENDA;ATIVIDADE;RAZÃO INATIVIDADE\n");

    while(lista_jogador) {
        mostrar_dados_jogador_csv(lista_jogador, fp);
        lista_jogador = lista_jogador->proximo;
    }    

    fclose(fp); 
}

void exportar_dados_partida_csv(no_partida_t *lista_partida, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");

    if(lista_vazia_partida(lista_partida)) {
        printf("Nenhuma partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    if (!fp) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }
    
    fprintf(fp, "NOME ADVERSÁRIO;LOCAL;DATA;RESULTADO;ESCALAÇÃO;N° SUBSTITUIÇÕES\n");

    while(lista_partida) {
        mostrar_dados_partida_csv(lista_partida, fp);
        lista_partida = lista_partida->proxima;
    }    

    fclose(fp); 
}

void exportar_dados_vendidos_csv(no_jogador_t *lista_jogador, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");

    if(lista_vazia_jogador(lista_jogador)) {
        printf("Nenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    if (!fp) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp, "NOME;POSIÇÃO;IDADE;ALTURA;PESO;VALOR VENDA;VALOR COMPRA;SALÁRIO;DATA ADMISSAO;DATA VENDA;ATIVIDADE;RAZÃO INATIVIDADE\n");

    while(lista_jogador) {
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") == 0) {
            mostrar_dados_jogador_csv(lista_jogador, fp);
        }
        lista_jogador = lista_jogador->proximo;
    }    

    fclose(fp);
}

void exportar_adversario_csv(no_partida_t *lista_partida, string nome_adv, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "w");

    if(lista_vazia_partida(lista_partida)) {
        printf("Nenhum partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    if (!fp) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp, "NOME ADVERSÁRIO;LOCAL;DATA;RESULTADO;ESCALAÇÃO;N° SUBSTITUIÇÕES\n");

    while(lista_partida) {
        if(strcmp(lista_partida->dados.nome_adversario, nome_adv) == 0) {
            mostrar_dados_partida_csv(lista_partida, fp);
        }
        lista_partida = lista_partida->proxima;
    }    

    fclose(fp);
}

void exportar_info_time(no_partida_t *lista_partida, no_jogador_t *lista_jogador, string nome_arq)
{
    int vitoria = 0, empate = 0, derrota = 0;
    int nmr_partidas = 0;
    float soma = 0;
    FILE *fp = fopen(nome_arq, "w");

    if(lista_vazia_partida(lista_partida) && lista_vazia_jogador(lista_jogador)) {
        printf("Não foi possível gerar o arquivo!\n");
        msg_press_enter();
        return;
    }

    if (!fp) {
        printf("Erro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    while(lista_partida) {
        if(strcmp(lista_partida->dados.resultado_partida, "VITORIA") == 0) {
            vitoria++;
        }
        if(strcmp(lista_partida->dados.resultado_partida, "EMPATE") == 0) {
            empate++;
            nmr_partidas--;
        }
        if(strcmp(lista_partida->dados.resultado_partida, "DERROTA") == 0) {
            derrota++;
        }
        
        nmr_partidas++;
        lista_partida = lista_partida->proxima;
    }

    while(lista_jogador) {
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") != 0) {
            soma += lista_jogador->dados.valor_passe;
        }
        lista_jogador = lista_jogador->proximo;
    }

    fprintf(fp, "N° VITÓRIAS;N° EMPATES;N° DERROTAS;ÍNDICE DE APROVEITAMENTO;VALOR TIME\n");
    fprintf(fp, "%i;", vitoria);
    fprintf(fp, "%i;", empate);
    fprintf(fp, "%i;", derrota);
    fprintf(fp, "%.2f;", ((float)vitoria / nmr_partidas) * 100);
    fprintf(fp, "%.2f", soma);

    fclose(fp);
}

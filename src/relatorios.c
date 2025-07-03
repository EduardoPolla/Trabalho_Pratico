#include "../include/relatorios.h"
#include "../include/cadastros.h"
#include "../include/utils.h"

// Jogadores

void mostrar_dados_jogador(no_jogador_t *lista_jogador)
{
    printf("\n=======================================================================\n");
    printf("Nome do jogador................: %s\n", lista_jogador->dados.nome_jogador);
    printf("Posições do jogador............: %s\n", lista_jogador->dados.posicao);
    printf("Idade do jogador...............: %i\n", lista_jogador->dados.idade);
    printf("Altura do jogador..............: %.2f\n", lista_jogador->dados.altura);
    printf("Peso do jogador................: %.2f\n", lista_jogador->dados.peso);
    printf("Valor de passe do jogador......: %.2f\n", lista_jogador->dados.valor_passe);
    printf("Valor de aquisição do jogador..: %.2f\n", lista_jogador->dados.valor_aquisicao);
    printf("Salário do jogador.............: %.2f\n", lista_jogador->dados.salario);
    printf("Data de admissão do jogador....: %i/%i/%i\n", lista_jogador->dados.admissao.dia, lista_jogador->dados.admissao.mes, lista_jogador->dados.admissao.ano);
    if(lista_jogador->dados.venda.mes != 0) {
        printf("Data de venda do jogador.......: %i/%i/%i\n", lista_jogador->dados.venda.dia, lista_jogador->dados.venda.mes, lista_jogador->dados.venda.ano);
    }
    printf("Status do jogador..............: %s\n", lista_jogador->dados.atividade);
    if(strcmp(lista_jogador->dados.atividade, "ATIVO") != 0) {
        printf("Razão da inatividade...........: %s\n", lista_jogador->dados.razao_inatividade);
    }
    printf("=======================================================================\n");
}

void relatorio_jogadores(no_jogador_t *lista_jogador)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("Nenhum jogador cadastrado!\n");
        return;
    }
        

    while(lista_jogador) {
        mostrar_dados_jogador(lista_jogador);
        lista_jogador = lista_jogador->proximo;
    }
}

void relatorio_jogadores_vendidos(no_jogador_t *lista_jogador)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("Nenhum jogador cadastrado!\n"); 
        return;
    }

    while(lista_jogador) {
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") == 0) {
            mostrar_dados_jogador(lista_jogador);
        }
        lista_jogador = lista_jogador->proximo;
    }
}


// Partidas

void mostrar_dados_partida(no_partida_t *lista_partida)
{
    int i;

    printf("\n=======================================================================\n");
    printf("Nome adversário................: %s\n", lista_partida->dados.nome_adversario);
    printf("Local da partida...............: %s\n", lista_partida->dados.local_partida);
    printf("Resultado da partida...........: %s\n", lista_partida->dados.resultado_partida);
    printf("Data da partida................: %i/%i/%i\n", lista_partida->dados.data_partida.dia, lista_partida->dados.data_partida.mes, lista_partida->dados.data_partida.ano);
    printf("Escalação......................: ");
    for(int i = 0; i < 10; i++) {
        printf("Jogador %i - %s, ", i, lista_partida->dados.escalacao[i]);
    }
    printf("Jogador %i - %s\n", ++i, lista_partida->dados.escalacao[i]);
    printf("Quantidade de substituições....: %i\n", lista_partida->dados.qtd_substituicoes);
    printf("=======================================================================\n");
}

void relatorio_partidas(no_partida_t *lista_partida)
{
    if(lista_vazia_partida(lista_partida)) {
        printf("Nenhuma partida cadastrada!\n"); 
        return;
    }

    while(lista_partida) {
        mostrar_dados_partida(lista_partida);
        lista_partida = lista_partida->proxima;
    }
}

void relatorio_partidas_adversatio(no_partida_t *lista_partida)
{

}


// Time 
void valor_time(no_jogador_t *lista_jogador)
{

}

void indice_aproveitamento(no_partida_t *lista_partida)
{

}
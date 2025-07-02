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
    printf("Altura do jogador..............: %f\n", lista_jogador->dados.altura);
    printf("Peso do jogador................: %f\n", lista_jogador->dados.peso);
    printf("Valor de passe do jogador......: %f\n", lista_jogador->dados.valor_passe);
    printf("Valor de aquisição do jogador..: %f\n", lista_jogador->dados.valor_aquisicao);
    printf("Salário do jogador.............: %f\n", lista_jogador->dados.salario);
    printf("Data de admissão do jogador....: %i/%i/%i\n", lista_jogador->dados.admissao.dia, lista_jogador->dados.admissao.mes, lista_jogador->dados.admissao.ano);
    if(lista_jogador->dados.venda.mes != 0) {
        printf("Data de venda do jogador.......: %i/%i/%i\n", lista_jogador->dados.venda.dia, lista_jogador->dados.venda.mes, lista_jogador->dados.venda.ano);
    }
    printf("Status do jogador..............: %s\n", lista_jogador->dados.atividade);
    if(strcmp(lista_jogador->dados.atividade, "ATIVO") != 0) {
        printf("Razão da inatividade...........: %s", lista_jogador->dados.razao_inatividade);
    }
    printf("\n=======================================================================\n");
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

}

void relatorio_partidas(no_partida_t *lista_partida)
{

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
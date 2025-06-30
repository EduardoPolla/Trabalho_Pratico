#include <stdlib.h>
#include "../include/cadastro.h"
#include <utils.h>

// Jogador
bool lista_vazia_jogador(lista_jogador_t *lista_jogador)
{
    if(!lista_jogador) return true; // Está vazia
    
    return false; // Não está vazia
}
void inicializa_lista_jogador(lista_jogador_t *lista_jogador)
{
    lista_jogador_t->cabeca = NULL;
}

no_jogador_t *novo_registro_jogador()
{
    no_t novo = (no_t*)malloc(sizeof(no_t));

    if(!novo) return NULL;

    // Nome
    printf("Nome do jogador................: ");
    fgets(novo->dados.nome_jogador, TAMANHO, stdin);
    retirar_enter(novo->dados.nome_jogador);
    formatar_maiusculas(novo->dados.nome_jogador);

    // Posição
    printf("Posições do jogador............: ");
    fgets(novo->dados.posicao, TAMANHO, stdin);
    retirar_enter(novo->dados.posicao);
    formatar_maiusculas(novo->dados.posicao);

    // Idade
    printf("Idade do jogador...............: ");
    scanf("%i", &novo->dados.idade);

    // Altura
    printf(" Altura do jogador.............: ");
    scanf("%f", &novo->dados.altura);

    // Peso
    printf(" o peso do jogador.............: ");
    scanf("%f", &novo->dados.peso);

    // Valor Passe
    printf("Valor de passe do jogador......: ");
    scanf("%f", &novo->dados.valor_passe);

    // Valor Aquisição
    printf("Valor de aquisição do jogador..: ");
    scanf("%f", &novo->dados.valor_aquisicao);

    // Salário
    printf("Salário do jogador.............: ");
    scanf("%f", &novo->dados.salario);

    //Data Admissão
    printf("Data de admissão...............: ");
    scanf("%i/%i/%i", &novo->dados.dia, &novo->dados.mes, &novo->dados.ano);

    // Atividade 
    novo->dados.atividade = ATIVO;

    // Inicializa Próximo
    novo->proximo = NULL;

    return novo;
}

void insere_novo_registro_jogador(no_jogador_t *novo_jogador, lista_jogador_t lista_jogador)
{

}

// Partida
bool lista_vazia_jogador(lista_partida_t *lista_partida)
{

}

void inicializa_lista_partida(lista_partida_t *lista_partida)
{

}

no_partida_t *novo_registro_partida()
{

}

void insere_novo_registro_partida(no_partida_t *novo_partida, lista_partida_t lista_partida)
{

}

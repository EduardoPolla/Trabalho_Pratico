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
    lista_jogador->cabeca = NULL;
}

no_jogador_t *novo_registro_jogador()
{
    no_jogador_t novo = (no_jogador_t*)malloc(sizeof(no_jogador_t));

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
    scanf("%i/%i/%i", &novo->dados.admissao.dia, &novo->dados.admissao.mes, &novo->dados.admissao.ano);

    // Atividade 
    novo->dados.atividade = ATIVO;

    // Inicializa Próximo
    novo->proximo = NULL;

    return novo;
}

void insere_novo_registro_jogador(no_jogador_t *novo_jogador, lista_jogador_t *lista_jogador)
{
    if(lista_vazia_jogador) {
        lista_jogador->cabeca_jogador = novo_jogador;
        return;
    }

    novo_jogador->proximo_jogador = lista_jogador->cabeca_jogador;
    lista_jogador->cabeca_jogador = novo_jogador;
}   

// Partida
bool lista_vazia_partida(lista_partida_t *lista_partida)
{
    if(!lista_partida) return true; // Está vazia

    return false; // Não está vazia
}

void inicializa_lista_partida(lista_partida_t *lista_partida)
{
    lista_partida->cabeca_partida = NULL;
}

no_partida_t *novo_registro_partida()
{
    string aux;
    no_partida_t nova = (no_jogador_t*)malloc(sizeof(no_partida_t));

    if(!nova) return NULL;

    // Nome
    printf("Nome do time adversário: ");
    fgets(nova->dados.nome_adversario, TAMANHO, stdin);
    retirar_enter(nova->dados.nome_adversario);
    formatar_maiusculas(nova->dados.nome_adversario);
    
    // Local
    printf("Local da partida: ");
    fgets(nova->dados.local_partida, TAMANHO, stdin);
    retirar_enter(nova->dados.local_partida);
    formatar_maiusculas(nova->dados.local_partida);

    // Data
    printf("Data da partida: ");
    scanf("%i/%i/%i", &nova->dados.dia, &nova->dados.mes, &nova->dados.ano);
    getchar();

    // Resultado
    printf("Resultado da partida (DERROTA, EMPATE, VITORIA): ");
    fgets(aux, TAMANHO, stdin);
    retirar_enter(aux);
    formatar_maiusculas(aux);

    switch(aux) {
        case 1: nova->dados.resultado_partida = DERROTA;
                break;

        case 2: nova->dados.resultado_partida = EMPATE;
                break;

        case 3: nova->dados.resultado_partida = VITORIA;
                break;

    }

    // Escalação

    // Quantidade Substituições
    printf("N° de substituições na partida: ");
    scanf("%i", &nova->dados.qtd_substituicoes);

    nova->proxima_partida = NULL;

    return nova;
}

void insere_novo_registro_partida(no_partida_t *nova_partida, lista_partida_t *lista_partida)
{
    if(lista_vazia_partida) {
        lista_partida->cabeca_partida = nova_partida;
        return;
    }

    nova_partida->proxima_partida = lista_partida->cabeca_partida;
    lista_partida->cabeca_partida = nova_partida;
}

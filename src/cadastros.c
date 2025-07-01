#include <stdlib.h>
#include "../include/cadastros.h"
#include "../include/utils.h"
#include <string.h>

// Jogador
bool lista_vazia_jogador(no_jogador_t *lista_jogador)
{
    if(lista_jogador) return false; // Não está vazia
    
    return true; // Está vazia 
}

no_jogador_t *novo_registro_jogador()
{
    no_jogador_t *novo = (no_jogador_t*)malloc(sizeof(no_jogador_t));

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
    getchar();

    // Altura
    printf("Altura do jogador..............: ");
    scanf("%f", &novo->dados.altura);
    getchar();

    // Peso
    printf("Peso do jogador................: ");
    scanf("%f", &novo->dados.peso);
    getchar();

    // Valor Passe
    printf("Valor de passe do jogador......: ");
    scanf("%f", &novo->dados.valor_passe);
    getchar();

    // Valor Aquisição
    printf("Valor de aquisição do jogador..: ");
    scanf("%f", &novo->dados.valor_aquisicao);
    getchar();

    // Salário
    printf("Salário do jogador.............: ");
    scanf("%f", &novo->dados.salario);
    getchar();

    //Data Admissão
    printf("Data de admissão...............: ");
    scanf("%i/%i/%i", &novo->dados.admissao.dia, &novo->dados.admissao.mes, &novo->dados.admissao.ano);
    getchar();

    // Data de Venda
    novo->dados.venda.dia = 0;
    novo->dados.venda.mes = 0;
    novo->dados.venda.ano = 0;

    // Atividade 
    strcpy(novo->dados.atividade, "ATIVO");

    // Inicializa Próximo
    novo->proximo = NULL;

    return novo;
}

void insere_novo_registro_jogador(no_jogador_t *novo_jogador, no_jogador_t **lista_jogador)
{
    if(lista_vazia_jogador(*lista_jogador)) {
        *lista_jogador = novo_jogador;
        return;
    }

    novo_jogador->proximo = *lista_jogador;
    *lista_jogador = novo_jogador;
}   

// Partida
bool lista_vazia_partida(no_partida_t *lista_partida)
{
    if(!lista_partida) return true; // Está vazia

    return false; // Não está vazia
}

no_partida_t *novo_registro_partida(no_jogador_t *lista_jogador)
{
    if(!lista_jogador) printf("Não há jogadores para escalação no banco de dados!\n"); return NULL;

    no_partida_t *nova = (no_partida_t*)malloc(sizeof(no_partida_t));
    int numero_jogador, i;

    if(!nova) return NULL;

    // Nome
    printf("Nome do time adversário........: ");
    fgets(nova->dados.nome_adversario, TAMANHO, stdin);
    retirar_enter(nova->dados.nome_adversario);
    formatar_maiusculas(nova->dados.nome_adversario);
    
    // Local
    printf("Local da partida...............: ");
    fgets(nova->dados.local_partida, TAMANHO, stdin);
    retirar_enter(nova->dados.local_partida);
    formatar_maiusculas(nova->dados.local_partida);

    // Data
    printf("Data da partida................: ");
    scanf("%i/%i/%i", &nova->dados.data_partida.dia, &nova->dados.data_partida.mes, &nova->dados.data_partida.ano);
    getchar();

    // Resultado
    printf("Resultado da partida (DERROTA, EMPATE ou VITORIA): ");
    fgets(nova->dados.resultado_partida, TAMANHO, stdin);
    retirar_enter(nova->dados.resultado_partida);
    formatar_maiusculas(nova->dados.resultado_partida);

    // Escalação
    printf("Jogadores disponíveis para escalação na partida: ");

    for(aux = lista_jogador; aux != NULL; aux = aux->proximo) {
        if()
            printf("Jogador[%i]: %s\n", lista_jogador->dados.nome_jogador);
    }

    // Quantidade Substituições
    printf("N° de substituições na partida.: ");
    scanf("%i", &nova->dados.qtd_substituicoes);
    getchar();

    nova->proxima = NULL;

    return nova;
}

void insere_novo_registro_partida(no_partida_t *nova_partida, no_partida_t **lista_partida)
{
    if(lista_vazia_partida(*lista_partida)) {
        *lista_partida = nova_partida;
        return;
    }

    nova_partida->proxima = *lista_partida;
    *lista_partida = nova_partida;
}

bool jogador_data_partida_iguais(no_jogador_t lista_jogador, no_partida_t lista_partida)
{
    int i = 0;

    if(lista_jogador->dados.dia  )
}
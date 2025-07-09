#include <stdlib.h>
#include "../include/cadastros.h"
#include "../include/utils.h"
#include <string.h>

// Comparador de Datas para Escalação Partida
int comparar_datas(data_t d_jogador, data_t d_partida)
{
    if(d_jogador.ano < d_partida.ano) return -1;
    if(d_jogador.ano > d_partida.ano) return 1; 
    if(d_jogador.mes < d_partida.mes) return -1;
    if(d_jogador.mes > d_partida.mes) return 1;
    if(d_jogador.dia < d_partida.dia) return -1;
    if(d_jogador.dia > d_partida.dia) return 1;

    return 0;
}

// Verifica se tem data de venda
bool tem_data_venda(no_jogador_t *lista_jogador) {
    if(lista_jogador->dados.venda.dia == 0 && lista_jogador->dados.venda.mes == 0 && lista_jogador->dados.venda.ano == 0) {
        return false;
    }

    return true;
}

bool jogador_ativo_data(data_t data_partida, no_jogador_t *lista_jogador)
{
    //Verifica se o jogador foi contratado antes da data da partida
    if(comparar_datas(lista_jogador->dados.admissao, data_partida) > 0) {
        return false;
    }

    // Se tiver data de venda, verifica se partida foi antes da venda
    if(tem_data_venda(lista_jogador) && comparar_datas(lista_jogador->dados.venda, data_partida) < 0) {
        return false; // Partida ocorreu depois da venda
    }

    return true; // Jogador está elegível a participar da escalação
}

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
    printf("\nNome do jogador................: ");
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

void inativar_jogador(no_jogador_t **lista_jogador, string nome)
{
    int opcao;

    if(lista_vazia_jogador(*lista_jogador)) {
        printf("\nNehum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    while(*lista_jogador) {
        if(strcmp((*lista_jogador)->dados.nome_jogador, nome) == 0) {
            printf("\nDeseja vender(1) ou inativar o jogador por recuperação médica(2): ");
            scanf("%i", &opcao);
            getchar();

            switch(opcao) {
                case 1: printf("Data de venda: ");
                        scanf("%i/%i/%i", &((*lista_jogador)->dados.venda.dia), &((*lista_jogador)->dados.venda.mes), &((*lista_jogador)->dados.venda.ano));
                        getchar();
                        strcpy((*lista_jogador)->dados.atividade, "INATIVO");
                        strcpy((*lista_jogador)->dados.razao_inatividade, "VENDIDO");
                        (*lista_jogador)->dados.salario = 0; 
                        break;

                case 2: strcpy((*lista_jogador)->dados.atividade, "INATIVO");
                        strcpy((*lista_jogador)->dados.razao_inatividade, "RECUPERAÇÃO MÉDICA");
                        break;

                default: printf("\nOpção inválida!\n");
                         msg_press_enter();
                         break;
            }
        }

        lista_jogador = &((*lista_jogador)->proximo);
    }
}

void reativar_jogador(no_jogador_t **lista_jogador, string nome)
{
    if(lista_vazia_jogador(*lista_jogador)) {
        printf("\nNehum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    while(*lista_jogador) {
        if(strcmp((*lista_jogador)->dados.nome_jogador, nome) == 0 && strcmp((*lista_jogador)->dados.razao_inatividade, "VENDIDO") != 0) {
            strcpy((*lista_jogador)->dados.atividade, "ATIVO");
            strcpy((*lista_jogador)->dados.razao_inatividade, ""); 
        }
        lista_jogador = &((*lista_jogador)->proximo);
    }
}

// Partida

bool lista_vazia_partida(no_partida_t *lista_partida)
{
    if(!lista_partida) return true; // Está vazia

    return false; // Não está vazia
}

no_partida_t *novo_registro_partida(no_jogador_t *lista_jogador)
{
    if(!lista_jogador) {
        printf("\nNão há jogadores para escalação no banco de dados!\n");
        msg_press_enter();
        return NULL;
    }

    no_partida_t *nova = (no_partida_t*)malloc(sizeof(no_partida_t));
    no_jogador_t *aux, *jogadores_elegiveis[TAMANHO];
    int qtd_elegiveis = 0, numero_jogador, i = 0;

    if(!nova) return NULL;

    // Nome
    printf("\nNome do time adversário........: ");
    fgets(nova->dados.nome_adversario, TAMANHO, stdin);
    retirar_enter(nova->dados.nome_adversario);
    formatar_maiusculas(nova->dados.nome_adversario);
    
    // Local
    printf("Local da partida...............: ");
    fgets(nova->dados.local_partida, TAMANHO, stdin);
    retirar_enter(nova->dados.local_partida);
    formatar_maiusculas(nova->dados.local_partida);

    // Resultado
    printf("Resultado da partida (DERROTA, EMPATE ou VITORIA): ");
    fgets(nova->dados.resultado_partida, TAMANHO, stdin);
    retirar_enter(nova->dados.resultado_partida);
    formatar_maiusculas(nova->dados.resultado_partida);

    // Data
    printf("Data da partida................: ");
    scanf("%i/%i/%i", &nova->dados.data_partida.dia, &nova->dados.data_partida.mes, &nova->dados.data_partida.ano);
    getchar();

    // Escalação
    for(aux = lista_jogador; aux != NULL; aux = aux->proximo) {
        if(jogador_ativo_data(nova->dados.data_partida, aux)) {
            jogadores_elegiveis[qtd_elegiveis] = aux;
            qtd_elegiveis++;
        }
    }

    if(qtd_elegiveis < 11) {
        printf("\nQuantidade de jogadores insuficientes para a data %i/%i/%i\n", nova->dados.data_partida.dia, nova->dados.data_partida.mes, nova->dados.data_partida.ano);
        free(nova);
        msg_press_enter();
        return NULL;
    }
    
    else {
        printf("Jogadores disponíveis para a data %i/%i/%i: \n\n", nova->dados.data_partida.dia, nova->dados.data_partida.mes, nova->dados.data_partida.ano);
        for(int i = 0; i < qtd_elegiveis; i++) {
            printf("%i - %s\n", i + 1, jogadores_elegiveis[i]->dados.nome_jogador);
        }

        printf("\n");

        for(int i = 0; i < 11; i++) {
            printf("Digite o número do jogador desejado para a posição %i: ", i + 1);
            scanf("%i", &numero_jogador);
            getchar();

            strcpy(nova->dados.escalacao[i], jogadores_elegiveis[numero_jogador - 1]->dados.nome_jogador);
        }
    }

    // Quantidade Substituições
    printf("\nN° de substituições na partida.: ");
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

    if(lista_vazia_partida(nova_partida)) {
        printf("\nErro ao inserir no banco de dados!\n");
        msg_press_enter();
        return;
    }

    nova_partida->proxima = *lista_partida;
    *lista_partida = nova_partida;
}
#include <stdio.h>
#include "../include/menus.h"
#include "../include/utils.h"


int menu_principal()
{
    int opcao;

    limpar_tela();

    printf("| MENU PRINCIPAL |\n");
    printf("------------------\n");
    printf("1. Cadastrar\n");
    printf("2. Relatórios\n");
    printf("3. Consultas\n");
    printf("0. Fechar programa\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &opcao);

    return opcao;
}

int menu_cadastros()
{
    int opcao;

    limpar_tela();

    printf("| MENU CADASTRO |\n");
    printf("-----------------\n");
    printf("1. Cadastrar jogador\n");
    printf("2. Cadastrar partida\n");
    printf("0. Voltar ao MENU PRINCIPAL\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &opcao);

    return opcao;
}

int menu_relatorios()
{
    int opcao;

    limpar_tela();

    printf("| MENU RELATÓRIOS |\n");
    printf("-------------------\n");
    printf("1. Relatório de jogadores\n");
    printf("2. Relatório de jogadores vendidos\n");
    printf("3. Relatório de partidas\n");
    printf("4. Relatório de partidas contra time adversário\n");
    printf("5. Valor do time\n");
    printf("6. Indíce de aproveitamento do time\n");
    printf("0. Voltar ao MENU PRINCIPAL\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &opcao);

    return opcao;
}

int menu_consultas()
{
int opcao;

    limpar_tela();

    printf("| MENU CONSULTAS |\n");
    printf("------------------\n");
    printf("1. Localizar jogador(es) por nome\n");
    printf("2. Localizar jogador(es) por posição\n");
    printf("3. Localizar jogador(es) por faixa etária\n");
    printf("4. Localizar jogador(es) por faixa salarial\n");
    printf("5. Localizar jogador com maior salário\n");
    printf("0. Voltar ao MENU PRINCIPAL\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &opcao);

    return opcao;
}
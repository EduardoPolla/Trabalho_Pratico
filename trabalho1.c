#include <stdio.h>
#include <string.h>
#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/utils.h"
#include "./include/relatorios.h"
#include "./include/arquivos.h"
#include "./include/consultas.h"

#define ENCERRAR 0

int main()
{
    //Menu
    int opcao, sub_opcao;

    // Jogadores 
    no_jogador_t *lista_jogador = NULL;

    // Partida
    no_partida_t *lista_partida = NULL;

    // Auxiliares
    string nome_adv;
    string nome_jogador;
    string posicao;

    int de_idade, ate_idade;

    float de_sal, ate_sal;

    // Carrega Jogadores de Arquivo .bin
    carregar_jogadores_bin(&lista_jogador, "jogadores.bin");

    // Carrega Partidas de Arquivo .bin
    carregar_partidas_bin(&lista_partida, "partidas.bin");

    do {
        opcao = menu_principal();

        switch(opcao) {
            
            case 1: do {
                        sub_opcao = menu_cadastros();

                        switch(sub_opcao) {

                            case 1: insere_novo_registro_jogador(novo_registro_jogador(), &lista_jogador);
                                    break;

                            case 2: insere_novo_registro_partida(novo_registro_partida(lista_jogador), &lista_partida);
                                    if(lista_vazia_jogador(lista_jogador)) {
                                        msg_press_enter();
                                    }
                                    break;
                                    
                                case 3: printf("Digite o nome do jogador: ");
                                        fgets(nome_jogador, TAMANHO, stdin);
                                        retirar_enter(nome_jogador);
                                        formatar_maiusculas(nome_jogador);
                                        inativar_jogador(&lista_jogador, nome_jogador);
                                        break;
        

                            default: msg_usuario("Opção inválida! Tente novamente!");
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 2: do {
                        sub_opcao = menu_relatorios();

                        switch(sub_opcao) {

                            case 1: relatorio_jogadores(lista_jogador);
                                    msg_press_enter();
                                    break;

                            case 2: relatorio_jogadores_vendidos(lista_jogador);
                                    msg_press_enter();
                                    break;

                            case 3: relatorio_partidas(lista_partida);
                                    msg_press_enter();
                                    break;

                            case 4: printf("Digite o nome do time adversário: ");
                                    fgets(nome_adv, TAMANHO, stdin);
                                    retirar_enter(nome_adv);
                                    formatar_maiusculas(nome_adv);
                                    relatorio_partidas_adversario(lista_partida, nome_adv);
                                    msg_press_enter();
                                    break;

                            case 5: valor_time(lista_jogador);
                                    msg_press_enter();
                                    break;

                            case 6: indice_aproveitamento(lista_partida);
                                    msg_press_enter();
                                    break;

                            case 0: limpar_tela();
                            break;

                            default: msg_usuario("Opção inválida! Tente novamente!");
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 3: do {
                        sub_opcao = menu_consultas();

                        switch(sub_opcao) {

                            case 1: printf("Nome para efetuar a busca: ");
                                    fgets(nome_jogador, TAMANHO, stdin);
                                    retirar_enter(nome_jogador);
                                    formatar_maiusculas(nome_jogador);
                                    localizar_jogadores_nome(lista_jogador, nome_jogador);
                                    msg_press_enter();
                                    break;

                            case 2: printf("Posição para efetuar a busca: ");
                                    fgets(posicao, TAMANHO, stdin);
                                    retirar_enter(posicao);
                                    formatar_maiusculas(posicao);
                                    localizar_jogadores_posicao(lista_jogador, posicao);
                                    msg_press_enter();
                                    break;

                            case 3: printf("Digite a idade mínima: ");
                                    scanf("%i", &de_idade);
                                    getchar();
                                    printf("Digite a idade máxima: ");
                                    scanf("%i", &ate_idade);
                                    getchar();
                                    localizar_jogador_idade(lista_jogador, de_idade, ate_idade);
                                    msg_press_enter();
                                    break;

                            case 4: printf("Digite o salário mínimo: ");
                                    scanf("%f", &de_sal);
                                    getchar();
                                    printf("Digite o salário máximo: ");
                                    scanf("%f", &ate_sal);
                                    getchar();
                                    localizar_jogador_salario(lista_jogador, de_sal, ate_sal);
                                    msg_press_enter();
                                    break;

                            case 5: localizar_jogador_maior_salario(lista_jogador);
                                    msg_press_enter();
                                    break;

                            case 0: limpar_tela();
                            break;

                            default: msg_usuario("Opção inválida! Tente novamente!");
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 0: limpar_tela();
                    break;

            default: msg_usuario("Opção inválida! Tente novamente!");
        }

    } while(opcao != ENCERRAR);

    // Salva Jogadores em Arquivo .bin
    if(!lista_vazia_jogador(lista_jogador)) {
        salvar_jogadores_bin(lista_jogador, "jogadores.bin");
    }

    // Salva Partidas em Arquivo .bin
    if(!lista_vazia_partida(lista_partida)) {
        salvar_partidas_bin(lista_partida, "partidas.bin");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/utils.h"
#include "./include/relatorios.h"
#include "./include/arquivos.h"

#define ENCERRAR 0

int main()
{
    //Menu
    int opcao, sub_opcao;

    // Jogadores 
    no_jogador_t *lista_jogador = NULL;

    // Partida
    no_partida_t *lista_partida = NULL;

    // Carrega Jogadores de Arquivo .bin
    carregar_jogadores_bin(lista_jogador, "jogadores.bin");

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

                            case 0: limpar_tela();
                            break;

                            default: msg_usuario("Opção inválida! Tente novamente!");
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 3: do {
                        sub_opcao = menu_consultas();

                        switch(sub_opcao) {

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

    return 0;
}
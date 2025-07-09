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
    int opcao, sub_opcao, opcao_saida;

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

	// Apagar Lista Jogadores
	no_jogador_t *aux_jog;

	// Apagar Lista Partidas
	no_partida_t *aux_part;

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
                                    
                            case 3: printf("\nDigite o nome do jogador: ");
                                    fgets(nome_jogador, TAMANHO, stdin);
                                    retirar_enter(nome_jogador);
                                    formatar_maiusculas(nome_jogador);
                                    inativar_jogador(&lista_jogador, nome_jogador);
                                    break;
                            
                            case 4: printf("\nDigite o nome do jogador: ");
                                    fgets(nome_jogador, TAMANHO, stdin);
                                    retirar_enter(nome_jogador);
                                    formatar_maiusculas(nome_jogador);
                                    reativar_jogador(&lista_jogador, nome_jogador);
                                    break;

                            case 0: limpar_tela();
                                    break;
        
                            default: msg_usuario("\nOpção inválida! Tente novamente!");
                                     msg_press_enter();
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 2: do {
                        opcao_saida = tipo_saida();

                        switch(opcao_saida) {
							case 1: do {
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

											case 4: printf("\nDigite o nome do time adversário: ");
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

											default: msg_usuario("\nOpção inválida! Tente novamente!");
                                                    msg_press_enter();
										}
									} while(sub_opcao != ENCERRAR);
									break;

							case 2: do {
										sub_opcao = menu_csv();

										switch(sub_opcao) {
											case 1: exportar_dados_jogador_csv(lista_jogador, "jogadores.csv");
                                                    abrir_arquivo_csv("jogadores.csv");
													break;

											case 2: exportar_dados_vendidos_csv(lista_jogador, "jogadores_vendidos.csv");
                                                    abrir_arquivo_csv("jogadores_vendidos.csv");
													break;

											case 3: exportar_dados_partida_csv(lista_partida, "partidas.csv");
													abrir_arquivo_csv("partidas.csv");
													break;

											case 4: printf("\nDigite o nome do time adversário: ");
													fgets(nome_adv, TAMANHO, stdin);
													retirar_enter(nome_adv);
													formatar_maiusculas(nome_adv);
													exportar_adversario_csv(lista_partida, nome_adv, "partidas_adversario.csv");
                                                    abrir_arquivo_csv("partidas_adversario.csv");
													break;

											case 5: exportar_info_time_csv(lista_partida, lista_jogador, "info_time.csv");
                                                    abrir_arquivo_csv("info_time.csv");
													break;

											case 0: limpar_tela();
											        break;

											default: msg_usuario("\nOpção inválida! Tente novamente!");
                                                     msg_press_enter();
										}
									} while(sub_opcao != ENCERRAR);
									break;

							case 3: do {
										sub_opcao = menu_txt();

										switch(sub_opcao) {
											case 1: exportar_dados_jogador_txt(lista_jogador, "jogadores.txt");
                                                    abrir_arquivo_csv("jogadores.txt");
													break;

											case 2: exportar_dados_vendidos_txt(lista_jogador, "jogadores_vendidos.txt");
                                                    abrir_arquivo_csv("jogadores_vendidos.txt");
													break;

											case 3: exportar_dados_partida_txt(lista_partida, "partidas.txt");
													abrir_arquivo_csv("partidas.txt");
													break;

											case 4: printf("\nDigite o nome do time adversário: ");
													fgets(nome_adv, TAMANHO, stdin);
													retirar_enter(nome_adv);
													formatar_maiusculas(nome_adv);
													exportar_adversario_txt(lista_partida, nome_adv, "partidas_adversario.txt");
                                                    abrir_arquivo_csv("partidas_adversario.txt");
													break;

											case 5: exportar_info_time_txt(lista_partida, lista_jogador, "info_time.txt");
                                                    abrir_arquivo_csv("info_time.txt");
													break;

											case 0: limpar_tela();
											        break;

											default: msg_usuario("\nOpção inválida! Tente novamente!");
                                                     msg_press_enter();
										}
									} while(sub_opcao != ENCERRAR);
									break;

							case 4: do {
										sub_opcao = menu_html();

										switch(sub_opcao) {
											case 1: exportar_dados_jogador_html(lista_jogador, "jogadores.html");
                                                    abrir_arquivo_csv("jogadores.html");
													break;

											case 2: exportar_dados_partida_html(lista_partida, "partidas.html");
                                                    abrir_arquivo_csv("partidas.html");
													break;

											case 0: limpar_tela();
											        break;

											default: msg_usuario("\nOpção inválida! Tente novamente!");
                                                     msg_press_enter();
										}
									} while(sub_opcao != ENCERRAR);
									break;

                            
                            case 0: limpar_tela();
                                    break;

							default: msg_usuario("\nOpção inválida! Tente novamente!");
                                     msg_press_enter();
                        }
                	} while(opcao_saida != ENCERRAR);
                    break;

            case 3: do {
                        sub_opcao = menu_consultas();

                        switch(sub_opcao) {

                            case 1: printf("\nNome para efetuar a busca: ");
                                    fgets(nome_jogador, TAMANHO, stdin);
                                    retirar_enter(nome_jogador);
                                    formatar_maiusculas(nome_jogador);
                                    localizar_jogadores_nome(lista_jogador, nome_jogador);
                                    msg_press_enter();
                                    break;

                            case 2: printf("\nPosição para efetuar a busca: ");
                                    fgets(posicao, TAMANHO, stdin);
                                    retirar_enter(posicao);
                                    formatar_maiusculas(posicao);
                                    localizar_jogadores_posicao(lista_jogador, posicao);
                                    msg_press_enter();
                                    break;

                            case 3: printf("\nDigite a idade mínima: ");
                                    scanf("%i", &de_idade);
                                    getchar();
                                    printf("Digite a idade máxima: ");
                                    scanf("%i", &ate_idade);
                                    getchar();
                                    localizar_jogador_idade(lista_jogador, de_idade, ate_idade);
                                    msg_press_enter();
                                    break;

                            case 4: printf("\nDigite o salário mínimo: ");
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

                            default: msg_usuario("\nOpção inválida! Tente novamente!");
                                     msg_press_enter();
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 0: limpar_tela();
                    break;

            default: msg_usuario("\nOpção inválida! Tente novamente!");
                     msg_press_enter();
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

	while(lista_jogador) {
		aux_jog = lista_jogador;
		lista_jogador = lista_jogador->proximo;
		free(aux_jog);
	}

	while(lista_partida) {
		aux_part = lista_partida;
		lista_partida = lista_partida->proxima;
		free(aux_part);
	}

    return 0;
}
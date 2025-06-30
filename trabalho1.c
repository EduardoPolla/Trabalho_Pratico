#include <stdio.h>
#include <string.h>
#include "./include/menus.h"
#include "./include/cadastros.h"
#include "./include/utils.h"
#include "./include/relatorios.h"

#define ENCERRAR 0

/*
//Mostrar jogadores =(3)=
void mostrar_jogadores(void);

//Mostrar Partidas =(5)=
void mostrar_partidas(void);

//Mostrar Jogadores por Faixa de Idade =(6)=
void mostrar_jogadores_idade(void);

//Mostrar Jogadores Vendidos =(7)=
void mostrar_jogadores_vendidos(void);

//Mostrar Jogadores por Nome =(8)=
void mostrar_jogadores_nome(void);

//Mostrar Jogadores por Posição =(9)=
void mostrar_jogadores_posicao(void);

//Mostrar Jogadores por Faixa Salarial =(10)=
void mostrar_jogadores_faixa_salario(void);

//Mostrar Jogador com Maior Salário =(11)=
void mostrar_jogador_maior_salario(void);

//Mostrar Partidas Contra Time Adversário =(12)=
void mostrar_partidas_time_adversario(void);

//Mostrar Índice de Aproveitamento =(13)=
void mostrar_indice_aproveitamento(void);

//Mostrar Valor do Time =(14)=
void mostrar_valor_time(void);

//Redefenir Dados Jogador =(15)=
void redefenir_dados_jogador(void);

//Redefinir Dados Partida =(16)=
void redefinir_dados_partida(void);
*/

int main()
{
    //Menu
    int opcao, sub_opcao;

    // Jogadores 
    lista_jogador_t lista_jogador;
    no_jogador_t *aux_jogador;
    inicializa_lista_jogador(&lista_jogador);

    // Partida
    lista_partida_t lista_partida;
    no_partida_t *aux_partida;
    inicializa_lista_partida(&lista_partida);

    do {
        opcao = menu_principal();

        switch(opcao) {
            
            case 1: do {
                        sub_opcao = menu_cadastros();

                        switch(sub_opcao) {

                            case 1: aux_jogador = novo_registro_jogador();
                                    insere_novo_registro_jogador(aux_jogador, &lista_jogador);
                                    break;


                            case 2: aux_partida = novo_registro_partida();
                                    insere_novo_registro_partida(aux_partida, &lista_partida);
                                    break;

                            default: printf("Opção inválida! Tente novamente!\n");
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 2: do {
                        sub_opcao = menu_relatorios();

                        switch(sub_opcao) {

                            case 0: limpar_tela();
                            break;

                            default: printf("Opção inválida! Tente novamente!\n");
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 3: do {
                        sub_opcao = menu_consultas();

                        switch(sub_opcao) {

                            case 0: limpar_tela();
                            break;

                            default: printf("Opção inválida! Tente novamente!\n");
                        }
                    } while(sub_opcao != ENCERRAR);
                    break;

            case 0: limpar_tela();
                    break;

            default: printf("Opção inválida! Tente novamente!\n");
        }

    } while(opcao != ENCERRAR);

    return 0;
}

/*
//IMPORTANTE: VISITAR A FUNÇÃO mostrar_dados_partidas ANTES DE ANALISAR partidas!!!
//Mostrar Partidas =(5)=
void mostrar_partidas(void)
{
    //Caso ainda não haja cadastro
    if(lista_partidas.qtd_partidas == 0) {
        printf("Não há jogos cadastrados na base de dados!!!\n");
    }

    if(lista_partidas.qtd_partidas != 0) {
        for(int i = 0; i < lista_partidas.qtd_partidas; i++) {
            mostrar_dados_partidas(i);
        }
    }
}

//Mostrar Jogadores por Faixa de Idade =(6)=
void mostrar_jogadores_idade(void)
{
    int de, ate, achou = 0;

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
        achou++;
    }

    if(base_dados.qtd_jog != 0) {
        printf("Digite a faixa de idade para efetuar a busca!!!\n\n");
        printf("De: ");
        scanf("%i", &de);
        printf("Até: ");
        scanf("%i", &ate);

        for(int i = 0; i < base_dados.qtd_jog; i++) {
            if(base_dados.jogadores[i].idade >= de && base_dados.jogadores[i].idade <= ate) {
                mostrar_dados_jogadores(i);
                achou++;
            }
        }
    }
    //Caso não encontre
    if(achou == 0) {
        printf("Não há jogadores nessa faixa de idade no banco de dados!!!\n");
    }
}

//Mostrar Jogadores Vendidos =(7)=
void mostrar_jogadores_vendidos(void)
{
    char vendido[] = {'V','E','N','D','I','D','O'};
    int achou = 0;

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
        achou++;
    }

    if(base_dados.qtd_jog != 0) {
        for(int i = 0; i < base_dados.qtd_jog; i++) {
            if(base_dados.jogadores[i].atividade == 'n' || base_dados.jogadores[i].atividade == 'N' && strcmp(base_dados.jogadores[i].razao_inatividade, vendido) == 0) {
                mostrar_dados_jogadores(i);
                achou++;
            }
        }
    }
    //Caso não encontre
    if(achou == 0) {
        printf("Não há jogadores vendidos no banco de dados!!!\n");
    }
}

//Mostrar Jogadores por Nome =(8)=
void mostrar_jogadores_nome(void)
{
    string busca;
    string nome_temporario;
    int achou = 0;
    char *token;

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
        achou++;
    }

    if(base_dados.qtd_jog != 0) {
        printf("Digite o nome do jogador para executar a busca: ");
        fgets(busca, TAMANHO, stdin);
        busca[strlen(busca) - 1] = '\0';

        //Laço de repetição para fazer com todos os jogadores
        for(int i = 0; i < base_dados.qtd_jog; i++) {
            //Copiando a string de nome, porque o token vai "comendo" a string 
            strcpy(nome_temporario, base_dados.jogadores[i].nome_jogador);

        //Ponteiro = função(nome da string, "caractere desejado para separar a string em pedaços");
            token = strtok(nome_temporario, " ");

            //Enquanto o ponteiro apontar para algo, continua executando
            while(token != NULL) {
                //Se o nome que o usuário digitou for igual ao nome da parte da string cortada.....
                if(strcmp(busca, token) == 0 || strcmp(busca, base_dados.jogadores[i].nome_jogador) == 0) {
                    //Então são mostrados os dados do jogador
                    mostrar_dados_jogadores(i);
                    achou++;
                }

                //Segunda chamada da função, que deve receber NULL. Caso contrário, haveria um loop
                token = strtok(NULL, " ");
            }
        }
    }
    //Caso não encontre
    if(achou == 0) {
        printf("\nNão há jogadores com esse nome no banco de dados!!!\n");
    }
}

//Mostrar Jogadores por Posição =(9)=
void mostrar_jogadores_posicao(void)
{
    string busca;
    string posicao_temporaria;
    int achou = 0;
    char *token;

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
        achou++;
    }

    if(base_dados.qtd_jog != 0) {
        printf("Digite a posição do jogador para executar a busca: ");
        fgets(busca, TAMANHO, stdin);
        busca[strlen(busca) - 1] = '\0';

        //Laço de repetição para fazer com todos os jogadores
        for(int i = 0; i < base_dados.qtd_jog; i++) {
            //Copiando a string de posição, porque o token vai "comendo" a string 
            strcpy(posicao_temporaria, base_dados.jogadores[i].posicao);

        //Ponteiro = função(nome da string, "caractere desejado para separar a string em pedaços");
            token = strtok(posicao_temporaria, ";");

            //Enquanto o ponteiro apontar para algo, continua executando
            while(token != NULL) {
                //Se a posição que o usuário digitou for igual à posição da parte da string cortada.....
                if(strcmp(busca, token) == 0 || strcmp(busca, base_dados.jogadores[i].posicao) == 0) {
                    //Então são mostrados os dados do jogador
                    mostrar_dados_jogadores(i);
                    achou++;
                }

                //Segunda chamada da função, que deve receber NULL. Caso contrário, haveria um loop
                token = strtok(NULL, ";");
            }
        }
    }
    //Caso não encontre
    if(achou == 0) {
        printf("\nNão há jogadores atuando nessa posição no banco de dados!!!\n");
    }
}

//Mostrar Jogadores por Faixa Salarial =(10)=
void mostrar_jogadores_faixa_salario(void)
{
    int achou = 0;
    float de, ate; 

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
        achou++;
    }

    if(base_dados.qtd_jog != 0) {
        printf("Digite a faixa salarial para efetuar a busca!!!\n\n");
        printf("De: ");
        scanf("%f", &de);
        printf("Até: ");
        scanf("%f", &ate);

        for(int i = 0; i < base_dados.qtd_jog; i++) {
            if(base_dados.jogadores[i].salario >= de && base_dados.jogadores[i].salario <= ate) {
                mostrar_dados_jogadores(i);
                achou++;
            }
        }
    }
    //Caso não encontre
    if(achou == 0) {
        printf("\nNão há jogadores nessa faixa salarial no banco de dados!!!\n");
    }
}

//Mostrar Jogador com Maior Salário =(11)=
void mostrar_jogador_maior_salario(void)
{
    int maior = 0, contador;

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
    }

    if(base_dados.qtd_jog != 0) {
        for(int i = 0; i < base_dados.qtd_jog; i++) {
            if(base_dados.jogadores[i].salario > maior) {
                maior = base_dados.jogadores[i].salario;
                contador = i;
            }
        }
        mostrar_dados_jogadores(contador);
    }
}

//Mostrar Partidas Contra Time Adversário =(12)=
void mostrar_partidas_time_adversario(void)
{
    string nome_time_adv;
    int achou = 0;

    //Caso ainda não haja cadastro
    if(lista_partidas.qtd_partidas == 0) {
        printf("Não há jogos cadastrados na base de dados!!!\n");
        achou++;
    }
    
    if(lista_partidas.qtd_partidas != 0) {
        printf("Digite o nome do time adversário para realizar a busca: ");
        fgets(nome_time_adv, TAMANHO, stdin);
        nome_time_adv[strlen(nome_time_adv) - 1] = '\0';

        for(int i = 0; i < lista_partidas.qtd_partidas; i++) {
            if(strcmp(lista_partidas.partidas[i].nome_adversario, nome_time_adv) == 0) {
                mostrar_dados_partidas(i);
                achou++;
            }
        }
    }

    if(achou == 0) {
        printf("Não há nenhum jogo contra o time adversário no banco de dados!!!\n");
    }
}

//Mostrar Índice de Aproveitamento =(13)=
void mostrar_indice_aproveitamento(void)
{
    char vitoria[] = {'V','I','T','O','R','I','A'};
    int contador = 0;

    //Caso ainda não haja cadastro
    if(lista_partidas.qtd_partidas == 0) {
        printf("Não há jogos cadastrados na base de dados!!!\n");
    }
    
    if(lista_partidas.qtd_partidas != 0) {
        for(int i = 0; i < lista_partidas.qtd_partidas; i++) {
            if(strcmp(lista_partidas.partidas[i].resultado_partida, vitoria) == 0) {
                contador++;
            }
        }

        printf("Índice de aproveitamento é de %.2f por cento!!!\n", ((float)contador / lista_partidas.qtd_partidas) * 100);
    }
}

//Mostrar Valor do Time =(14)=
void mostrar_valor_time(void)
{
    double soma = 0;
    char vendido[] = {'V','E','N','D','I','D','O'};

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
    }    
    
    if(base_dados.qtd_jog != 0) {
        for(int i = 0; i < base_dados.qtd_jog; i++) {
            if(strcmp(base_dados.jogadores[i].razao_inatividade, vendido) != 0) {
                soma += base_dados.jogadores[i].valor_passe;
            }
        }
    }

    printf("Valor do time é de %f!!!\n", soma);
}

//Redefenir Dados Jogador =(15)=
void redefenir_dados_jogador(void)
{
    int numero_jog;
    char confirmar = 'n';

    //Caso ainda não haja cadastro
    if(base_dados.qtd_jog == 0) {
        printf("Não há jogadores cadastrados na base de dados!!!\n");
    }    

    if(base_dados.qtd_jog != 0) {
        while(confirmar == 'n' || confirmar == 'N') {
            printf("Digite o número do jogador para redefenir seus dados: ");
            scanf("%i", &numero_jog);
            getchar();

            numero_jog = numero_jog - 1;

            if(numero_jog > base_dados.qtd_jog - 1) {
                printf("\nEsse número não corresponde a nenhum jogador do banco de dados!!!\n");
                break;
            }

            if(numero_jog <= base_dados.qtd_jog - 1) {
                mostrar_dados_jogadores(numero_jog);

                printf("\nDigite S para confirmar e N para escolher outro jogador: ");
                scanf("%c", &confirmar);
                getchar();
                printf("\n");

                if(confirmar == 'S' || confirmar == 's') {
                    cadastro(numero_jog);
                }
            }
        }
    }
}

//Redefinir Dados Partida =(16)=
void redefinir_dados_partida(void)
{
    int numero_partida;
    char confirmar = 'n';

    //Caso ainda não haja cadastro
    if(lista_partidas.qtd_partidas == 0) {
        printf("Não há partidas cadastrados na base de dados!!!\n");
    }    

    if(lista_partidas.qtd_partidas != 0) {
        while(confirmar == 'n' || confirmar == 'N') {
            printf("Digite o número da partida para redefenir seus dados: ");
            scanf("%i", &numero_partida);
            getchar();

            numero_partida = numero_partida - 1;

            if(numero_partida > lista_partidas.qtd_partidas - 1) {
                printf("\nEsse número não corresponde a nenhuma partida do banco de dados!!!\n");
                break;
            }

            if(numero_partida <= lista_partidas.qtd_partidas - 1) {
                mostrar_dados_partidas(numero_partida);

                printf("\nDigite S para confirmar e N para escolher outra partida: ");
                scanf("%c", &confirmar);
                getchar();
                printf("\n");

                if(confirmar == 'S' || confirmar == 's') {
                    lista(numero_partida);
                }
            }
        }
    }
}
*/
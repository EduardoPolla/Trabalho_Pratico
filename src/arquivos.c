#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arquivos .bin
void salvar_jogadores_bin(no_jogador_t *lista_jogador, string nome_arq)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("\nNenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "wb");

    if(!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    while(lista_jogador) {
        fwrite(lista_jogador, sizeof(no_jogador_t), 1, fp);
        lista_jogador = lista_jogador->proximo;
    }

    fclose(fp);
}

void carregar_jogadores_bin(no_jogador_t **lista_jogador, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    while(!feof(fp)) {
        no_jogador_t *aux = (no_jogador_t*)malloc(sizeof(no_jogador_t));
        fread(aux, sizeof(no_jogador_t), 1, fp);
        if(!feof(fp)) {
            aux->proximo = NULL;
            insere_novo_registro_jogador(aux, lista_jogador);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

void salvar_partidas_bin(no_partida_t *lista_partida, string nome_arq)
{
    if(lista_vazia_partida(lista_partida)) {
        printf("\nNenhum partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "wb");

    if(!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    while(lista_partida) {
        fwrite(lista_partida, sizeof(no_partida_t), 1, fp);
        lista_partida = lista_partida->proxima;
    }

    fclose(fp);
}

void carregar_partidas_bin(no_partida_t **lista_partida, string nome_arq)
{
    FILE *fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    while(!feof(fp)) {
        no_partida_t *aux = (no_partida_t*)malloc(sizeof(no_partida_t));
        fread(aux, sizeof(no_partida_t), 1, fp);
        if(!feof(fp)) {
            aux->proxima = NULL;
            insere_novo_registro_partida(aux, lista_partida);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

// Arquivos .csv
void abrir_arquivo_csv(string nome_arq)
{
    char comando[TAMANHO];

    sprintf(comando, "xdg-open %s", nome_arq);
    system(comando); 
}

void mostrar_dados_jogador_csv(no_jogador_t *lista_jogador, FILE *fp) 
{
    fprintf(fp, "%s;", lista_jogador->dados.nome_jogador);
    fprintf(fp, "\"%s\";", lista_jogador->dados.posicao);
    fprintf(fp, "%i;", lista_jogador->dados.idade);
    fprintf(fp, "%.2f;", lista_jogador->dados.altura);
    fprintf(fp, "%.2f;", lista_jogador->dados.peso);
    fprintf(fp, "R$%.2f;", lista_jogador->dados.valor_passe);
    fprintf(fp, "R$%.2f;", lista_jogador->dados.valor_aquisicao);
    fprintf(fp, "R$%.2f;", lista_jogador->dados.salario);
    fprintf(fp, "%d/%d/%d;", lista_jogador->dados.admissao.dia, lista_jogador->dados.admissao.mes, lista_jogador->dados.admissao.ano);
    fprintf(fp, "%d/%d/%d;", lista_jogador->dados.venda.dia, lista_jogador->dados.venda.mes, lista_jogador->dados.venda.ano);
    fprintf(fp, "%s;", lista_jogador->dados.atividade);
    if(strcmp(lista_jogador->dados.atividade, "INATIVO") == 0) {
        fprintf(fp, "%s\n", lista_jogador->dados.razao_inatividade);
    }
    else {
        fprintf(fp, "\n");
    }
}

void mostrar_dados_partida_csv(no_partida_t *lista_partida, FILE *fp) 
{
    fprintf(fp, "%s;", lista_partida->dados.nome_adversario);
    fprintf(fp, "%s;", lista_partida->dados.local_partida);
    fprintf(fp, "%d/%d/%d;", lista_partida->dados.data_partida.dia, lista_partida->dados.data_partida.mes, lista_partida->dados.data_partida.ano);
    fprintf(fp, "%s;", lista_partida->dados.resultado_partida);
    fprintf(fp, "\"");
    for(int i = 0; i < 11; i++) {
        fprintf(fp, "%s", lista_partida->dados.escalacao[i]);
        if(i < 10) {
            fprintf(fp, ", ");
        }
    }
    fprintf(fp, "\";");
    fprintf(fp, "%i\n", lista_partida->dados.qtd_substituicoes);
}

void exportar_dados_jogador_csv(no_jogador_t *lista_jogador, string nome_arq)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("\nNenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }
    
    fprintf(fp, "NOME;POSIÇÃO;IDADE;ALTURA;PESO;VALOR VENDA;VALOR COMPRA;SALÁRIO;DATA ADMISSAO;DATA VENDA;ATIVIDADE;RAZÃO INATIVIDADE\n");

    while(lista_jogador) {
        mostrar_dados_jogador_csv(lista_jogador, fp);
        lista_jogador = lista_jogador->proximo;
    }    

    fclose(fp); 
}

void exportar_dados_partida_csv(no_partida_t *lista_partida, string nome_arq)
{
    if(lista_vazia_partida(lista_partida)) {
        printf("\nNenhuma partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }
    
    fprintf(fp, "NOME ADVERSÁRIO;LOCAL;DATA;RESULTADO;ESCALAÇÃO;N° SUBSTITUIÇÕES\n");

    while(lista_partida) {
        mostrar_dados_partida_csv(lista_partida, fp);
        lista_partida = lista_partida->proxima;
    }    

    fclose(fp); 
}

void exportar_dados_vendidos_csv(no_jogador_t *lista_jogador, string nome_arq)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("\nNenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp, "NOME;POSIÇÃO;IDADE;ALTURA;PESO;VALOR VENDA;VALOR COMPRA;SALÁRIO;DATA ADMISSAO;DATA VENDA;ATIVIDADE;RAZÃO INATIVIDADE\n");

    while(lista_jogador) {
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") == 0) {
            mostrar_dados_jogador_csv(lista_jogador, fp);
        }
        lista_jogador = lista_jogador->proximo;
    }    

    fclose(fp);
}

void exportar_adversario_csv(no_partida_t *lista_partida, string nome_adv, string nome_arq)
{
    if(lista_vazia_partida(lista_partida)) {
        printf("\nNenhum partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp, "NOME ADVERSÁRIO;LOCAL;DATA;RESULTADO;ESCALAÇÃO;N° SUBSTITUIÇÕES\n");

    while(lista_partida) {
        if(strcmp(lista_partida->dados.nome_adversario, nome_adv) == 0) {
            mostrar_dados_partida_csv(lista_partida, fp);
        }
        lista_partida = lista_partida->proxima;
    }    

    fclose(fp);
}

void exportar_info_time_csv(no_partida_t *lista_partida, no_jogador_t *lista_jogador, string nome_arq)
{
    int vitoria = 0, empate = 0, derrota = 0;
    int nmr_partidas = 0;
    float soma = 0;

    if(lista_vazia_partida(lista_partida) && lista_vazia_jogador(lista_jogador)) {
        printf("\nNão foi possível gerar o arquivo!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    while(lista_partida) {
        if(strcmp(lista_partida->dados.resultado_partida, "VITORIA") == 0) {
            vitoria++;
        }
        if(strcmp(lista_partida->dados.resultado_partida, "EMPATE") == 0) {
            empate++;
            nmr_partidas--;
        }
        if(strcmp(lista_partida->dados.resultado_partida, "DERROTA") == 0) {
            derrota++;
        }
        
        nmr_partidas++;
        lista_partida = lista_partida->proxima;
    }

    while(lista_jogador) {
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") != 0) {
            soma += lista_jogador->dados.valor_passe;
        }
        lista_jogador = lista_jogador->proximo;
    }

    fprintf(fp, "N° VITÓRIAS;N° EMPATES;N° DERROTAS;ÍNDICE DE APROVEITAMENTO;VALOR TIME\n");
    fprintf(fp, "%i;", vitoria);
    fprintf(fp, "%i;", empate);
    fprintf(fp, "%i;", derrota);
    fprintf(fp, "%.2f;", ((float)vitoria / nmr_partidas) * 100);
    fprintf(fp, "R$%.2f", soma);

    fclose(fp);
}

// Arquivos .txt
void mostrar_dados_jogador_txt(no_jogador_t *lista_jogador, FILE *fp)
{
    fprintf(fp, "Nome: %s\n", lista_jogador->dados.nome_jogador);
    fprintf(fp, "Posições: %s\n", lista_jogador->dados.posicao);
    fprintf(fp, "Idade: %i\n", lista_jogador->dados.idade);
    fprintf(fp, "Altura: %.2f\n", lista_jogador->dados.altura);
    fprintf(fp, "Peso: %.2f\n", lista_jogador->dados.peso);
    fprintf(fp, "Valor de passe: R$%.2f\n", lista_jogador->dados.valor_passe);
    fprintf(fp, "Valor de venda: R$%.2f\n", lista_jogador->dados.valor_aquisicao);
    fprintf(fp, "Salário: R$%.2f\n", lista_jogador->dados.salario);
    fprintf(fp, "Data de admissão: %d/%d/%d\n", lista_jogador->dados.admissao.dia, lista_jogador->dados.admissao.mes, lista_jogador->dados.admissao.ano);
    fprintf(fp, "Data de venda: %d/%d/%d\n", lista_jogador->dados.venda.dia, lista_jogador->dados.venda.mes, lista_jogador->dados.venda.ano);
    fprintf(fp, "Status: %s\n", lista_jogador->dados.atividade);
    if(strcmp(lista_jogador->dados.atividade, "INATIVO") == 0) {
        fprintf(fp, "Razão da Inatividade: %s\n", lista_jogador->dados.razao_inatividade);
    }
    fprintf(fp, "\n");
}

void mostrar_dados_partida_txt(no_partida_t *lista_partida, FILE *fp)
{
    fprintf(fp, "Adversário: %s\n", lista_partida->dados.nome_adversario);
    fprintf(fp, "Local da partida: %s\n", lista_partida->dados.local_partida);
    fprintf(fp, "Data da partida: %d/%d/%d\n", lista_partida->dados.data_partida.dia, lista_partida->dados.data_partida.mes, lista_partida->dados.data_partida.ano);
    fprintf(fp, "Resultado: %s\n", lista_partida->dados.resultado_partida);
    fprintf(fp, "Escalação: \n");
    for(int i = 0; i < 11; i++) {
        fprintf(fp, "Jogador[%i]: %s\n", i+1, lista_partida->dados.escalacao[i]);
    }
    fprintf(fp, "Quantidade de substituições: %i\n\n", lista_partida->dados.qtd_substituicoes);
}

void exportar_dados_jogador_txt(no_jogador_t *lista_jogador, string nome_arq)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("\nNenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if(!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }
    
    fprintf(fp, "-------------------------------\n");
    fprintf(fp, "Relatorio Completo de Jogadores\n");
    fprintf(fp, "-------------------------------\n\n");

    while(lista_jogador) {
        mostrar_dados_jogador_txt(lista_jogador, fp);  
        lista_jogador = lista_jogador->proximo;
    }  

    fclose(fp);
}

void exportar_dados_partida_txt(no_partida_t *lista_partida, string nome_arq)
{
    if(lista_vazia_partida(lista_partida)) {
        printf("\nNenhuma partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if(!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }
    
    fprintf(fp, "-------------------------------\n");
    fprintf(fp, "Relatorio Completo de Partidas\n");
    fprintf(fp, "-------------------------------\n\n");

    while(lista_partida) {
        mostrar_dados_partida_txt(lista_partida, fp);   
        lista_partida = lista_partida->proxima; 
    }

    fclose(fp);
}

void exportar_dados_vendidos_txt(no_jogador_t *lista_jogador, string nome_arq)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("\nNenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp, "----------------------------------------\n");
    fprintf(fp, "Relatorio Completo de Jogadores Vendidos\n");
    fprintf(fp, "----------------------------------------\n\n");


    while(lista_jogador) {
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") == 0) {
            mostrar_dados_jogador_txt(lista_jogador, fp);
        }
        lista_jogador = lista_jogador->proximo;
    }    

    fclose(fp);
}

void exportar_adversario_txt(no_partida_t *lista_partida, string nome_adv, string nome_arq)
{
    if(lista_vazia_partida(lista_partida)) {
        printf("\nNenhum partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp, "------------------------------------------------\n");
    fprintf(fp, "Relatorio Completo de Partidas Contra Adversário\n");
    fprintf(fp, "------------------------------------------------\n\n");

    while(lista_partida) {
        if(strcmp(lista_partida->dados.nome_adversario, nome_adv) == 0) {
            mostrar_dados_partida_txt(lista_partida, fp);
        }
        lista_partida = lista_partida->proxima;
    }    

    fclose(fp);
}

void exportar_info_time_txt(no_partida_t *lista_partida, no_jogador_t *lista_jogador, string nome_arq)
{
    int vitoria = 0, empate = 0, derrota = 0;
    int nmr_partidas = 0;
    float soma = 0;

    if(lista_vazia_partida(lista_partida) && lista_vazia_jogador(lista_jogador)) {
        printf("\nNão foi possível gerar o arquivo!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq, "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    while(lista_partida) {
        if(strcmp(lista_partida->dados.resultado_partida, "VITORIA") == 0) {
            vitoria++;
        }
        if(strcmp(lista_partida->dados.resultado_partida, "EMPATE") == 0) {
            empate++;
            nmr_partidas--;
        }
        if(strcmp(lista_partida->dados.resultado_partida, "DERROTA") == 0) {
            derrota++;
        }
        
        nmr_partidas++;
        lista_partida = lista_partida->proxima;
    }

    while(lista_jogador) {
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") != 0) {
            soma += lista_jogador->dados.valor_passe;
        }
        lista_jogador = lista_jogador->proximo;
    }

    fprintf(fp, "----------------------------------------\n");
    fprintf(fp, "Índice de Aproveitamento e Valor do Time\n");
    fprintf(fp, "----------------------------------------\n\n");

    fprintf(fp, "Número de vitórias: %i\n", vitoria);
    fprintf(fp, "Número de empates: %i\n", empate);
    fprintf(fp, "Número de derrotas: %i\n", derrota);
    fprintf(fp, "Índice de aproveitamento: %.2f\n", ((float)vitoria / nmr_partidas) * 100);
    fprintf(fp, "Valor do time: R$%.2f", soma);

    fclose(fp);
}

// Arquivos .html
void exportar_dados_jogador_html(no_jogador_t *lista_jogador, string nome_arq)
{
    if(lista_vazia_jogador(lista_jogador)) {
        printf("\nNenhum jogador cadastrado!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq , "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp , "<html> <body> <table> <tr> <td><h1>Nome do Jogador</h1></td> <td><h1>Posições</h1></td> <td><h1>Idade</h1></td> <td><h1>Altura</h1></td> <td><h1>Peso</h1></td> <td><h1>Valor Aquisição</h1></td> <td><h1>Valor de Venda</h1></td> <td><h1>Salario</h1></td> <td><h1>Data de Admissão</h1></td> <td><h1>Data de Venda</h1></td> <td><h1>Atividade</h1></td> <td><h1>Razão Inatividade</h1></td> </tr>\n");

    while(lista_jogador) {
        fprintf(fp , "<tr>"); 
        fprintf(fp, "<td><p>%s</p></td>", lista_jogador->dados.nome_jogador);
        fprintf(fp, "<td><p>%s</p></td>", lista_jogador->dados.posicao);
        fprintf(fp , "<td><p>%i</p></td>", lista_jogador->dados.idade);
        fprintf(fp, "<td><p>%.2f</p></td>", lista_jogador->dados.altura);
        fprintf(fp , "<td><p>%.2f</p></td>", lista_jogador->dados.peso);
        fprintf(fp, "<td><p>R$%.2f</p></td>", lista_jogador->dados.valor_aquisicao);
        fprintf(fp , "<td><p>R$%.2f</p></td>", lista_jogador->dados.valor_passe);
        fprintf(fp, "<td><p>R$%.2f</p></td>", lista_jogador->dados.salario);
        fprintf(fp , "<td><p>%i/%i/%i</p></td>", lista_jogador->dados.admissao.dia, lista_jogador->dados.admissao.mes, lista_jogador->dados.admissao.ano);
        fprintf(fp, "<td><p>%i/%i/%i</p></td>", lista_jogador->dados.venda.dia, lista_jogador->dados.venda.mes, lista_jogador->dados.venda.ano);
        fprintf(fp , "<td><p>%s</p></td>", lista_jogador->dados.atividade);
        if(strcmp(lista_jogador->dados.razao_inatividade, "VENDIDO") == 0) {
            fprintf(fp , "<td><p>%s</p></td> </tr>\n", lista_jogador->dados.razao_inatividade);
        }
        else {
            fprintf(fp, "</tr>\n");
        }
        lista_jogador = lista_jogador->proximo;
    }

    fprintf(fp , "</table> </body> </html>");

    fclose(fp);
}

void exportar_dados_partida_html(no_partida_t *lista_partida, string nome_arq)
{
    if(lista_vazia_partida(lista_partida)) {
        printf("\nNenhum partida cadastrada!\n");
        msg_press_enter();
        return;
    }

    FILE *fp = fopen(nome_arq , "w");

    if (!fp) {
        printf("\nErro ao abrir o arquivo %s!\n", nome_arq);
        msg_press_enter();
        return;
    }

    fprintf(fp , "<html> <body> <table> <tr> <td><h1>Nome do Adversário</h1></td> <td><h1>Local da Partida</h1></td> <td><h1>Data da Partida</h1></td> <td><h1>Resultado</h1></td> <td><h1>Quantidade de Substituições</h1></td> </tr>\n");

    while(lista_partida) {
        fprintf(fp , "<tr> <td><p>%s</p></td>", lista_partida->dados.nome_adversario);
        fprintf(fp, "<td><p>%s</p></td>", lista_partida->dados.local_partida);
        fprintf(fp , "<td><p>%i/%i/%i</p></td> ", lista_partida->dados.data_partida.dia, lista_partida->dados.data_partida.mes, lista_partida->dados.data_partida.ano);
        fprintf(fp , "<td><p>%s</p></td>", lista_partida->dados.resultado_partida);
        fprintf(fp, "<td><p>%i</p></td> </tr>\n", lista_partida->dados.qtd_substituicoes);

        lista_partida = lista_partida->proxima;
    }

    fprintf(fp , "</table> </body> </html>");

    fclose(fp);
}
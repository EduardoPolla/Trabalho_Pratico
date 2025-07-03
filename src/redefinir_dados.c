#include "../include/redefinir_dados.h"
#include "../include/cadastros.h"

void redefinir_jogador(**lista_jogador)
{
    string nome;

    if(lista_vazia_jogador(*lista_jogador)) {
        printf("Nenhum jogador cadastrado!\n");
        return;
    }

    printf("Digite o nome completo do jogador: ");
    fgets(nome, TAMANHO, stdin);
    retirar_enter(nome);
    formatar_maiusculas(nome);
}

void redefinir_partida(**lista_partida)
{

}

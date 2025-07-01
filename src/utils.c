#include "../include/utils.h"

void limpar_tela()
{
    system("clear");
}

void retirar_enter(string string)
{
    string[strlen(string) - 1] = '\0';
}

void formatar_maiusculas(string string)
{
    for(size_t i = 0; i < strlen(string); i++) {
        *(string+i) = toupper(*(string+i));
    }
}

void msg_press_enter()
{
    printf("\nPressione ENTER para limpar a tela: ");
    getchar();
}
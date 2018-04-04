#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "estrutura.h"
#include "Cadastrar_Imoveis.h"
#include "Consulta_Imoveis.h"

int main(){
    setlocale(LC_ALL, "");
    tImovel imovel;
    int escolha = 1;

    FILE *imoveis;
    imoveis = fopen("imobiliaria.dat", "a+b");
    if(!imoveis){
        printf("NAO CONSEGUIU ABRIR O ARQUIVO\n");
    }

    while(escolha){
        escolha  = Menu();
        SubMenu(imovel , escolha, imoveis);
        printf("Deseja terminar o programa ?\n"
               "1-Continuar programa\n"
               "0-Terminar programa\n"
               "Resposta: ");
        scanf("%d", &escolha);
        system("cls");
        system("clear");
        printf("\n");
        fseek(imoveis, 0 ,SEEK_SET);
    }

    fclose(imoveis);
    return 0;
}
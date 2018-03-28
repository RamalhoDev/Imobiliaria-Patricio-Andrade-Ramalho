#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"


void SubMenu(int indice, FILE *imoveis){
    int escolha, quantidade;
    
    switch(indice){
        case 1:
            Cadastrar_Imoveis(imoveis);
            break;
        case 2:
            printf("2-1.Consultar imóveis por tipo (casa, apartamento ou terreno:\n");
            printf("2-2.Consultar imóveis para vender por bairro:\n");
            printf("2-3.Consultar imóveis para alugar por bairro:\n");
            printf("2-4.Consultar imóveis disponíveis por cidade:\n");
            printf("2-5.Consultar todos os imóveis :\n");
            printf("2-6.Consultar todos  os imóveis e suas características:\n");
            printf("Digite sua opção (1 a 6):  ");
            scanf("%d", &escolha);
            break;
    }

}

int Menu(){
    int i;
    printf("============================================================================\n");
    printf("1- Cadastrar imoveis :\n" );
    printf("2- Consultar imoveis :\n" );
    printf("Digite sua opcaoo:  ");
    scanf("%d%*c", &i);
    system("cls");
    system("clear");
    return i;
}

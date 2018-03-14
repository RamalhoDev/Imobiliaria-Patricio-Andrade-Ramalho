#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"


int Menu(){
    int i;
    printf("============================================================================\n");
    printf("1- Cadastrar imóveis :\n" );
    printf("2- Consultar imóveis :\n" );
    printf("Digite sua opção:  ");
    scanf("%d", &i);

    return i;
}

void SubMenu(){
    int indice= Menu(), escolha;

    switch(indice){
        case 1:
            Cadastrar_Imóveis();
            break;
        case 2:
            printf("2-1.Consultar imóveis por tipo (casa, apartamento ou terreno:\n");
            printf("2-2.Consultar imóveis para vender por bairro:\n");
            printf("2-3.Consultar imóveis para alugar por bairro:\n");
            printf("2-4.Consultar imóveis disponíveis por cidade:\n", );
            printf("2-5.Consultar todos os imóveis :\n");
            printf("2-6.Consultar todos  os imóveis e suas características:\n");
            printf("Digite sua opção (1 a 6):  ");
            scanf("%d", &escolha);

            break;
    }

}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cadastrar_Imoveis.h"


void Cadastrar_Imoveis(int quantos){
    int i;
    for(i = 0; i<quantos; i++){
        printf("Insira as seguintes informações sobre o imóvel:\n ");
        printf("Insira o endereo do imóvel: ");
        fgets(imoveis[i].rua, Qt, stdin);
        printf("\nInsira o número da casa: ");
        scanf("%d", &imoveis[i].numero);
        printf("Insira o bairro do imóvel: ");
        fgets(imoveis[i].bairro, Qt, stdin);
        getchar();
        printf("Insira o cep do imóvel: ");
        fgets(imoveis[i].cep, Qt, stdin);
        getchar();
        printf("Insira a cidade do imóvel: ");
        fgets(imoveis[i].cidade, Qt, stdin);
        getchar();
    }
}
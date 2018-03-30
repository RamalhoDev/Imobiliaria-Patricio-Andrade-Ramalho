#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Consulta_Imoveis.h"

void Consultar_Todos_Imoveis(tImovel imovel ,FILE *imoveis){
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
                
        printf("Casa %d da Rua: %s\n", imovel.numero, imovel.rua);
        if(feof(imoveis)){
            break;
        }
    }
}


void Consultar_Vender_Tipo(tImovel imovel ,FILE *imoveis){
    int tipoImovel;
    printf("Digite o tipo de imóvel para vender que você deseja pesquisar:\n"
           "1-Casa\n"
           "2-Apartamento\n"
           "3-Terreno\n"
           "4-Flat\n"
           "5-Studio\n"
           "Resposta: ");
    scanf("%d", &tipoImovel);
    system("cls");
    system("clear");
            
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        if(tipoImovel == imovel.tipo && imovel.transacao == 1){
            printf("Casa %d da Rua: %s", imovel.numero, imovel.rua);
            printf("Preço: R$ %.2lf\n", imovel.valor);
            if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5){
                printf("Condomínio: R$ %.2lf\n\n", imovel.condominio);
            }
        }
        if(feof(imoveis)){
            break;
        }
    }
}

void Consultar_Alugar_Tipo(tImovel imovel ,FILE *imoveis){
    int tipoImovel;
    printf("Digite o tipo de imóvel para alugar que você deseja pesquisar:\n"
           "1-Casa\n"
           "2-Apartamento\n"
           "3-Terreno\n"
           "4-Flat\n"
           "5-Studio\n"
           "Resposta: ");
    scanf("%d", &tipoImovel);
    system("cls");
    system("clear");
            
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        
        if(tipoImovel == imovel.tipo && imovel.transacao == 2){
            printf("Casa %d da Rua: %s", imovel.numero, imovel.rua);
            printf("Preço: R$ %.2lf\n", imovel.valor);
            if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5){
                printf("Condomínio: R$ %.2lf\n\n", imovel.condominio);
            }
        }
        if(feof(imoveis)){
            break;
        }
    }
}

void Consultar_Vender_Bairro(tImovel imovel ,FILE *imoveis){
    char bairro2[Qt];
    size_t tamanho;

    printf("Qual bairro você deseja procurar ?\n");
    fgets(bairro2, Qt, stdin);
    tamanho = strlen(bairro2);
    STRING_MAIUSCULO(bairro2, tamanho);
    puts(bairro2);
    //system("cls");
    //system("clear");
            
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        if(!strcmp(bairro2 ,imovel.bairro) && imovel.transacao == 1){
            printf("Casa %d da Rua: %s", imovel.numero, imovel.rua);
            printf("Preço: R$ %.2lf\n", imovel.valor);
            if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5){
                printf("Condomínio: R$ %.2lf\n\n", imovel.condominio);
            }
        }
        if(feof(imoveis)){
            break;
        }
    }
}

void Consultar_Alugar_Bairro(tImovel imovel,FILE *imoveis){
    char bairro2[Qt];
    size_t tamanho;

    printf("Qual bairro você deseja procurar ?\n");
    fgets(bairro2, Qt, stdin);
    tamanho = strlen(bairro2);
    STRING_MAIUSCULO(bairro2, tamanho);
    
    //system("cls");
    //system("clear");

    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        if(!strcmp(bairro2 ,imovel.bairro) && imovel.transacao == 2){
            printf("Casa %d da Rua: %s", imovel.numero, imovel.rua);
            printf("Preço: R$ %.2lf\n", imovel.valor);
            if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5){
                printf("Condomínio: R$ %.2lf\n\n", imovel.condominio);
            }
        }
        if(feof(imoveis)){
            break;
        }
    }
}

void STRING_MAIUSCULO(char frase[], size_t tamanho){
    int i;

    for(i = 0; i < tamanho-1; i++){
        frase[i] = toupper(frase[i]);
    }
}


void Consultar_Descricao_Todos_Imoveis(tImovel imovel ,FILE * imoveis){
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
            printf("Imóvel %d da Rua: %s", imovel.numero, imovel.rua);
            printf("Preço: R$ %.2lf || ", imovel.valor);
            if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5){
                printf("Condomínio: R$ %.2lf\n", imovel.condominio);
            }
            printf("Bairro: %s || Endereço: %s, %d\n", imovel.bairro, imovel.rua, imovel.numero);
            printf("CEP: %s || Cidade: %s");
        if(feof(imoveis)){
            break;
        }
    }
}



void Consultar_Descricao_Cidade(tImovel imovel ,FILE *imoveis){
    char cidade2[Qt];
    size_t tamanho;

    printf("Qual cidade você deseja procurar ?\n");
    fgets(cidade2, Qt, stdin);
    tamanho = strlen(cidade2);
    STRING_MAIUSCULO(cidade2, tamanho);

    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        if(!strcmp(cidade2 ,imovel.cidade) ){
            printf("Casa %d da Rua: %s", imovel.numero, imovel.rua);
            printf("Preço: R$ %.2lf\n", imovel.valor);
            if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5){
                printf("Condomínio: R$ %.2lf\n\n", imovel.condominio);
            }
        }
        if(feof(imoveis)){
            break;
        }
    }
}
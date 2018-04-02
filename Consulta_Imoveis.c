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
            printf("Bairro: %s    || \nEndereço: \nRua: %s, \nNúmero:%d\n", imovel.bairro, imovel.rua, imovel.numero);
            printf("\nCidade: %s || CEP: %s\n", imovel.cidade, imovel.cep);
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
            if(imovel.tipo==1){
                puts("-------------------------------------------------\n");
                printf("Casas da Cidade: %s\n", imovel.cidade);
                puts("-------------------------------------------------\n\n");
                puts("Dados de Localização\n\n");
                printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
                printf("Bairro: %s\n", imovel.bairro);
                printf("CEP: %s\n"imovel.bairro);
                
                puts("Dados Mobiliários\n\n");
                printf("Quantidade de Andares: %d\n",imovel.casa.andares);
                printf("Quantidade de Quartos: %d\n",imovel.casa.qtQuartos);
                printf("Extensao territorial: %d\n",imovel.casa.areaTer);
                printf("QArea Construída: %d\n",imovel.casa.areaConst);
                printf("Preço: R$ %.2lf\n", imovel.valor);
            }
            if(imovel.tipo==2){
                puts("-------------------------------------------------\n");
                printf("Apartamentos da Cidade: %s\n", imovel.cidade);
                puts("-------------------------------------------------\n\n");
                puts("Dados de Localização\n\n");
                printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
                printf("Bairro: %s\n", imovel.bairro);
                printf("CEP: %s\n"imovel.bairro);
                
                puts("Dados Mobiliários\n\n");
                printf("Andar do apartamento: %d\n",imovel.ap.andar);
                printf("Quantidade de quartos do apartamento: %d\n",imovel.ap.qtQuartos);
                printf("Extensao territorial: %d\n",imovel.ap.area);
                print("Posição do apartamento: %s\n",imovel.ap.posicao);
                printf("Vagas na Garagem: %d",imovel.ap.qtGaragens);
                printf("Valor do condomínio: R$ %.2lf\n", imovel.ap.condominio);
            }
            if(imovel.tipo==3){
                puts("-------------------------------------------------\n");
                printf("Terrenos da Cidade: %s\n", imovel.cidade);
                puts("-------------------------------------------------\n\n");
                puts("Dados de Localização\n\n");
                printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
                printf("Bairro: %s\n", imovel.bairro);
                printf("CEP: %s\n"imovel.bairro);
                
                puts("Dados Mobiliários\n\n");
                printf("Área do Terreno: %d\n",imovel.ter.area);
            }
            if(imovel.tipo==4 || 5){
                puts("-------------------------------------------------\n");
                if(imovel.tipo==4){
                printf("Flats da Cidade: %s\n", imovel.cidade);
                }
                if(tipo.imovel==5){
                    printf("Studios da Cidade: %s\n", imovel.cidade);
                }
                puts("-------------------------------------------------\n\n");
                puts("Dados de Localização\n\n");
                printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
                printf("Bairro: %s\n", imovel.bairro);
                printf("CEP: %s\n"imovel.bairro);
                
                puts("Dados Mobiliários\n\n");
                printf("Área do Imóvel: %d\n",imovel.flat.area);
                printf("Possui ar-condicionado: %s\n",imovel.flat.ar);
                printf("Possui internet: %s\n",imovel.flat.internet);
                printf("Possui Tv a cabo: %s\n",imovel.flat.tv);
                printf("Possui Lavanderia: %s\n",imovel.flat.lavanderia);
                printf("Possui Serviço de quarto %s\n",imovel.flat.limpeza);
                printf("Possui Recepção 24 horas %s\n",imovel.flat.recepcao);
                printf("Valor: %.2lf\n",imovel.flat.condominio);
                
                if(tipo.imovel==5){
                    printf("Possui Pscina: %s\n",imovel.studio.piscina);
                    printf("Possui Sauna: %s\n",imovel.studio.sauna);  
                    printf("Possui Academia: %s\n",imovel.studio.academia);  
                }
            }
            /* printf("Casa %d da Rua: %s", imovel.numero, imovel.rua);
            printf("Preço: R$ %.2lf\n", imovel.valor);
            if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5){
                printf("Condomínio: R$ %.2lf\n\n", imovel.condominio);
            */
            }
        }
        if(feof(imoveis)){
            break;
        }
    }
}

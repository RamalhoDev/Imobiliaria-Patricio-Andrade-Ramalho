#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Consulta_Imoveis.h"

void Consultar_Todos_Imoveis(tImovel imovel ,FILE *imoveis){
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){

        switch(imovel.tipo){        
            case 1:
                Consulta_Parcial_Casa(imovel);
                break;
            case 2:
                Consulta_Parcial_Apartamento(imovel);
                break;
            case 3:
                Consulta_Parcial_Terreno(imovel);
                break;
            case 4:
                Consulta_Parcial_Flat(imovel);
                break;
            case 5:
                Consulta_Parcial_Studio(imovel);
                break;
        }

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
           "5-Studio\n\n"
           "Resposta: ");
    scanf("%d", &tipoImovel);
    system("cls");
    system("clear");
            
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        
        if(tipoImovel == imovel.tipo && imovel.transacao == 1){
            switch(imovel.tipo){        
            case 1:
                Consulta_Parcial_Casa(imovel);
                break;
            case 2:
                Consulta_Parcial_Apartamento(imovel);
                break;
            case 3:
                Consulta_Parcial_Terreno(imovel);
                break;
            case 4:
                Consulta_Parcial_Flat(imovel);
                break;
            case 5:
                Consulta_Parcial_Studio(imovel);
                break;
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
            
            switch(imovel.tipo){        
            case 1:
                Consulta_Parcial_Casa(imovel);
                break;
            case 2:
                Consulta_Parcial_Apartamento(imovel);
                break;
            case 3:
                Consulta_Parcial_Terreno(imovel);
                break;
            case 4:
                Consulta_Parcial_Flat(imovel);
                break;
            case 5:
                Consulta_Parcial_Studio(imovel);
                break;
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
    //system("cls");
    //system("clear");
            
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        
        if(!strcmp(bairro2 ,imovel.bairro) && imovel.transacao == 1){
            switch(imovel.tipo){        
                case 1:
                    Consulta_Parcial_Casa(imovel);
                    break;
                case 2:
                    Consulta_Parcial_Apartamento(imovel);
                    break;
                case 3:
                    Consulta_Parcial_Terreno(imovel);
                    break;
                case 4:
                    Consulta_Parcial_Flat(imovel);
                    break;
                case 5:
                    Consulta_Parcial_Studio(imovel);
                    break;
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
        
            switch(imovel.tipo){        
                case 1:
                    Consulta_Parcial_Casa(imovel);
                    break;
                case 2:
                    Consulta_Parcial_Apartamento(imovel);
                    break;
                case 3:
                    Consulta_Parcial_Terreno(imovel);
                    break;
                case 4:
                    Consulta_Parcial_Flat(imovel);
                    break;
                case 5:
                    Consulta_Parcial_Studio(imovel);
                    break;
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
            switch(imovel.tipo){        
                case 1:
                    Consultar_Descricao_Casa(imovel);
                    break;
                case 2:
                    Consultar_Descricao_Apartamento(imovel);
                    break;
                case 3:
                    Consultar_Descricao_Terreno(imovel);
                    break;
                case 4:
                    Consultar_Descricao_Flat(imovel);
                    break;
                case 5:
                    Consultar_Descricao_Studio(imovel);
                    break;
            }   
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
            switch(imovel.tipo){        
                case 1:
                    Consultar_Descricao_Casa(imovel);
                    break;
                case 2:
                    Consultar_Descricao_Apartamento(imovel);
                    break;
                case 3:
                    Consultar_Descricao_Terreno(imovel);
                    break;
                case 4:
                    Consultar_Descricao_Flat(imovel);
                    break;
                case 5:
                    Consultar_Descricao_Studio(imovel);
                    break;
            }   
        }
        if(feof(imoveis)){
            break;
        }
    }
}

void Consulta_Parcial_Casa(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tCasa\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    printf("Preço: R$ %.2lf\n", imovel.valor);
    
}
void Consulta_Parcial_Apartamento(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tApartamento\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    printf("Valor do condomínio: R$ %.2lf\n", imovel.ap.condominio);
    printf("Preço: R$ %.2lf\n", imovel.valor);
}

void Consulta_Parcial_Terreno(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tTerreno\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    printf("Preço: R$ %.2lf\n", imovel.valor);
}

void Consulta_Parcial_Flat(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tFlat\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    printf("Preço: R$ %.2lf\n", imovel.valor);
    printf("Valor: %.2lf\n",imovel.flat.condominio);
}

void Consulta_Parcial_Studio(tImovel imovel){
    printf("-------------------------------------------------\n\n");
    printf("\t\t\tStudio\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("Preço: R$ %.2lf\n", imovel.valor);
    printf("Valor: %.2lf\n",imovel.flat.condominio);
}

void Consultar_Descricao_Casa(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tCasa\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    
    printf("Dados Mobiliários\n\n");
    printf("Quantidade de Andares: %d\n",imovel.casa.andares);
    printf("Quantidade de Quartos: %d\n",imovel.casa.qtQuartos);
    printf("Extensao territorial: %d\n",imovel.casa.areaTer);
    printf("Área Construída: %d\n",imovel.casa.areaConst);
    printf("Preço: R$ %.2lf\n", imovel.valor);
}

void Consultar_Descricao_Apartamento(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tApartamento\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    
    printf("Dados Mobiliários\n\n");
    printf("Andar do apartamento: %d\n",imovel.ap.andar);
    printf("Quantidade de quartos do apartamento: %d\n",imovel.ap.qtQuartos);
    printf("Extensao territorial: %d\n",imovel.ap.area);
    printf("Posição do apartamento: %s\n",imovel.ap.posicao);
    printf("Vagas na Garagem: %d",imovel.ap.qtGaragens);
    printf("Valor do condomínio: R$ %.2lf\n", imovel.ap.condominio);
    printf("Preço: R$ %.2lf\n", imovel.valor);
}

void Consultar_Descricao_Terreno(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tTerreno\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    
    printf("Dados Mobiliários\n\n");
    printf("Área do Terreno: %d\n",imovel.ter.area);
    printf("Preço: R$ %.2lf\n", imovel.valor);
}

void Consultar_Descricao_Flat(tImovel imovel){
    printf("-------------------------------------------------\n");
    printf("\t\t\tFlat\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);
    
    printf("Dados Mobiliários\n\n");
    printf("Área do Imóvel: %d\n",imovel.flat.area);
    printf("Possui ar-condicionado: %c\n",imovel.flat.ar);
    printf("Possui internet: %c\n",imovel.flat.internet);
    printf("Possui Tv a cabo: %c\n",imovel.flat.tv);
    printf("Possui Lavanderia: %c\n",imovel.flat.lavanderia);
    printf("Possui Serviço de quarto %c\n",imovel.flat.limpeza);
    printf("Possui Recepção 24 horas %c\n",imovel.flat.recepcao);
    printf("Valor: %.2lf\n",imovel.flat.condominio);
    printf("Preço: R$ %.2lf\n", imovel.valor);
}

void Consultar_Descricao_Studio(tImovel imovel){
    printf("-------------------------------------------------\n\n");
    printf("\t\t\tStudio\n");
    printf("-------------------------------------------------\n\n");
    printf("Dados de Localização\n\n");
    printf("Casa numero: %d da Rua: %s\n", imovel.numero, imovel.rua);
    printf("Bairro: %s\n", imovel.bairro);
    printf("CEP: %s\n",imovel.cep);

    printf("Dados Mobiliários\n\n");
    printf("Área do Imóvel: %d\n",imovel.flat.area);
    printf("Possui ar-condicionado: %c\n",imovel.flat.ar);
    printf("Possui internet: %c\n",imovel.flat.internet);
    printf("Possui Tv a cabo: %c\n",imovel.flat.tv);
    printf("Possui Lavanderia: %c\n",imovel.flat.lavanderia);
    printf("Possui Serviço de quarto %c\n",imovel.flat.limpeza);
    printf("Possui Recepção 24 horas %c\n",imovel.flat.recepcao);
    printf("Valor: %.2lf\n",imovel.flat.condominio);
    printf("Preço: R$ %.2lf\n", imovel.valor);

    printf("Possui Piscina: %c\n",imovel.studio.piscina);
    printf("Possui Sauna: %c\n",imovel.studio.sauna);  
    printf("Possui Academia: %c\n",imovel.studio.academia);  
}
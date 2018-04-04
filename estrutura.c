#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

//Função responsável por executar as funções de cadastro/consultas de acordo com a escolha do usuário
void SubMenu(tImovel imovel,int indice, FILE *imoveis){
    int escolha, quantidade;
    
    switch(indice){
        //Caso o usuário digite 1, ele será direcionado a função de cadastro
        case 1:
            Cadastrar_Imoveis(imovel,imoveis);
            break;
        //Caso o usuário digite 2, ele será direcionado as funções de consulta
        case 2:
            printf("2-1.Consultar todos os imóveis\n"
                   "2-2.Consultar imóveis para vender por tipo de imóvel:\n"
                   "2-3.Consultar imóveis para alugar por tipo de imóvel:\n"
                   "2-4.Consultar imóveis para vender por bairro:\n"
                   "2-5.Consultar imóveis para alugar por bairro:\n"
                   "2-6.Consultar imóveis disponíveis por cidade:\n"
                   "2-7.Consultar todos  os imóveis e suas características:\n"
                   "Digite sua opção (1 a 6): ");
            scanf("%d%*c", &escolha);
            system("cls");
            system("clear");
            switch(escolha){
                //Após de ser direcionado a parte de consulta, o usuário terá 7 opçoes para consultar informações.
                case 1:
                    Consultar_Todos_Imoveis(imovel , imoveis);
                    break;
                case 2:
                    Consultar_Vender_Tipo(imovel, imoveis);
                    break;
                case 3:
                    Consultar_Alugar_Tipo(imovel, imoveis);
                    break;
                case 4:
                    Consultar_Vender_Bairro(imovel, imoveis);
                    break;
                case 5:
                    Consultar_Alugar_Bairro(imovel, imoveis);
                    break;
                case 6:
                    Consultar_Descricao_Cidade(imovel, imoveis);
                    break;
                case 7:
                    Consultar_Descricao_Todos_Imoveis(imovel, imoveis);
                    break;
            }
            break;
    }
}

//Função responsável por retornar a opção do usuário (Cadastrar/Consultar)
int Menu(){
    int i;
    printf("*******************************************\n");
    printf("1-Cadastrar imoveis\n"
           "2-Consultar imoveis\n"
           "Digite sua opção:  ");
    scanf("%d%*c", &i);
    system("cls");
    system("clear");
    return i;
}

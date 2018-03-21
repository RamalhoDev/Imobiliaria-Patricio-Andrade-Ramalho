#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define Qt 60

typedef struct{
    int andar;
    int area;
    int qtQuartos;
    int qtGaragens;
    char posicao[Qt];
    double condominio;
}tApartamento;

typedef struct{
    int qtQuartos;
    int areaTer;
    int areaConst;
    int andares;
}tCasa;

typedef struct{
    int area;
}tTerreno;

typedef struct{
    char rua[Qt];
    int numero;
    char bairro[Qt];
    char cep[Qt];
    char cidade[Qt];
    int transacao;
    int tipo;
    double valor;
    tApartamento ap;
    tCasa casa;
    tTerreno ter;
}tImovel;

tImovel imovel;

int Menu();
void SubMenu();
void Cadastrar_Imoveis();
void Cadastrar_Casa();
void Cadastrar_Apartamento();
void Cadastrar_Terreno();




int main(){
    FILE *imoveis;
    imoveis = fopen("imobiliaria.txt", "ab");
    int escolha  = Menu();
    SubMenu(escolha, imoveis);
    setlocale(LC_ALL, "Portuguese");
    fclose(imoveis);
    return 0;
}





int Menu(){
    int i;
    printf("============================================================================\n");
    printf("1- Cadastrar imóveis :\n" );
    printf("2- Consultar imóveis :\n" );
    printf("Digite sua opção:  ");
    scanf("%d", &i);
    system("cls");
    system("clear");
    return i;
}





void Cadastrar_Imoveis(FILE *imoveis){
    printf("Insira as seguintes informações sobre o imóvel:\n ");
    printf("Insira o endereo do imóvel: ");
    fgets(imovel.rua, Qt, stdin);
    printf("\nInsira o número da casa: ");
    scanf("%d", &imovel.numero);
    printf("Insira o bairro do imóvel: ");
    fgets(imovel.bairro, Qt, stdin);
    getchar();
    printf("Insira o cep do imóvel: ");
    fgets(imovel.cep, Qt, stdin);
    getchar();
    printf("Insira a cidade do imóvel: ");
    fgets(imovel.cidade, Qt, stdin);
    getchar();
    printf("Qual o tipo do seu imóvel ?\n"
           "1-Casa\n"
           "2-Apartamento\n"
           "3-Terreno\n");
    scanf("%d", &imovel.tipo);
    
    switch(imovel.tipo){
        case 1:
            Cadastrar_Casa(imoveis);
            break;
        case 2:
            Cadastrar_Apartamento(imoveis);
            break;
        case 3:
            Cadastrar_Terreno(imoveis);
            break;
        default:
            printf("Esse tipo não existe.");
    }
}





void Cadastrar_Casa(FILE *imoveis){
    printf("Digite a Área da casa em metros quadrados: ");
    scanf("")
    // if(fwrite(imovel, size(tImovel), 1, imoveis)!= 1){
    //     puts("Cadastro quase completo.");
    // }else{
    //     puts("Informações não foram escritas corretamente.");
    // }
}






void Cadastrar_Terreno(FILE *imoveis){
    // if(fwrite(imovel, size(tImovel), 1, imoveis)!= 1){
    //     puts("Cadastro quase completo.");
    // }else{
    //     puts("Informações não foram escritas corretamente.");
    // }
}





void Cadastrar_Apartamento(FILE *imoveis){
    // if(fwrite(imovel, size(tImovel), 1, imoveis)!= 1){
    //     puts("Cadastro quase completo.");
    // }else{
    //     puts("Informações não foram escritas corretamente.");
    // }
}





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


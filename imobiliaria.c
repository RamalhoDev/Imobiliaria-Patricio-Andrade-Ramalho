#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define Qt 100


typedef struct{
    char rua[Qt];
    int numero;
    char bairro[Qt];
    char cep[Qt];
    char cidade[Qt];
}tImovel;

tImovel imoveis[Qt];

int Menu();
void SubMenu();
void Cadastrar_Imoveis();


int main(){
    int escolha  = Menu();
    SubMenu(escolha);
    setlocale(LC_ALL, "Portuguese");
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

void Cadastrar_Imoveis(int quantos){
    int i;
    for(i = 0; i<quantos; i++){
        printf("Insira as seguintes informações sobre o imóvel:\n ");
        printf("Insira o endereo do imóvel: ");
        fgets(imoveis[i].rua, Qt, stdin);
        //getchar();
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

void SubMenu(int indice){
    int escolha, quantidade;

    switch(indice){
        case 1:
            printf("Quantos imoveis deseja cadastrar ?\n");
            scanf("%d%*c", &quantidade);
            Cadastrar_Imoveis(quantidade);
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


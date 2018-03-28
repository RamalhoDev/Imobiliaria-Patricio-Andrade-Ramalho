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
	int area;
	double condominio;
	char ar;
	char internet;
	char tv;
	char lavanderia;
	char limpeza;
	char recepcao;
}tFlat;

typedef struct{
    tFlat info;
    char piscina;
    char sauna ;
    char academia;
}tStudio;

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
    tFlat flat;
    tStudio studio;
}tImovel;

tImovel imovel;
tImovel imovelPri;

int Menu();
void SubMenu();
void Cadastrar_Imoveis(FILE *imoveis);
void Cadastrar_Casa(FILE *imoveis);
void Cadastrar_Apartamento(FILE *imoveis);
void Cadastrar_Terreno(FILE *imoveis);
void Cadastrar_Flat_Studio(FILE *imoveis);



int main(){
    setlocale(LC_ALL, "");
    int escolha = 1;
    FILE *imoveis;
    imoveis = fopen("imobiliaria.dat", "a+b");
    
    if(!imoveis){
        printf("NAO CONSEGUIU ABRIR O ARQUIVO\n");
    }
    while(escolha){
        escolha  = Menu();
        SubMenu(escolha, imoveis);
        printf("Deseja terminar o programa ?\n"
               "1-Continuar programa;\n"
               "0-Terminar programa.\n");
        scanf("%d", &escolha);
        printf("\n");;
    }
    // fseek(imoveis, 0, SEEK_SET);
    // while(1){
    //     fread(&imovelPri, sizeof(tImovel), 1, imoveis);
    //     printf("Quantidade de metro quadrados costruidos:  %d\n", imovelPri.casa.areaConst);
    //     if(feof(imoveis)){
    //         break;
    //     }
    // }

    fclose(imoveis);
    return 0;
}




void Cadastrar_Imoveis(FILE *imoveis){
    printf("Insira as seguintes informacoes sobre o imovel:\n");
    printf("Insira o endereo do imovel: ");
    fgets(imovel.rua, Qt, stdin);
    printf("Insira o numero da casa: ");
    scanf("%d%*c", &imovel.numero);
    printf("Insira o bairro do imovel: ");
    fgets(imovel.bairro, Qt, stdin);
    printf("Insira o cep do imovel: ");
    fgets(imovel.cep, Qt, stdin);
    printf("Insira a cidade do imovel: ");
    fgets(imovel.cidade, Qt, stdin);
    printf("Qual o tipo do seu imovel:\n"
           "1-Casa\n"
           "2-Apartamento\n"
           "3-Terreno\n"
           "4-Flat\n"
           "5-Studio\n");
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
        case 4:
        case 5:
            Cadastrar_Flat_Studio(imoveis);
            break;
    
        default:
            printf("Esse tipo nao existe.");
    }

    fwrite(&imovel , sizeof(imovel),1, imoveis);
}


void Cadastrar_Casa(FILE *imoveis){
	//Inicializa tudo com 0
	imovel.casa.andares = imovel.casa.areaConst = imovel.casa.areaTer = imovel.casa.qtQuartos = 0;
	
	//Recebe do usuario todos os valores do imovel tipo Casa
    printf("Digite a quantidade de quartos da casa: ");
    scanf("%d", &imovel.casa.qtQuartos);
    printf("Digite a quantidade de andares: ");
    scanf("%d", &imovel.casa.andares);
    printf("Digite a area do terreno (metros quadrados): ");
    scanf("%d", &imovel.casa.areaTer);
    printf("Digite a area construida (metros quadrados): " );
    scanf("%d%*c", &imovel.casa.areaConst);
    
    //Verifica se a area construida e maior que a area do terreno
    if(imovel.casa.areaConst > imovel.casa.areaTer){
    	printf("\nArea construida nao pode ser maior que a area do terreno!\n\n");
    	Cadastrar_Casa(imoveis);
	}
    
    //Verifica se algum dos valores nao foi digitado
    if(imovel.casa.andares == 0){
    	printf("\nQuantidade de andares nao especificada!\n\n");
    	Cadastrar_Casa(imoveis);
	}else if(imovel.casa.areaConst == 0){
		printf("\nArea construida nao especificada!\n\n");
    	Cadastrar_Casa(imoveis);
	}else if(imovel.casa.areaTer == 0){
		printf("\nArea do terreno nao especificada!\n\n");
    	Cadastrar_Casa(imoveis);
	}else if(imovel.casa.qtQuartos == 0){
		printf("\nQuantidade de quartos n�o especificada!\n\n");
    	Cadastrar_Casa(imoveis);
	}
	
	puts("Cadastro concluido com sucesso!");	
}

void Cadastrar_Terreno(FILE *imoveis){
    //Inicializa tudo com 0
	imovel.ter.area = 0;
	
	//Recebe do usuario a area do terreno
    printf("Digite a quantiade de quartos da casa: ");
    scanf("%d", &imovel.ter.area);
    
    //Verifica se a area foi digitada
    if(imovel.ter.area == 0){
    	printf("\nArea nao digitada!\n\n");
    	Cadastrar_Casa(imoveis);
	}else
		puts("Cadastro concluido com sucesso!");
}

void Cadastrar_Apartamento(FILE *imoveis){
    //Inicializa tudo com 0
	imovel.ap.andar = imovel.ap.area = imovel.ap.qtGaragens = imovel.ap.qtQuartos = imovel.ap.condominio = 0;
	
	//Recebe do usuario todos os valores do imovel tipo Casa
    printf("Digite a quantiade de quartos do apartamento: ");
    scanf("%d", &imovel.ap.qtQuartos);
    printf("Digite o andar do apartamento: ");
    scanf("%d", &imovel.ap.andar);
    printf("Digite a area do apartamento (metros quadrados): ");
    scanf("%d", &imovel.ap.area);
    printf("Digite a quantidade de garagens: " );
    scanf("%d", &imovel.ap.qtGaragens);
    printf("Digite o valor do condominio: ");
    scanf("%lf", &imovel.ap.condominio);
    printf("Digite a posicao do apartamento: ");
    fgets(imovel.ap.posicao, Qt, stdin);
    getchar();
    
    //Verifica se algum dos valores nao foi digitado
    if(imovel.ap.andar == 0){
    	printf("\nQuantidade de andares nao especificada!\n\n");
    	Cadastrar_Apartamento(imoveis);
	}
	if(imovel.ap.area == 0){
		printf("\nArea construida nao especificada!\n\n");
    	Cadastrar_Apartamento(imoveis);
	}
	if(imovel.ap.qtGaragens == 0){
		printf("\nQuantidade de garagens nao especificada!\n\n");
    	Cadastrar_Apartamento(imoveis);
	}
	if(imovel.ap.qtQuartos == 0){
		printf("\nQuantidade de quartos n�o especificada!\n\n");
    	Cadastrar_Apartamento(imoveis);
	}
	if(imovel.ap.condominio == 0){
		printf("\nValor do condominio n�o especificada!\n\n");
    	Cadastrar_Apartamento(imoveis);
	}
	
	puts("Cadastro concluido com sucesso!");
}

void Cadastrar_Flat_Studio(FILE *imoveis){
	//Inicializa a area e o valor do condominio com 0
	imovel.flat.area = imovel.flat.condominio = 0;
	//Inicializa os valores char com 'x' para definir que nao houve resposta
	imovel.flat.ar = imovel.flat.ar = imovel.flat.internet = imovel.flat.lavanderia = imovel.flat.limpeza = imovel.flat.recepcao = imovel.flat.tv = 'x';
	
	//Recebe to usuario todas as informacoes do imovel tipo Flat
	printf("Digite a area do flat: ");
	scanf("%d", &imovel.flat.area);
	printf("O imovel tem arcondicionado (s/n)? ");
	scanf("%c%*c", &imovel.flat.ar);
	printf("O imovel tem internet (s/n)? ");
	scanf("%c%*c", &imovel.flat.internet);
	printf("O imovel tem TV a cabo (s/n)? ");
	scanf("%c%*c", &imovel.flat.tv);
	printf("O imovel tem lavanderia (s/n)? ");
	scanf("%c%*c", &imovel.flat.lavanderia);
	printf("O imovel tem servico de limpeza/arrumacao (s/n)? ");
	scanf("%c%*c", &imovel.flat.limpeza);
	printf("O imovel tem recepcao 24hrs (s/n)? ");
	scanf("%c%*c", &imovel.flat.recepcao);
	printf("Digite o valor do condominio: ");
	scanf("%lf", &imovel.flat.condominio);
	
    //Cadastra as informações extras do studio.
    if(imovel.tipo == 5){
        printf("O imovel tem piscina (s/n)? ");
	    scanf("%c%*c", &imovel.studio.piscina);
        printf("O imovel tem lavanderia (s/n)? ");
        scanf("%c%*c", &imovel.studio.sauna);
        printf("O imovel tem lavanderia (s/n)? ");
        scanf("%c%*c", &imovel.studio.academia);
    }
	
    //Verifica se alguma informacao esta faltando
	if(imovel.flat.area == 0){
    	printf("\nArea do imovel nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	if(imovel.flat.condominio == 0){
    	printf("\nValor do condominio nao especificado!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	if(imovel.flat.ar != 's' || imovel.flat.ar != 'n'){
    	printf("\nInformacao sobre o arcondicionado nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	if(imovel.flat.internet != 's' || imovel.flat.internet != 'n'){
    	printf("\nInformacao sobre a internet nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	if(imovel.flat.tv != 's' || imovel.flat.ar != 'n'){
    	printf("\nInformacao sobre a TV a cabo nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	if(imovel.flat.lavanderia != 's' || imovel.flat.lavanderia != 'n'){
    	printf("\nInformacao sobre a lavanderia nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	if(imovel.flat.limpeza != 's' || imovel.flat.limpeza != 'n'){
    	printf("\nInformacao sobre a limpeza nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	if(imovel.flat.recepcao != 's' || imovel.flat.recepcao != 'n'){
    	printf("\nInformacao sobre a recepcao nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imoveis);
	}
	
    puts("Cadastro concluido com sucesso!");
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

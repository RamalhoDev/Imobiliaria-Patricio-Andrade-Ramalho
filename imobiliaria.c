#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define Qt 60

typedef struct{
    int andar;
    int area;
    int qtQuartos;
    int qtGaragens;
    char posicao[Qt];
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
    double condominio;
    tApartamento ap;
    tCasa casa;
    tTerreno ter;
    tFlat flat;
    tStudio studio;
}tImovel;


int Menu();
void SubMenu();
void Cadastrar_Imoveis(tImovel imovel,FILE *imoveis);
void Cadastrar_Casa(tImovel imovel, FILE *imoveis);
void Cadastrar_Apartamento(tImovel imovel ,FILE *imoveis);
void Cadastrar_Terreno(tImovel imovel, FILE *imoveis);
void Cadastrar_Flat_Studio(tImovel imovel, FILE *imoveis);



void Consultar_Todos_Imoveis(tImovel imovel,FILE *imoveis);
void Consultar_Vender_Tipo(tImovel imovel ,FILE *imoveis);
void Consultar_Alugar_Tipo(tImovel imovel ,FILE *imoveis);
void Consultar_Vender_Bairro(tImovel imovel ,FILE *imoveis);
void Consultar_Alugar_Bairro(tImovel imovel ,FILE *imoveis);

void Consultar_Descricao_Todos_Imoveis(tImovel imovel ,FILE *imoveis);
void Consultar_Descricao_Cidade(tImovel imovel ,FILE *imoveis);

void STRING_MAIUSCULO(char frase[], size_t tamanho);

int main(){
    setlocale(LC_ALL, "");
    
    tImovel imovel;
    int escolha = 1;

    FILE *imoveis;
    imoveis = fopen("imobiliaria.dat", "a+b");
    
    if(!imoveis){
        printf("NAO CONSEGUIU ABRIR O ARQUIVO\n");
    }

    while(escolha){
        escolha  = Menu();
        SubMenu(imovel, escolha, imoveis);
        printf("Deseja terminar o programa ?\n"
               "1-Continuar programa\n"
               "0-Terminar programa\n"
               "Resposta: ");
        scanf("%d", &escolha);
        system("cls");
        system("clear");
        printf("\n");
        fseek(imoveis, 0 ,SEEK_SET);
    }

    fclose(imoveis);
    return 0;
}




void Cadastrar_Imoveis(tImovel imovel,FILE *imoveis){
    printf("Insira as seguintes informacoes sobre o imovel:\n");
    printf("Insira o endereo do imovel: ");
    fgets(imovel.rua, Qt, stdin);
    STRING_MAIUSCULO(imovel.rua, strlen(imovel.rua));
    printf("Insira o numero da casa: ");
    scanf("%d%*c", &imovel.numero);
    printf("Insira o bairro do imovel: ");
    fgets(imovel.bairro, Qt, stdin);
    STRING_MAIUSCULO(imovel.bairro, strlen(imovel.bairro));
    printf("Insira o cep do imovel: ");
    fgets(imovel.cep, Qt, stdin);
    STRING_MAIUSCULO(imovel.cep, strlen(imovel.cep));
    printf("Insira a cidade do imovel: ");
    fgets(imovel.cidade, Qt, stdin);
    STRING_MAIUSCULO(imovel.cidade, strlen(imovel.cidade));
    printf("Qual o tipo do seu imovel:\n"
           "1-Casa\n"
           "2-Apartamento\n"
           "3-Terreno\n"
           "4-Flat\n"
           "5-Studio\n");
    scanf("%d", &imovel.tipo);
    printf("Você deseja alugar ou vender o imóvel ?\n"
           "1-Vender\n"
           "2-Alugar\n"
           "Resposta:");
    scanf("%d", &imovel.transacao);
    printf("Preço do imóvel: R$ ");
    scanf("%lf", &imovel.valor);
    if(imovel.tipo == 2 || imovel.tipo == 4 || imovel.tipo == 5 ){
        printf("Preço do condomínio: R$ ");
        scanf("%lf", &imovel.condominio);
    }
    puts("");
    switch(imovel.tipo){
        case 1:
            Cadastrar_Casa(imovel ,imoveis);
            break;
        case 2:
            Cadastrar_Apartamento(imovel,imoveis);
            break;
        case 3:
            Cadastrar_Terreno(imovel,imoveis);
            break;
        case 4:
        case 5:
            Cadastrar_Flat_Studio(imovel,imoveis);
            break;
    
        default:
            printf("Esse tipo nao existe.");
    }

    fwrite(&imovel , sizeof(imovel),1, imoveis);
    //fseek(imoveis, 0, SEEK_SET);
}


void Cadastrar_Casa(tImovel imovel, FILE *imoveis){
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
    	Cadastrar_Casa(imovel,imoveis);
	}
    
    //Verifica se algum dos valores nao foi digitado
    if(imovel.casa.andares == 0){
    	printf("\nQuantidade de andares nao especificada!\n\n");
    	Cadastrar_Casa(imovel,imoveis);

	}else if(imovel.casa.areaConst == 0){
		printf("\nArea construida nao especificada!\n\n");
    	Cadastrar_Casa(imovel,imoveis);
	}else if(imovel.casa.areaTer == 0){
		printf("\nArea do terreno nao especificada!\n\n");
    	Cadastrar_Casa(imovel,imoveis);
	}else if(imovel.casa.qtQuartos == 0){
		printf("\nQuantidade de quartos n�o especificada!\n\n");
    	Cadastrar_Casa(imovel,imoveis);
	}
	
	puts("Cadastro concluido com sucesso!");	
}

void Cadastrar_Terreno(tImovel imovel,FILE *imoveis){
    //Inicializa tudo com 0
	imovel.ter.area = 0;
	
	//Recebe do usuario a area do terreno
    printf("Digite a quantiade de quartos da casa: ");
    scanf("%d", &imovel.ter.area);
    
    //Verifica se a area foi digitada
    if(imovel.ter.area == 0){
    	printf("\nArea nao digitada!\n\n");
    	Cadastrar_Terreno(imovel,imoveis);
	}else
		puts("Cadastro concluido com sucesso!");
}

void Cadastrar_Apartamento(tImovel imovel,FILE *imoveis){
    //Inicializa tudo com 0
	imovel.ap.andar = imovel.ap.area = imovel.ap.qtGaragens = imovel.ap.qtQuartos = 0;
	
	//Recebe do usuario todos os valores do imovel tipo Casa
    printf("Digite a quantiade de quartos do apartamento: ");
    scanf("%d", &imovel.ap.qtQuartos);
    printf("Digite o andar do apartamento: ");
    scanf("%d", &imovel.ap.andar);
    printf("Digite a area do apartamento (metros quadrados): ");
    scanf("%d", &imovel.ap.area);
    printf("Digite a quantidade de garagens: " );
    scanf("%d", &imovel.ap.qtGaragens);
    printf("Digite a posicao do apartamento: ");
    fgets(imovel.ap.posicao, Qt, stdin);
    STRING_MAIUSCULO(imovel.ap.posicao, strlen(imovel.ap.posicao));
    //Verifica se algum dos valores nao foi digitado
    if(imovel.ap.andar == 0){
    	printf("\nQuantidade de andares nao especificada!\n\n");
    	Cadastrar_Apartamento(imovel,imoveis);
	}
	if(imovel.ap.area == 0){
		printf("\nArea construida nao especificada!\n\n");
    	Cadastrar_Apartamento(imovel,imoveis);
	}
	if(imovel.ap.qtGaragens == 0){
		printf("\nQuantidade de garagens nao especificada!\n\n");
    	Cadastrar_Apartamento(imovel,imoveis);
	}
	if(imovel.ap.qtQuartos == 0){
		printf("\nQuantidade de quartos n�o especificada!\n\n");
    	Cadastrar_Apartamento(imovel,imoveis);
	}
	if(imovel.condominio == 0){
		printf("\nValor do condominio n�o especificada!\n\n");
    	Cadastrar_Apartamento(imovel,imoveis);
	}
	
	puts("Cadastro concluido com sucesso!");
}

void Cadastrar_Flat_Studio(tImovel imovel,FILE *imoveis){
	//Inicializa a area e o valor do condominio com 0
	imovel.flat.area = 0;
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
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	if(imovel.condominio == 0){
    	printf("\nValor do condominio nao especificado!\n\n");
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	if(imovel.flat.ar != 's' || imovel.flat.ar != 'n'){
    	printf("\nInformacao sobre o arcondicionado nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	if(imovel.flat.internet != 's' || imovel.flat.internet != 'n'){
    	printf("\nInformacao sobre a internet nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	if(imovel.flat.tv != 's' || imovel.flat.ar != 'n'){
    	printf("\nInformacao sobre a TV a cabo nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	if(imovel.flat.lavanderia != 's' || imovel.flat.lavanderia != 'n'){
    	printf("\nInformacao sobre a lavanderia nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	if(imovel.flat.limpeza != 's' || imovel.flat.limpeza != 'n'){
    	printf("\nInformacao sobre a limpeza nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	if(imovel.flat.recepcao != 's' || imovel.flat.recepcao != 'n'){
    	printf("\nInformacao sobre a recepcao nao especificada!\n\n");
    	Cadastrar_Flat_Studio(imovel,imoveis);
	}
	
    puts("Cadastro concluido com sucesso!");
}


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

void SubMenu(tImovel imovel,int indice, FILE *imoveis){
    int escolha, quantidade;
    
    switch(indice){
        case 1:
            Cadastrar_Imoveis(imovel,imoveis);
            break;
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
                    //Consultar_Descricao_Cidade(imovel, imoveis);
                    break;
                case 7:
                    //Consultar_Descricao_Todos_Imoveis(imovel, imoveis);
                    break;
            }
            break;
    }
}



void Consultar_Todos_Imoveis(tImovel imovel ,FILE *imoveis){
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
                
        printf("Imóvel %d da Rua: %s\n", imovel.numero, imovel.rua);
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
            printf("Imóvel %d da Rua: %s", imovel.numero, imovel.rua);
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
            printf("Imóvel %d da Rua: %s", imovel.numero, imovel.rua);
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
            
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        if(!strcmp(bairro2 ,imovel.bairro) && imovel.transacao == 1){
            printf("Imóvel %d da Rua: %s", imovel.numero, imovel.rua);
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
    
    while(fread(&imovel, sizeof(tImovel), 1, imoveis)){
        if(!strcmp(bairro2 ,imovel.bairro) && imovel.transacao == 2){
            printf("Imóvel %d da Rua: %s", imovel.numero, imovel.rua);
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
        if(!strcmp(cidade2 ,imovel.bairro) ){
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

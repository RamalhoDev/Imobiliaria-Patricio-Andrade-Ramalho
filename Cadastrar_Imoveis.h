#ifndef CADASTRAR_IMOVEIS_H
#define CADASTRAR_IMOVEIS_H
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
	char ar;
	char internet;
	char tv;
	char lavanderia;
	char limpeza;
	char recepcao;
    double condominio;
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

void Cadastrar_Imoveis(tImovel imovel,FILE *imoveis);
void Cadastrar_Casa(tImovel imovel,FILE *imoveis);
void Cadastrar_Apartamento(tImovel imovel, FILE *imoveis);
void Cadastrar_Terreno(tImovel imovel, FILE *imoveis);
void Cadastrar_Flat_Studio(tImovel imovel,FILE *imoveis);

#endif
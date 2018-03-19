#include "Cadastrar_Imoveis.c"
#define Qt 100


typedef struct{
    char rua[Qt];
    int numero;
    char bairro[Qt];
    char cep[Qt];
    char cidade[Qt];
}tImovel;

void Cadastrar_Imoveis();
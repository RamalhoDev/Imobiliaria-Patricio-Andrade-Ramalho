#include "Consulta_Imoveis.c"


void Consultar_Todos_Imoveis(tImovel imovel ,FILE *imoveis);
void Consultar_Vender_Tipo(tImovel imovel ,FILE *imoveis);
void Consultar_Alugar_Tipo(tImovel imovel ,FILE *imoveis);
void Consultar_Vender_Bairro(tImovel imovel ,FILE *imoveis);
void Consultar_Alugar_Bairro(tImovel imovel ,FILE *imoveis);
void Consultar_Descricao_Todos_Imoveis(tImovel imovel ,FILE *imoveis);
void Consultar_Descricao_Cidade(tImovel imovel ,FILE *imoveis);
void Consulta_Parcial_Casa(tImovel imovel);
void Consulta_Parcial_Apartamento(tImovel imovel);
void Consulta_Parcial_Terreno(tImovel imovel);
void Consulta_Parcial_Flat(tImovel imovel);
void Consulta_Parcial_Studio(tImovel imovel);
void STRING_MAIUSCULO(char frase[], size_t tamanho);

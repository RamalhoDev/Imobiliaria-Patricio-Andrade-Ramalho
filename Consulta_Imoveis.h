#ifndef CONSULTA_IMOVEIS_H
#define CONSULTA_IMOVEIS_H
#include "Cadastrar_Imoveis.h"

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
void Consultar_Descricao_Casa(tImovel imovel);
void Consultar_Descricao_Apartamento(tImovel imovel);
void Consultar_Descricao_Terreno(tImovel imovel);
void Consultar_Descricao_Flat(tImovel imovel);
void Consultar_Descricao_Studio(tImovel imovel);
void STRING_MAIUSCULO(char frase[], size_t tamanho);

#endif
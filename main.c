#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "estrutura.h"
#include "Cadastrar_Imoveis.h"
#include "Consulta_Imoveis.h"

int main(){
    //Define a linguagem do programa como Português
    setlocale(LC_ALL, "Portuguese");

    //Cria uma váriavel do tipo tImovel
    tImovel imovel;

    //Inicializa a variável escolha (Responsável por receber a escolha do usuário na função "Menu") com 1
    int escolha = 1;

    //Cria um ponteiro responsável por inicializar o uso de arquivos no programa
    FILE *imoveis;

    //Abre o arquivo binaŕio "imobiliaria.dat" que será usado para escrita e leitura (a+b)
    imoveis = fopen("imobiliaria.dat", "a+b");

    //Caso o arquivo não abra como deveria, a seguinte mensagem de erro será mostrada
    if(!imoveis){
        printf("NAO CONSEGUIU ABRIR O ARQUIVO\n");
    }

    //Laço de repetição responsável pela chamada das funções listadas no menu
    while(escolha){
        //A função "Menu" retorna um inteiro que representa a opção do usuário
        escolha  = Menu();

        //Executa a função de cadastro ou consulta de acordo com o segundo parâmetro (escolha)
        SubMenu(imovel , escolha, imoveis);
        printf("Deseja terminar o programa ?\n"
               "1-Continuar programa\n"
               "0-Terminar programa\n"
               "Resposta: ");
        scanf("%d", &escolha);
        system("cls");
        system("clear");
        printf("\n");
        //Deslocamento para o início do arquivo
        fseek(imoveis, 0 ,SEEK_SET);
    }

    //Fecha o arquivo aberto na linha 23
    fclose(imoveis);
    return 0;
}
//bibliotecas padrões
#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//arquivos do jogo
#include "funcao_nao_imp.h"
#include "personagem_atributos.h"
#include "sprites.h"
#include "funcoes.c"

//verica se é windows ou linux e passa para todos os arquivos que tem o #include "funcao_nao_imp.h"
//basicamente, é só colocar system(CLEAR)
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif


//main
int main(){
    
    setlocale (LC_ALL, "Portuguese");

    //passando dados para struct personagem.atributos
    inimigo_1[0].ataque = 1;
    inimigo_1[0].vida = 10;
    strcpy(inimigo_1[0].nome, "Dath");
    strcpy(inimigo_1[0].classe, "monstro");

    inimigo_1[1].ataque = 2;
    inimigo_1[1].vida = 10;
    strcpy(inimigo_1[1].nome, "Fangoroth");
    strcpy(inimigo_1[1].classe, "monstro");

    inimigo_1[2].ataque = 2;
    inimigo_1[2].vida = 15;
    strcpy(inimigo_1[2].nome, "Zephyrion");
    strcpy(inimigo_1[2].classe, "monstro");

    strcpy(inv[0].espadas_nome, "Espada de madeira");
    strcpy(inv[1].espadas_nome, "Espada de madeira refinada");
    strcpy(inv[2].espadas_nome, "Espada de cobre");
    strcpy(inv[3].espadas_nome, "Espada de ferro");

    strcpy(inv[0].escudo_nome, "Escudo de madeira");
    strcpy(inv[1].escudo_nome, "Escudo de madeira refinado");
    strcpy(inv[2].escudo_nome, "Escudo de cobre");
    strcpy(inv[3].escudo_nome, "Escudo de ferro");

    inv[0].escudo_valores = 1;
    inv[1].escudo_valores = 3;
    inv[2].escudo_valores = 5;
    inv[3].escudo_valores = 10;
    
    inv[0].espadas_valores = 1;
    inv[1].espadas_valores = 3;
    inv[2].espadas_valores = 5;
    inv[3].espadas_valores = 10;


    int lingua;
    //animation();
    //printf("%s", titulo_1);

    sleep(2);
    printf("\t\t\t|_________________________________________________|\n");
	printf("\t\t\t|                                                 |\n");
	printf("\t\t\t|             Selecione sua localidade            |\n");
	printf("\t\t\t|               Brasil  -  Digite: 1              |\n");
	printf("\t\t\t|              (SEGUNDA LOC em breve)             |\n");
	printf("\t\t\t|              (TERCEIRA LOC em breve)            |\n");
	printf("\t\t\t|_________________________________________________|\n");

    scanf("%d", &lingua);
    srand(time(NULL));
    switch (lingua)
    {
    case 1:
        cadastro(); //no arquivo funções
        break;
    case 2:
        //para testes DESENVOLVIMENTO: -- lembrar de remover ao dar o pull pro main
        
        strcpy(personagem_principal.nome, "dev");
        strcpy(personagem_principal.classe, "Humano");
        personagem_principal.vida=10;
        personagem_principal.ataque=5;

        verificador = 1; 
        invetario(); //coloquei zero pra iniciar no primeiro inimigo - só lembra de passar todos os parametros que a função utiliza
        
        break;

    default:
        main();
    }
    
}

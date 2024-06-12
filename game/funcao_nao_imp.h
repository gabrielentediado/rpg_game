#ifndef FUNCAO_NAO_IMP_H
#define FUNCAO_NAO_IMP_H

//para acessar os arquivos dessa path basta incluir #include "FUNCAO_NAO_IMP"

//espaço para declarar as funções

int dado(void);
int dado2(void);
void cadastro();
void quarto();
void sala();
void batalha(int x);
void morte();
void animation();

int menuNav; // variavel para navegacao entre menus
int dadoGerado; //variavel global para dados de 6 lados
int verificador=0; // essa variavel coloquei para ser um true/false, por exemplo na primeira parte, para ele conseguir andar precisa explorar a casa primeiro


//verica se é windows ou linux e passa para todos os arquivos que tem o #include "funcao_nao_imp.h"
//basicamente, é só colocar system(CLEAR)
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

//passei aqueles caracters para o sprites.h

#endif

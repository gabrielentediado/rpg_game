#ifndef FUNCAO_NAO_IMP_H
#define FUNCAO_NAO_IMP_H

//espaço para declarar as funções

int dado(void);

int cadastro();

int verificador=0; // essa variavel coloquei para ser um true/false, por exemplo na primeira parte, para ele conseguir andar precisa explorar a casa primeiro

//titulo
char titulo[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                       RPG                       |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n"; // titulo para deixar os menus bonitinhos

char combate[] = 
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n"
"\t\t\t|                                                 |\n"
"\t\t\t|  ATACAR - 1      FUGIR - 2      3 - DEFENDER    |\n"
"\t\t\t _________________________________________________\n";

int menuNav; // variavel para navegacao entre menus

#endif

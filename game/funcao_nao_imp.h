#ifndef FUNCAO_NAO_IMP_H
#define FUNCAO_NAO_IMP_H

//espaço para declarar as funções


int dado(void);
int dado2(void);
void cadastro();
int quarto();
void sala();
int batalha(int x);
void morte();
void animation();


//variavel global
int verificador=0; // essa variavel coloquei para ser um true/false, por exemplo na primeira parte, para ele conseguir andar precisa explorar a casa primeiro

//titulo
char titulo_1[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                     *RPG*                       |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";


char titulo_2[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                      *PG                        |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";
char titulo_3[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                     R*G                         |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";

char titulo_4[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                      RP*                        |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";


char combate[] = 
"\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n"
"\t\t|                                                 |\n"
"\t\t|  ATACAR - 1      FUGIR - 2      3 - DEFENDER    |\n"
"\t\t|___________________        ______________________|\n";

char mapa[] =
"\t\t\t ________________________________________________________\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t ________________________________________________________\n ";

int menuNav; // variavel global para navegacao entre menus

int dadoGerado; //variavel global para dados

#endif

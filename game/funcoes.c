//espaço para usar as fuções antes de serem implementadas no arquivo main.c

#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "funcao_nao_imp.h"
#include "personagem_atributos.h"


int dado(void){

    srand(time(NULL));

    return((rand() % 6) + 1);

}

//                _           _             
//               | |         | |            
//   ___ __ _  __| | __ _ ___| |_ _ __ ___  
//  / __/ _` |/ _` |/ _` / __| __| '__/ _ \ 
// | (_| (_| | (_| | (_| \__ \ |_| | | (_) |
//  \___\__,_|\__,_|\__,_|___/\__|_|  \___/ 
                                         
//main -> cadastro
int cadastro(){
    
    system("cls");

    int escolha;

    Personagem_atributos personagem_principal;

    puts("*Depois de uma longa noite, você finalmente acorda...\n");
    
    sleep(2);
    getchar();//limpar o buffer

    printf("Como deveriamos lhe chamar?\n");
    scanf("%19[^\n]s", &personagem_principal.nome);

    printf("Olá! %s \n", personagem_principal.nome);
    sleep(3);

    do
    {
        system("cls");

        printf("%s", titulo);
	    printf("\t\t\t|           Visualize as classes:                 |\n");
	    printf("\t\t\t|    1 - Para Mago                                |\n");
        printf("\t\t\t|    2 - Para Humano                              |\n");
        printf("\t\t\t|    3 - Para Elfo                                |\n");
        printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");
        
        scanf("%d", &menuNav);

        switch (menuNav)
        {
        case 1:
            
            printf("%s", titulo);
            printf("\t\t\t|                  MAGO                           |\n");
            printf("\t\t\t|    VIDA: 15HP                                   |\n");
            printf("\t\t\t|    DANO: 3HP                                    |\n");
            printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");

            printf("1 - Escolher \n2 - Sair\n");

            scanf("%d", &escolha);

            if (escolha == 1)
            {
                strcpy(personagem_principal.classe, "mago");

                personagem_principal.vida==15;
                personagem_principal.ataque==3;

                mundo();
                
            }
            

            break;

        case 2:

            printf("%s", titulo);
            printf("\t\t\t|                  HUMANO                         |\n");
            printf("\t\t\t|    VIDA: 9HP                                    |\n");
            printf("\t\t\t|    DANO: 6HP                                    |\n");
            printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");
             
            printf("1 - Escolher \n2 - Sair\n");
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                strcpy(personagem_principal.classe, "Humano");

                personagem_principal.vida==9;
                personagem_principal.ataque==6;

                mundo();
            }
            
            
            break;
        
        case 3:


            printf("%s", titulo);
            printf("\t\t\t|                  ELFO                           |\n");
            printf("\t\t\t|    VIDA: 10HP                                   |\n");
            printf("\t\t\t|    DANO: 4HP                                    |\n");
            printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");
             
            printf("1 - Escolher \n2 - Sair\n");

            scanf("%d", &escolha);
            

            if (escolha == 1)
            {
                strcpy(personagem_principal.classe, "Elfo");
                
                personagem_principal.vida==10;
                personagem_principal.ataque==4;

                mundo();
            }
            

            break;

        }

    }while(escolha != 1);
    

}

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

// quarto

int quarto(){

    
        if(verificador == 0){ // para entrar no quarto ele precisa entrar na sala primeiro

            puts("Você decide entrar no quarto, entretanto a porta esta trancada e não há formas de entrar\n\n");
            explorarCasa();

        } else {

            printf("O quarto esta escuro e abandonado, há restos de roupas pelo chão...\n");
            sleep(1);
            printf("Parece ter sido vasculhado por alguem recentemente...\n");
            sleep(1);
            puts("Em meio a bagunça, você observa alguns rasgos na parede. \n");
            sleep(1);
            puts("Na parde ao lado uma escrita em sangue feito a mão 'eles são reais' \n\n");
            sleep(1);
            puts("Logo abaixo um báu de madeira, você deseja abrir? \n");
            
            puts("1-para abrir\n2-para voltar");

            puts("\n\n*Você contará com sua sorte para conseguir ou não abrir o baú*"); //começar a usar o dado daqui depois da introdução

            scanf("%d", &menuNav);

            int dadoGerado = dado();


            if (menuNav == 1){

                // dado gerado


                Personagem_inventario inv;
                

                if(dadoGerado >= 4){
                    
                    sleep(1);
                    printf("valor da jogadada do dado : %d \n", dadoGerado); // mostra o valor do dado
                    
                    printf("Você empurra o baú, uma parte se solta e você pode conferir o que há dentro\n\n");
                    printf("Legal, você encontrou um pergaminho, item adicionado ao seu inventário\n");

                    inv.pergaminho = 1;

                    sleep(2);
                    printf("Acho que não há mais o que explorar, vamos sair da casa!");
                    opcoes();
                    
                } else {

                    sleep(1);
                    printf("valor da jogadada do dado : %d \n", dadoGerado); // mostra o valor do dado

                    printf("O baú está muito bem lacrado, infelizmente você não consegue abrir\n");
                    sleep(2);
                    printf("Acho que não há mais o que explorar, vamos sair da casa!");
                    opcoes();
                }

            } else {

            }


        }
        break;

}

//sala

void sala(){

    
        if(verificador == 0){ // verificar se ele ja entrou ou nao na sala
            printf("Você entra silenciosamente na sala principal.\n");
            sleep(1);

            //removi as funções sprites do código, falta ainda implementar os headers

            sleep(1);
            printf("O local está horrível, há pedaços de madeira podre em toda parte\n");
            sleep(1);
            printf("É possível ver algo brilhante refletindo em uma pequena mesa de centro\n");
            sleep(1);
            puts("Deseja verificar o que é?\n");
            printf("1 - Sim\n2 - Não\n");
            scanf("%d", &menuNav);
            
            if (menuNav == 1){
                puts("Você chega perto para ver, afasta um pouco os pedaçoes destroçados de madeira...\n");
                sleep(1);
                puts("É isso! Uma chave, com certeza é a chave que precisa para entrar no quarto\n");

                verificador = 1; // agora ele ja pode andar e entrar no quarto

                sleep(1);
                printf("Vamos voltar e explorar o quarto...\n");
                explorarCasa();

            }else{

                puts("Ah, melhor não ver o que é, devemos voltar!");
                sleep(1);
                opcoes();

            }
            
        }



}
    
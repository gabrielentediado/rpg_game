//bibliotecas padrões

#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//arquivos do jogo

#include "personagem_atributos.h"

#include "sprites.h"

#include "funcoes.c"


//titulo
char titulo[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                       RPG                       |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n"; // titulo para deixar os menus bonitinhos

int menuNav; // variavel para navegacao entre menus

int verificador=0; // essa variavel coloquei para ser um true/false, por exemplo na primeira parte, para ele conseguir andar precisa explorar a casa primeiro

//                            _       
//                           | |      
//  _ __ ___  _   _ _ __   __| | ___  
// | '_ ` _ \| | | | '_ \ / _` |/ _ \ 
// | | | | | | |_| | | | | (_| | (_) |
// |_| |_| |_|\__,_|_| |_|\__,_|\___/ 


//andar


void andar(){
    if(verificador == 0){
        getchar(); //buffer
        system("cls"); //limpa a tela
        printf("Bom, é melhor explorar a casa para procurar algo para me defender \n\n");
        sleep(3); //tava pasando direto para as opções
        opcoes();

    } else {
        printf("continuar daqui.");

        //inciar um evento aleatorio:
    }
}                 


// explorar Casa


void explorarCasa(){
    system("cls");
    puts("\n\n*Você decide explorar a casa...*");
    sleep(1);
    puts("Qual cômodo deseja explorar?");
    printf("1 - Quarto\n2 - Sala principal\n");
    scanf("%d", &menuNav);

    switch (menuNav)
    {

    //quarto
    case 1:
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
    //sala principal
    case 2:
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
    default:
        
        //para não parar a execução do jogo do nada
        sleep(1);
        explorarCasa();
    }


}
//main -> cadastro -> mundo
void mundo(){

    system("cls"); //limpa a tela
    
    //introdução:

    printf("*Você está em sua casa e enfim levanta...\n\n");
    sleep(1);
    printf("Você não se recorda de nada...\n");
    sleep(1);
    printf("Segue ao espelho, nada de especial\n");
    sleep(1);
    printf("Seu braço reflete, é possível ver uma mensagem...\n\n'Mate-os, liberte a alma' \n\n");
    sleep(1);
    puts("Você olha ao redor e não vê nada além de uma casa de madeira caindo aos pedaços\n");
    sleep(1);

    opcoes(); //chama as opções
    
}

//main -> cadastro -> mundo -> opções -> (andar ou explorar casa)

int  opcoes()
{
    puts("O que deseja fazer??");

    puts("1 - Andar \n2 - Explorar a casa\n");
    scanf("%d", &menuNav);
    switch (menuNav)
    {
    case 1:
        andar(); 
        break;
    case 2:
        explorarCasa();  // primeiro terá que explorar a casa
    default:
        opcoes(); 
        break;
    }
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

//                  _       
//                 (_)      
//  _ __ ___   __ _ _ _ __  
// | '_ ` _ \ / _` | | '_ \ 
// | | | | | | (_| | | | | |
// |_| |_| |_|\__,_|_|_| |_|
          
int main(){

    char lingua[10];
    printf("%s", titulo);
	printf("\t\t\t|                                                 |\n");
	printf("\t\t\t|             Selecione sua localidade            |\n");
	printf("\t\t\t|    Brasil  -  Digite: Portuguese                 |\n");
	printf("\t\t\t|    (SEGUNDA LOC)                                |\n");
	printf("\t\t\t|    (TERCEIRA LOC)                               |\n");
	printf("\t\t\t|_________________________________________________|\n");

    scanf("%s", &lingua);
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Personagem_atributos personagem_principal;

    if(strcmp(lingua, "pl") == 0){ // coloquei isso so pra pular o cadastro e agilizar o processo
        
        strcpy(personagem_principal.classe, "Humano");
        
        personagem_principal.vida==999;
        personagem_principal.ataque==999;
        verificador = 1;

        explorarCasa();

    } else {
        cadastro();
    }


  
}

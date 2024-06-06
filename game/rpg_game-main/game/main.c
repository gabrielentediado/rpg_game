//bibliotecas padr�es

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

int verificador=0; // essa variavel coloquei para ser um true/false, por exemplo na primeira parte, para ele conseguir andar precisa explorar a casa primeiro

//                            _       
//                           | |      
//  _ __ ___  _   _ _ __   __| | ___  
// | '_ ` _ \| | | | '_ \ / _` |/ _ \ 
// | | | | | | |_| | | | | (_| | (_) |
// |_| |_| |_|\__,_|_| |_|\__,_|\___/ 


//andar


void andar(){

    Personagem_atributos inimigo_1; 
    inimigo_1.ataque == 1;
    inimigo_1.vida == 10;
    inimigo_1.nome == "Bath";
    inimigo_1.classe == "Monstro";

    if(verificador == 0){
        getchar(); //buffer
        system("cls"); //limpa a tela
        printf("Bom, � melhor explorar a casa para procurar algo para me defender \n\n");
        sleep(3); //tava pasando direto para as op��es
        opcoes();

    } else {
        printf("continuar daqui.");

        sleep(1);

        puts("vamos dar uma passo para frente ");
        puts("digite 1 para jogar o dado e 2 para ");

        //inciar um evento aleatorio:
    }
}                 


// explorar Casa


void explorarCasa(){
    system("cls");
    puts("\n\n*Voc� decide explorar a casa...*");
    sleep(1);
    puts("Qual c�modo deseja explorar?");
    printf("1 - Quarto\n2 - Sala principal\n");
    scanf("%d", &menuNav);

    switch (menuNav)
    {

    //quarto
    case 1:
        if(verificador == 0){ // para entrar no quarto ele precisa entrar na sala primeiro

            puts("Voc� decide entrar no quarto, entretanto a porta esta trancada e n�o h� formas de entrar\n\n");
            explorarCasa();

        } else {

            printf("O quarto esta escuro e abandonado, h� restos de roupas pelo ch�o...\n");
            sleep(1);
            printf("Parece ter sido vasculhado por alguem recentemente...\n");
            sleep(1);
            puts("Em meio a bagun�a, voc� observa alguns rasgos na parede. \n");
            sleep(1);
            puts("Na parde ao lado uma escrita em sangue feito a m�o 'eles s�o reais' \n\n");
            sleep(1);
            puts("Logo abaixo um b�u de madeira, voc� deseja abrir? \n");
            
            puts("1-para abrir\n2-para voltar");

            puts("\n\n*Voc� contar� com sua sorte para conseguir ou n�o abrir o ba�*"); //come�ar a usar o dado daqui depois da introdu��o

            scanf("%d", &menuNav);

            int dadoGerado = dado();


            if (menuNav == 1){

                // dado gerado


                Personagem_inventario inv;
                

                if(dadoGerado >= 4){
                    
                    sleep(1);
                    printf("valor da jogadada do dado : %d \n", dadoGerado); // mostra o valor do dado
                    
                    printf("Voc� empurra o ba�, uma parte se solta e voc� pode conferir o que h� dentro\n\n");
                    printf("Legal, voc� encontrou um pergaminho, item adicionado ao seu invent�rio\n");

                    inv.pergaminho = 1;

                    sleep(2);
                    printf("Acho que n�o h� mais o que explorar, vamos sair da casa!");
                    opcoes();
                    
                } else {

                    sleep(1);
                    printf("valor da jogadada do dado : %d \n", dadoGerado); // mostra o valor do dado

                    printf("O ba� est� muito bem lacrado, infelizmente voc� n�o consegue abrir\n");
                    sleep(2);
                    printf("Acho que n�o h� mais o que explorar, vamos sair da casa!");
                    opcoes();
                }

            } else {

            }


        }
        break;
    //sala principal
    case 2:
        if(verificador == 0){ // verificar se ele ja entrou ou nao na sala
            printf("Voc� entra silenciosamente na sala principal.\n");
            sleep(1);

            //removi as fun��es sprites do c�digo, falta ainda implementar os headers

            sleep(1);
            printf("O local est� horr�vel, h� peda�os de madeira podre em toda parte\n");
            sleep(1);
            printf("� poss�vel ver algo brilhante refletindo em uma pequena mesa de centro\n");
            sleep(1);
            puts("Deseja verificar o que �?\n");
            printf("1 - Sim\n2 - N�o\n");
            scanf("%d", &menuNav);
            if (menuNav == 1){
                puts("Voc� chega perto para ver, afasta um pouco os peda�oes destro�ados de madeira...\n");
                sleep(1);
                puts("� isso! Uma chave, com certeza � a chave que precisa para entrar no quarto\n");

                verificador = 1; // agora ele ja pode andar e entrar no quarto

                sleep(1);
                printf("Vamos voltar e explorar o quarto...\n");
                explorarCasa();

            }else{

                puts("Ah, melhor n�o ver o que �, devemos voltar!");
                sleep(1);
                opcoes();

            }
            
        }
    default:
        
        //para n�o parar a execu��o do jogo do nada
        sleep(1);
        explorarCasa();
    }


}
//main -> cadastro -> mundo
void mundo(){

    system("cls"); //limpa a tela
    
    //introdu��o:

    printf("*Voc� est� em sua casa e enfim levanta...\n\n");
    sleep(1);
    printf("Voc� n�o se recorda de nada...\n");
    sleep(1);
    printf("Segue ao espelho, nada de especial\n");
    sleep(1);
    printf("Seu bra�o reflete, � poss�vel ver uma mensagem...\n\n'Mate-os, liberte a alma' \n\n");
    sleep(1);
    puts("Voc� olha ao redor e n�o v� nada al�m de uma casa de madeira caindo aos peda�os\n");
    sleep(1);

    opcoes(); //chama as op��es
    
}

//main -> cadastro -> mundo -> op��es -> (andar ou explorar casa)

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
        explorarCasa();  // primeiro ter� que explorar a casa
    default:
        opcoes(); 
        break;
    }
}


//                  _       
//                 (_)      
//  _ __ ___   __ _ _ _ __  
// | '_ ` _ \ / _` | | '_ \ 
// | | | | | | (_| | | | | |
// |_| |_| |_|\__,_|_|_| |_|
          
int main(){
    
    setlocale (LC_ALL, "Portuguese");

    int lingua;

    printf("%s", titulo);
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

    Personagem_atributos personagem_principal;


    switch (lingua)
    {
    case 1:
        
        cadastro();
        break;
    case 2:
        //para testes
        
        strcpy(personagem_principal.classe, "Humano");
        personagem_principal.vida==999;
        personagem_principal.ataque==999;
        verificador = 1;

        explorarCasa();

    default:
        main();
    }
  
}

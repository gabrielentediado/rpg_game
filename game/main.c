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

//                            _       
//                           | |      
//  _ __ ___  _   _ _ __   __| | ___  
// | '_ ` _ \| | | | '_ \ / _` |/ _ \ 
// | | | | | | |_| | | | | (_| | (_) |
// |_| |_| |_|\__,_|_| |_|\__,_|\___/ 


//andar


void andar(){

    inimigo_1.ataque = 1;
    inimigo_1.vida = 10;
    inimigo_1.nome == "Dath";
    inimigo_1.classe == "Monstro";

    if(verificador == 0){
        getchar(); //buffer
        system("cls"); //limpa a tela
        printf("Bom, é melhor explorar a casa para procurar algo para me defender \n\n");
        sleep(10); //tava pasando direto para as opções
        opcoes();

    } 
    else{
        printf("continuar daqui.");

        printf("Jogue o dado para dar um passo adiante \n");
        printf("aparte 1 para jogar o dado ou 2 para ir sem a sorte \n");
        scanf("%d", &menuNav);

        switch (menuNav)
        {
        case 1:
            dado();
            break;
        
        case 2:
            //testando o combate

            printf("%s tenta dar uma passo, mas do escuro aparece algo, um mostro vindo em sua direção \n", personagem_principal.nome);
            sleep(1);
            printf("%s \n", combate);


            break;
        }
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

    switch (menuNav){

    case 1:
    //quarto
    quarto();
    break;

    case 2:
    //sala
    sala(); //entrar na sala primeiro e depois no quarto
    break; //tinha apagado os breaks sem querer ao passar as funções

    //coloquei as opções
    case 3:
    opcoes();
    
    default:
        
    //para não parar a execução do jogo do nada
    explorarCasa();

    break; //tinha apagado os breaks sem querer ao passar as funções

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
    sleep(10);

    opcoes(); //chama as opções
    
}

//main -> cadastro -> mundo -> opções -> (andar ou explorar casa)

int  opcoes()
{
    system("cls");

    puts("Menu: ");

    puts("O que deseja fazer??");

    puts("1 - Andar \n2 - Explorar a casa\n");
    scanf("%d", &menuNav);
    switch (menuNav)
    {
    case 1:
        andar(); //no arquivo funções
        break;
    case 2:
        explorarCasa();  // primeiro terá que explorar a casa (no arquivo funções)
        break; //tinha apagado os breaks sem querer ao passar as funções
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
    switch (lingua)
    {
    case 1:
        cadastro(); //no arquivo funções
        break;
    case 2:
        //para testes
        
        strcpy(personagem_principal.classe, "Humano");
        personagem_principal.vida=999;
        personagem_principal.ataque=999;

        verificador = 1;

        andar();

    default:
        main();
    }
  
}

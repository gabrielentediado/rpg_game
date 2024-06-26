

//bibliotecas padrões
#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//teste

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


//andar 

//quando, o inimigo morrer ou o personagem fugir incrementa em 1 o x e esse valor passa o i e o prt recebe o local da varievel.
void andar(int i) //andar com o dado, dar um passo ou batalhar, por equanto
{

    dadoGerado = dado(); 

    int *prt = &i; 
    //tranformei os inimigos em vetores, para possibilitar colocar vários inimigos, pensei em fazer com os ponteiros também
    inimigo_1[*prt].ataque;
    inimigo_1[*prt].vida;
    inimigo_1[*prt].nome;
    inimigo_1[*prt].classe;
    

    //teste: 

    //coloquei mais 2 para testar,
    //se quisermos futaramente colocar, tipo: ele anda x vezes e ganha ou anda x vezes e descobre um local novo
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

    
    if(verificador == 0){
        getchar(); //buffer
        system(CLEAR); //limpa a tela
        printf("Bom, é melhor explorar a casa para procurar algo para me defender \n\n");
        sleep(10); //tava pasando direto para as opções
        opcoes();

    } 
    else{
        printf("continuar daqui. \n");
        //se quiserem colocar a opção de poder voltar pro menu vai ter que mexer no código, se ele conseguir voltar quebra, pois tá passando 0 ao chamar o andar(0); no menu
        printf("Jogue o dado para dar um passo adiante \n");
        printf("\n*aperte 1 para jogar o dado* \n*2 para ir sem a sorte*\n");
        scanf("%d", &menuNav);

        switch (menuNav)
        {
        case 1:

            if (dadoGerado > 4 && i <= 2){
                printf("dado gerado: %d\n", dadoGerado);
                printf("Parece que o caminho está limpo \n vamo continuar");
                *prt++;
                andar(*prt);
                sleep(5);
            }else if(dadoGerado < 4 && i <= 2){
                printf("dado gerado: %d\n", dadoGerado);
                printf("tenta dar uma passo, mas do escuro aparece algo, um %s vindo em sua direção \n", inimigo_1[i].classe);
                sleep(10);
                batalha(i); //o valor de i passa para a função batalha(int x) e permite identificar o inimigo
            }else{
                printf("o jogo acabou por equando, aguarde novos updates  \n");
            }

            break;  
        case 2:
            printf("Por sua coragem ganhara 1 ponto de ataque e um 1 de vida \n");
            personagem_principal.ataque++;
            personagem_principal.vida++;
            sleep(5);
            if (i <= 2)
            {
                printf("tenta dar uma passo, mas do escuro aparece algo, um %s vindo em sua direção \n", inimigo_1[i].classe);
                batalha(i); //o valor de i passa para a função batalha(int x) e permite identificar o inimigo

            }else{
                printf("o jogo acabou por equando, aguarde novos updates  \n");
            }
            
            break;

        }
    }
}                 


// explorar Casa
void explorarCasa(){

    system(CLEAR);
    puts("\n\n*Você decide explorar a casa...*");
    sleep(1);
    puts("Qual lugar da casa deseja explorar? \n");
    printf("\n1 - Quarto\n2 - Sala principal \n3 - Voltar para o menu\n");
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
        break;

    default:
        
        //para não parar a execução do jogo do nada
        explorarCasa();

        break; //tinha apagado os breaks sem querer ao passar as funções

    }

}


//                            _       
//                           | |      
//  _ __ ___  _   _ _ __   __| | ___  
// | '_ ` _ \| | | | '_ \ / _` |/ _ \ 
// | | | | | | |_| | | | | (_| | (_) |
// |_| |_| |_|\__,_|_| |_|\__,_|\___/ 


//main -> cadastro -> mundo
void mundo(){
    

    sleep(8);
    system(CLEAR); //limpa a tela

    //testagem:
    printf("%s\n", personagem_principal.nome);
    printf("%d\n", personagem_principal.vida); 
    printf("%s", personagem_principal.classe);

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

int  opcoes(){

    system(CLEAR);
    puts("\n\nMenu: ");
    puts("O que deseja fazer??");
    puts("1 - Andar \n2 - Explorar a casa\n");
    scanf("%d", &menuNav);
    switch (menuNav)
    {
    case 1:
        andar(0); //depois de ter explorado a casa ele pode andar
        break;
    case 2:
        if (inv.pergaminho == 1) // para evitar de ficar explorando a casa
        {
            printf("a casa já foi explorada, vamos sair \n");
            sleep(10);
            opcoes();
        }else{

            explorarCasa();   // primeiro terá que explorar a casa (no arquivo funções)
        }

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
    animation();
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
	    
    default:
        main();
    }
    
}

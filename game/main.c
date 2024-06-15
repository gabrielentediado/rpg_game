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


//andar 

//quando, o inimigo morrer ou o personagem fugir incrementa em 1 o x e esse valor passa o i e o prt recebe o local da varievel.
void andar(int i) //andar com o dado, dar um passo ou batalhar, por equanto
{

    dadoGerado = dado(); 

    //tranformei os inimigos em vetores, para possibilitar colocar vários inimigos, pensei em fazer com os ponteiros também
    inimigo_1[i].ataque;
    inimigo_1[i].vida;
    inimigo_1[i].nome;
    inimigo_1[i].classe;

    int quantidade_inimigos = 2; 

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

            if (dadoGerado > 4 && i <= quantidade_inimigos){
                printf("dado gerado: %d\n", dadoGerado);
                printf("Parece que o caminho está limpo \n vamo continuar");
                i++;
                andar(i);
                sleep(5);
            }else if(dadoGerado < 4 && i <= quantidade_inimigos){
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
            if (i <= quantidade_inimigos)
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
        if (inv[0].pergaminho_verificador == 1) // para evitar de ficar explorando a casa
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

//main
int main(){

    setlocale (LC_ALL, "Portuguese");
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
        andar(0); //coloquei zero pra iniciar no primeiro inimigo - só lembra de passar todos os parametros que a função utiliza
        
        break;

    default:
        main();
    }
    
}

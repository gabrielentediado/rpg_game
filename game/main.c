
 //jogo de rpg

#include <stdio.h>
#include <time.h>
#include <unistd.h> //biblioteca para delay (sleep)
#include <locale.h>
#include <stdlib.h>
#include <string.h>

char titulo[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                       RPG                       |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n"; // titulo para deixar os menus bonitinhos
int menuNav; // variavel para navegacao entre menus
int verificador; // essa variavel coloquei para ser um true/false, por exemplo na primeira parte, para ele conseguir andar precisa explorar a casa primeiro

typedef struct //estrura para colocar as informaçoes do jogador e também de inimigos
{
    
    char nome[20];
    
    char classe[20];

    int vida[10];


}Personagem_atributos;


//      _           _       
//     | |         | |      
//   __| | __ _  __| | ___  
//  / _` |/ _` |/ _` |/ _ \ 
// | (_| | (_| | (_| | (_) |
//  \__,_|\__,_|\__,_|\___/ 
                         
                         

int dado_6_lados(int jogada){

    //soma quantas vezes o jogador jogou o dado : 

    int total=0;

    for (int i = 0; i < jogada; i++)
    {
        total = total + rand() % 6 + 1;
    }
    
    return total; //retona um valor que podera ser usado como um ataque ou outra coisa
}

//                 _ _       
//                (_) |      
//  ___ _ __  _ __ _| |_ ___ 
// / __| '_ \| '__| | __/ _ \
// \__ \ |_) | |  | | ||  __/
// |___/ .__/|_|  |_|\__\___|
//     | |                   
//     |_|                   


int sprite_1(){

    printf("\n.....\n"); //teste de sprite

}

//                            _       
//                           | |      
//  _ __ ___  _   _ _ __   __| | ___  
// | '_ ` _ \| | | | '_ \ / _` |/ _ \ 
// | | | | | | |_| | | | | (_| | (_) |
// |_| |_| |_|\__,_|_| |_|\__,_|\___/ 
                                   
void andar(){
    if(verificador == 0){
        system("cls"); //limpa a tela
        printf("Bom, é melhor procurar algo para me defender antes de explorar\n\n");
        opcoes();
    } else {
        printf("continuar daqui.");
    }


}                                   

void explorarCasa(){

    puts("\n\n*Você decide explorar a casa...*");
    sleep(1);
    puts("Qual cômodo deseja explorar?");
    printf("1 - Quarto\n2 - Sala principal\n");
    scanf("%d", &menuNav);
    switch (menuNav)
    {
    case 1:
        if(verificador == 0){ // para entrar no quarto ele precisa entrar na sala primeiro
            puts("Você decide entrar no quarto, entretanto a porta esta trancada e não há formas de entrar\n\n");
            explorarCasa();
        } else {
            printf("O quarto esta escuro e abandonado, há restos de roupas pelo chão...\n");
            sleep(1);
            printf("Parece ter sido vasculhado por alguem recentemente...\n");
            sleep(1);
        }
        break;
    case 2:
        if(verificador == 0){ // verificar se ele ja entrou ou nao na sala
            printf("Você entra silenciosamente na sala principal.\n");
            sleep(1);
            sprite_1();
            sleep(1);
            printf("O local está horrível, há pedaços de madeira podre em toda parte\n");
            sleep(1);
            printf("É possível ver algo brilhante refletindo em uma pequena mesa de centro\n");
            sleep(1);
            puts("Deseja verificar o que é?\n");
            printf("1 - Sim\n2 - Não");
            scanf("%d", &menuNav);
            if (menuNav == 1){
                puts("Você chega perto para ver, afasta um pouco os pedaçoes destroçados de madeira...\n");
                sleep(1);
                puts("É isso! Uma chave, com certeza é a chave que precisa para entrar no quarto\n");
                verificador = 1; // agora ele ja pode andar e entrar no quarto
                sleep(1);
                printf("Vamos voltar e explorar o quarto...\n");
                explorarCasa();

            } else {
                puts("Ah, melhor não ver o que é, devemos voltar!");
                opcoes();
            }
            
        }
    default:
        break;
    }


}

void mundo(){

    system("cls"); //limpa a tela

    printf("*Você está em sua casa e enfim levanta...\n\n");
    sleep(1);
    printf("Você não se recorda de nada...\n");
    sleep(1);
    printf("Segue ao espelho, nada de especial\n");
    sleep(1);

    sprite_1();

    printf("Seu braço reflete, é possível ver uma mensagem...\n\n'Mate-os, liberte a alma' \n\n");
    sleep(1);
    puts("Você olha ao redor e não vê nada além de uma casa de madeira caindo aos pedaços\n");
    sleep(1);
    opcoes();
    
}

void opcoes()
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
        explorarCasa();
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
                                         
                                         

int cadastro(){
    
    system("cls");

    int n, escolha;

    Personagem_atributos personagem;

    puts("*Depois de uma longa noite, você finalmente acorda...\n");
    
    sleep(2);
    getchar();
    printf("Como deveriamos lhe chamar?\n");
    scanf("%19[^\n]s", &personagem.nome);

    printf("Olá! %s \n", personagem.nome);
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
        

        scanf("%d", &n);

        switch (n)
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
                strcpy(personagem.classe, "mago");
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
                strcpy(personagem.classe, "Humano");
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
                strcpy(personagem.classe, "Elfo");
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
	printf("\t\t\t|    Brasil  -  Digite: portugues                 |\n");
	printf("\t\t\t|    (SEGUNDA LOC)                                |\n");
	printf("\t\t\t|    (TERCEIRA LOC)                               |\n");
	printf("\t\t\t|_________________________________________________|\n");

    scanf("%s", &lingua);
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    Personagem_atributos personagem;
    if(strcmp(lingua, "pl") == 0){ // coloquei isso so pra pular o cadastro e agilizar o processo
        strcpy(personagem.classe, "Humano");
        mundo();
    } else {
        cadastro();
    }


  
}

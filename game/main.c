
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

    printf("....."); //teste de sprite

}

//                            _       
//                           | |      
//  _ __ ___  _   _ _ __   __| | ___  
// | '_ ` _ \| | | | '_ \ / _` |/ _ \ 
// | | | | | | |_| | | | | (_| | (_) |
// |_| |_| |_|\__,_|_| |_|\__,_|\___/ 
                                   
                                   


void mundo(){

    system("cls"); //limpa a tela

    printf("Você está em sua casa e, por fim, levanta\n");
    sleep(1);
    printf("infelizmente, você não se recorda de nada.\n");
    printf("você olha no espelho e não há nada especial.\n");
    sleep(1);

    sprite_1();

    printf("mas em seu braço há uma marca escrita: 'Mate-os, liberte a alma' \n");
    sleep(1);
    puts("você olha ao redor e não vê nada além de uma casa de madeira caindo aos pedaços");

    puts("o que você faz agora?");
    puts("1 - andar \n 2 - desistir");
    
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

    setlocale(LC_ALL, lingua);
    srand(time(NULL));

    cadastro();
  
}

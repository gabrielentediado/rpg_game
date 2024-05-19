 //jogo de rpg

#include <stdio.h>
#include <time.h>
#include <unistd.h> //biblioteca para delay (sleep)
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct //estrura para colocar as informaçoes do jogador e também de inimigos
{
    
    char nome[20];
    
    char classe[20];

    int vida[10];

}Personagem_atributos;



int dado_6_lados(int jogada){

    //soma quantas vezes o jogador jogou o dado : 

    int total=0;

    for (int i = 0; i < jogada; i++)
    {
        total = total + rand() % 6 + 1;
    }
    
    return total; //retona um valor que podera ser usado como um ataque ou outra coisa
}

int sprite_1(){

    printf("....."); //teste de sprite

}

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

int cadastro(){
    
    system("cls");

    int n, escolha;

    Personagem_atributos personagem;

    printf("Depois de uma longa noite \n");
    
    sleep(2);

    puts("você finalmente acorda ");
    
    getchar();

    printf("qual o seu nome? ");
    scanf("%19[^\n]s", &personagem.nome);

    printf("Olá! %s \n", personagem.nome);
    sleep(3);


    do
    {
        system("cls");

        puts("vizualize as classes \n 1 - para mago \n 2 - para Humano \n 3 - para elfo");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            
            puts("Mago \n Vida: 15 \n Dano: 3 \n ");

            printf("1 - escolher \n2 - sair\n");

            scanf("%d", &escolha);

            if (escolha == 1)
            {
                strcpy(personagem.classe, "mago");
                
            }
            

            break;

        case 2:

            puts("Humano \n Vida: 9 \n Dano: 6 \n  ");
             
            printf("1 - escolher \n2 - sair\n");
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                strcpy(personagem.classe, "Humano");
            }
            
            
            break;
        
        case 3:

            puts("Elfo \n vida: 10 \n Dano: 4 ");
             
            printf("1 - escolher \n2 - sair\n");

            scanf("%d", &escolha);
            

            if (escolha == 1)
            {
                strcpy(personagem.classe, "Elfo");
            }
            

            break;

        }

    }while(escolha != 1);
    

}

int main(){

    char lingua[10];
    printf("selecione a sua localidade: \n Brasil - Digite: 'portugues' \n" );
    scanf("%s", &lingua);

    setlocale(LC_ALL, lingua);
    srand(time(NULL));

    cadastro();
  
}

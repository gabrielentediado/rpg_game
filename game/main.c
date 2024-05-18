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
    
    char *classe;

    int vida[10];

}Personagem_atributos;



int dado_6_lados(int jogada){

    //soma quantas vezes o jogador jogou o dado : 

    int total;

    for (int i = 0; i < jogada; i++)
    {
        total = total + rand() % 6 + 1;
    }
    
    return total; //retona um valor que podera ser usado como um ataque ou outra coisa
}


int cadastro(){
    
    system("cls");

    int n, escolha;

    Personagem_atributos personagem;

    printf("Depois de uma longa noite pacata \n");
    
    sleep(2);

    puts("você finalmente acorda ");
    
    printf("qual o seu nome? ");
    scanf("%19[^\n]s", &personagem.nome);

    printf("Olá! %s \n", personagem.nome);

    do
    {
  

        puts("vizualize as classes \n 1 - para mago \n 2 - para cyborgue \n 3 - elfo");
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

            puts("Cyborgue \n Vida: 16 \n Dano: 2 \n  ");
             
            printf("1 - escolher \n2 - sair\n");
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                strcpy(personagem.classe, "Cyborgue");
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
    
    return mundo();

}

int main(){

    char lingua[10];
    printf("selecione a sua localidade: \n Brasil - Digite: 'portugues' \n" );
    scanf("%s", &lingua);

    setlocale(LC_ALL, lingua);
    srand(time(NULL));

    return cadastro();
}
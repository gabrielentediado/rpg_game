// arquivo: PERSONAGEM_ATRIBUTOS_H

//removi a struct atributo e coloquei aqui

#ifndef PERSONAGEM_ATRIBUTOS_H
#define PERSONAGEM_ATRIBUTOS_H

typedef struct //estrura para colocar as informaçoes do jogador e também de inimigos
{
    
    char nome[20];
    
    char classe[20];

    int vida[10];

    int ataque[10]; //coloquei o dano para ser usado

}Personagem_atributos;

#endif // MINHA_STRUCT_H
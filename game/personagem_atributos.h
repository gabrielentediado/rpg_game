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



// inventario do jogador, usei numeros para verificar se ele tem ou não, exemplo o primeiro pergaminho é 1, então quando for para usar
// so precisa verificar se o pergaminho que ele tem é o 1, 2,3 e etc, mesma coisa com outros itens. No caso de espadas é melhor aumentar direto
// o ataque do personagem dele

typedef struct 
{
    int pergaminho;

}Personagem_inventario;





#endif // MINHA_STRUCT_H

// arquivo: PERSONAGEM_ATRIBUTOS_H

//removi a struct atributo e coloquei aqui

#ifndef PERSONAGEM_ATRIBUTOS_H
#define PERSONAGEM_ATRIBUTOS_H

typedef struct //estrura para colocar as informaçoes do jogador e também de inimigos
{
    
    char nome[20];
    
    char classe[20];

    int vida;

    int ataque; 

}Personagem_atributos;

Personagem_atributos personagem_principal; //passei pra uma varievel global

Personagem_atributos inimigo_1[10]; //inimigo 1 

// inventario do jogador, usei numeros para verificar se ele tem ou não, exemplo o primeiro pergaminho é 1, então quando for para usar
// so precisa verificar se o pergaminho que ele tem é o 1, 2,3 e etc, mesma coisa com outros itens. No caso de espadas é melhor aumentar direto
// o ataque do personagem dele

typedef struct 
{
    int pergaminho;

}Personagem_inventario;

Personagem_inventario inv;




#endif // MINHA_STRUCT_H

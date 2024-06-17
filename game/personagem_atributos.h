// arquivo: PERSONAGEM_ATRIBUTOS_H
//para acessar os arquivos dessa path basta incluir #include "funcoes.c"
//removi a struct atributo e coloquei aqui

#ifndef PERSONAGEM_ATRIBUTOS_H
#define PERSONAGEM_ATRIBUTOS_H

#define MAX 15

// inventario do jogador, usei numeros para verificar se ele tem ou não, exemplo o primeiro pergaminho é 1, então quando for para usar
// so precisa verificar se o pergaminho que ele tem é o 1, 2,3 e etc, mesma coisa com outros itens. No caso de espadas é melhor aumentar direto
// o ataque do personagem dele

typedef struct 
{
    int pergaminho_verificador;
    char pergaminho_nome[15];

    int espadas_verificador;
    int quantidade_espadas;
    int espadas_valores;
    char espadas_nome[15];

    int quantidade_escudos;
    int escudo_valores;
    char escudo_nome[15];

}inventario;

inventario inv[MAX];

typedef struct //estrura para colocar as informaçoes do jogador e também de inimigos
{
    char nome[20];
    char classe[20];
    int vida;
    int ataque;

    inventario Personagem_inventario;

}Personagem_atributos;

Personagem_atributos personagem_principal; //passei pra uma varievel global

Personagem_atributos personagem_principal_itens[MAX]; 

Personagem_atributos inimigo_1[10]; //inimigos, por equanto o máximo de inimigos é 10, mas pode aumentar se quiser


#endif // MINHA_STRUCT_H

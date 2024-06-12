#include "sprites.h"

// Função para criar um novo sprite
Sprite* criar_sprite(int largura, int altura, char** dados) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));
    sprite->largura = largura;
    sprite->altura = altura;
    sprite->dados = dados;
    return sprite;
}
// Função para destruir um sprite
void destruir_sprite(Sprite* sprite) {
    free(sprite);
}


void sprite(){

     // Criar um sprite
    char* dados[] = {
        "####",
        "#  #",
        "####"
    };
    Sprite* sprite = criar_sprite(4, 3, dados);

    // Usar o sprite...
    // ...

    // Destruir o sprite quando terminar
    destruir_sprite(sprite);

    return 0;
}


//                 _ _       
//                (_) |      
//  ___ _ __  _ __ _| |_ ___ 
// / __| '_ \| '__| | __/ _ \
// \__ \ |_) | |  | | ||  __/
// |___/ .__/|_|  |_|\__\___|
//     | |                   
//     |_|                   

#ifndef SPRITE_H
#define SPRITE_H



// Estrutura para um sprite de personagem

typedef struct {

    int largura;     // Largura do sprite
    int altura;      // Altura do sprite
    
    char** dados;    // Dados do sprite (matriz de caracteres)

} Sprite;

// Função para criar um novo sprite
Sprite* criar_sprite(int largura, int altura, char** dados);

// Função para destruir um sprite
void destruir_sprite(Sprite* sprite);

#endif // SPRITE_H

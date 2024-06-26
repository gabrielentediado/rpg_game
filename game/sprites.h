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


//titulo
char titulo_1[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                     *RPG*                       |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";


char titulo_2[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                      *PG                        |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";
char titulo_3[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                     R*G                         |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";

char titulo_4[] = 
"\t\t\t _________________________________________________\n"
"\t\t\t|                                                 |\n"
"\t\t\t|                      RP*                        |\n"
"\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n";


char combate[] = 
"\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n"
"\t\t|                                                 |\n"
"\t\t|  ATACAR - 1      FUGIR - 2      3 - DEFENDER    |\n"
"\t\t|___________________        ______________________|\n";

char mapa[] =
"\t\t\t ________________________________________________________\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t|                                                        |\n"
"\t\t\t ________________________________________________________\n";


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

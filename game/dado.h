#include <stdio.h>
#include <time.h>
#include <unistd.h> //biblioteca para delay (sleep)
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//arquivos do jogo

#include "personagem_atributos.h"
#include "sprites.h" //falta incluir os sprite

int dado6(void){

    return((rand() % 6) + 1);

}

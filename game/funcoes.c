//espaço para usar as fuções antes de serem implementadas no arquivo main.c

#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "funcao_nao_imp.h"

int dado(void){

    return((rand() % 6) + 1);

}
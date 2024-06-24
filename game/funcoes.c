//espaço para usar as fuções antes de serem implementadas no arquivo main.c
//para acessar os arquivos dessa path basta incluir #include "funcoes.c"

#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <locale.h>
#include <stdlib.h>
#include <string.h>



#include "funcao_nao_imp.h"
#include "personagem_atributos.h"
#include "sprites.h"

//dado de 6 lados
int dado(){

    srand(time(NULL));
    return((rand() % 6) + 1);

}

//dado de 3 lados
int dado_2(){

    srand(time(NULL));
    return((rand() % 3) + 1);

}

int verificador_bau_tentativa = 0;// para impedir dele tentar abrir o bau varias vezes (apenas uma tentativa)

void morte()
{
    printf("%s morreu \n", personagem_principal.nome); 
    printf("Aperte 1: para 'Tentar novamentea'\n2: para 'desitir'");
    scanf("%d", &menuNav);
    switch (menuNav)
    {
    case 1:
        printf("%s", personagem_principal.nome);   
        opcoes();
        break;
    
    case 2:
        printf("A sua historia acaba por aqui \n Obrigado por ter jogado");
        break;
    }
}



// explorar Casa
void explorarCasa(){

    system(CLEAR);
    puts("\n\n*Você decide explorar a casa...*");
    sleep(1);
    puts("Qual lugar da casa deseja explorar? \n");
    printf("\n1 - Quarto\n2 - Sala principal \n3 - Voltar para o menu\n");
    scanf("%d", &menuNav);

    switch (menuNav){

    case 1:
        //quarto
        quarto();
        break;
    case 2:
        //sala
        sala(); //entrar na sala primeiro e depois no quarto
        break; //tinha apagado os breaks sem querer ao passar as funções

    //coloquei as opções
    case 3:
        opcoes();
        break;

    default:
        explorarCasa();
        break; //tinha apagado os breaks sem querer ao passar as funções
    }

}

//quando, o inimigo morrer ou o personagem fugir incrementa em 1 o x e esse valor passa o i e o prt recebe o local da varievel.
void andar(int i) //andar com o dado, dar um passo ou batalhar, por equanto
{
    dadoGerado = dado(); 
    int quantidade_inimigos = 2; //se adionar mais alterar

    if(verificador == 0){
        getchar(); //buffer
        system(CLEAR); //limpa a tela
        printf("Bom, é melhor explorar a casa para procurar algo para me defender \n\n");
        sleep(10); //tava pasando direto para as opções
        opcoes();

    } 
    else{
        printf("continuar daqui. \n");
        //se quiserem colocar a opção de poder voltar pro menu vai ter que mexer no código, se ele conseguir voltar quebra, pois tá passando 0 ao chamar o andar(0); no menu
        printf("Jogue o dado para dar um passo adiante \n");
        printf("\n*aperte 1 para jogar o dado* \n*2 para ir sem a sorte*\n");
        scanf("%d", &menuNav);

        switch (menuNav)
        {
        case 1:

            if (dadoGerado > 4 && i <= quantidade_inimigos){
                printf("dado gerado: %d\n", dadoGerado);
                printf("Parece que o caminho está limpo \n vamo continuar");
                i++;
                andar(i);
                sleep(5);
            }else if(dadoGerado < 4 && i <= quantidade_inimigos){
                printf("dado gerado: %d\n", dadoGerado);
                printf("tenta dar uma passo, mas do escuro aparece algo, um %s vindo em sua direção \n", inimigo_1[i].classe);
                sleep(10);
                batalha(i); //o valor de i passa para a função batalha(int x) e permite identificar o inimigo
            }else{
                printf("o jogo acabou por equando, aguarde novos updates  \n");
            }

            break;  
        case 2:
            printf("Por sua coragem ganhara 1 ponto de ataque e um 1 de vida \n");
            personagem_principal.ataque++;
            personagem_principal.vida++;
            sleep(5);
            if (i <= quantidade_inimigos)
            {
                printf("tenta dar uma passo, mas do escuro aparece algo, um %s vindo em sua direção \n", inimigo_1[i].classe);
                batalha(i); //o valor de i passa para a função batalha(int x) e permite identificar o inimigo

            }else{
                printf("o jogo acabou por equando, aguarde novos updates  \n");
            }
            break;
        }
    }
}                 

int dano;
int dadoGerado_2;

void batalha(int x) //para saber qual inimigo usei o "x", é só passar o valor ao chamar a função
{   

    //ponteiro que aponta para os valores da struct personagem_principal
    Personagem_atributos *personagem_ponteiro = &personagem_principal; 

    sleep(3);

    //para saber se o inimigo morreu ou personagem morreu, dois casos possiveis: 
    //SISTEMA DE MORTES:
    if (personagem_ponteiro->vida<=0)
    {
        morte(); //perder
    }else if(inimigo_1[x].vida <=0){
        printf("você conseguiu \n");
        sleep(3);
        //ganhar passa para o proximo inimigo
        x++; //para colocar mais inimigos vai ter só que fazer isso
        andar(x);
    }
    //agora a vez do inimigo:

    system(CLEAR);
    int defesa = 0;
    printf("\t\t_______Nome do inimigo: %s_______________\n",inimigo_1[x].nome);
    printf("\t\t__________Nome classe: %s________________\n",inimigo_1[x].classe);
    printf("\t\t___________ vida: %d ____________________\n",inimigo_1[x].vida);

    printf("%s", combate);

    printf("\t\t_____________| %s |___________________ \n", personagem_ponteiro->nome);
    printf("\t\t___________Sua vida:%d ______________\n", personagem_ponteiro->vida);
    scanf("%d", &menuNav);
    switch (menuNav)
    {
    case 1:
        printf("%s decide atacar\n", personagem_ponteiro->nome);
        dadoGerado = dado();
        if (dadoGerado > 3)
        {
            printf("valor da jogada: %d \n", dadoGerado);
            printf("%s ecertou o ataque. \n", personagem_ponteiro->nome);

            dano =  inimigo_1[x].vida - personagem_ponteiro->ataque;

            inimigo_1[x].vida = dano;
        }else{
            printf("valor da jogada: %d \n", dadoGerado);
            printf("%s errou o ataque \n", personagem_ponteiro->nome);
            puts("");
        }

        break;
    
    case 2:
        printf("%s decide fugir \n", personagem_ponteiro->nome);
        dadoGerado = dado();

            if (dadoGerado > 5)
        {
            printf("valor da jogada: %d \n", dadoGerado);
            printf("%s consegue fugir \n", personagem_ponteiro->nome);
            sleep(4);
            x++; 
            andar(x);

        }else{
            printf("valor da jogada: %d \n", dadoGerado);
            printf("não foi possivel fugir \n ");
            puts("");
            sleep(1);
        }

        break;
    
    case 3:
        printf("%s decide defender \n", personagem_ponteiro->nome);
        dadoGerado = dado();

        
            if (dadoGerado > 3)
        {
            defesa = 1; //ganha um de defesa
            printf("valor da jogada: %d \n", dadoGerado);
            printf("%s adquirou um ponto de defasa \n", personagem_ponteiro->nome);
            sleep(3);

        }else{

            printf("valor da jogada: %d \n", dadoGerado);
            printf("%s não foi possivel adquirir um ponto de defasa \n", personagem_ponteiro->nome);
            sleep(3);
        }

        break;
    }

    
    printf("Turno do advesário! \n");
    dadoGerado_2 = dado_2();
    printf("dado do adversario: %d \n", dadoGerado_2);

    sleep(4);

    if (dadoGerado_2 == 3) //ataque forte, quebra a defesa
    {
        printf("%s atacou \n", inimigo_1[x].nome);
        dano = personagem_ponteiro->vida - inimigo_1[x].ataque;
        personagem_ponteiro->vida = dano;
        sleep(5);
        

    }else if (dadoGerado_2== 2)  //ataque medio
    {
        
        if (defesa == 1 )
        {
            printf("%s ataca, mas %s consegue defender\n", inimigo_1[x].nome, personagem_principal.nome);
            sleep(5);
            
        }
        
        else{
            
            printf("O inimigo te acerta \n");
            int dano = personagem_principal.vida - inimigo_1[x].ataque;
            personagem_principal.vida = dano;
            sleep(5);
            

        }
    }else if (dadoGerado_2 == 1) //errar
    {
        printf("%s errou \n", inimigo_1[x].nome);
        sleep(5);
        
    }
    
    batalha(x);

}



void invetario(){
    system(CLEAR);
    printf("Inventário: \n1- para ver as suas espadas\n2-para ver seus os escudos\n3-voltar para o menu");
    scanf("%d", &menuNav);

    //inventario *invetario_ponteiro[] = &inv[MAX];
    //inventario *personagem_invetario[] = &personagem_principal_itens[MAX];
    
    printf("você adquiriu uma %s\n", inv[0].espadas_nome);
    //testando a usabilidade: //para passar os valores da espada ou do escudo é só copiar o código e alterar os valores do array
    strcpy(personagem_principal_itens[0].Personagem_inventario.espadas_nome, inv[0].espadas_nome);
    int espada = personagem_principal.ataque + inv[0].espadas_valores;
    personagem_principal.ataque = espada; 
    inv[0].espadas_verificador = 1; //para saber qual espada o usuario tem, 0 para false, 1 para true
    int usando_espada = 0; 

     printf("você adquiriu um %s\n", inv[0].escudo_nome);
    strcpy(personagem_principal_itens[0].Personagem_inventario.escudo_nome, inv[0].escudo_nome);
    int escudo = personagem_principal.vida + inv[0].escudo_valores;
    personagem_principal.vida = escudo; 
    inv[0].escudos_verificador = 1; 
    sleep(5);

    switch (menuNav)
    {
    case 1:
       //mostrar as espadas: 
       //fiz dessa forma para caso ele não consiga pegar uma espada em alguma determidada parte do jogo
        for (int i = 0; i < MAX; i++)
        {
            if(inv[i].espadas_verificador == 1)
            {
                printf("%d - %s \n", i+1, personagem_principal_itens[i].Personagem_inventario.espadas_nome);
            }
        }
        //trocar de espada, para quando a gente colocar stats nas espadas
        printf("Deseja trocar de arma\n1-para sim\n2-para voltar");
        scanf("%d", &menuNav);

        //para trocar de arma ele tem que tirar o valor da espada que ele já estiver usando, senão terá ataque infinito
        switch (menuNav)
        {
        case 1:
            espada = personagem_principal.ataque - inv[usando_espada].espadas_valores;
            personagem_principal.ataque = espada;

            printf("qual espada deseja escolher? \n"); 
            scanf("%d", &menuNav);
            //para impedir de colocar uma espada que não possui
            if(inv[menuNav].espadas_verificador == 1)
            {
                int espada = personagem_principal.ataque + inv[menuNav].espadas_valores;
                personagem_principal.ataque = espada;
                printf("você selecionou a espada: %s\nEstá com: %d de ataque", inv[menuNav].espadas_nome, espada);
                sleep(5);
                invetario(); 
            }else{
                
                printf("você não possui está espada\n");
                invetario(); 
            }

            break;

        case 2:
            invetario(); 
            break;
        
        default:
            invetario(); 
            break;
        }
        
       sleep(3);

        break;
        
    case 2:
        //mostrar os escudos:
        for (int i = 0; i < MAX; i++)
        {
            if(inv[i].escudos_verificador == 1)
            {
                printf("%d - %s \n", i+1, personagem_principal_itens[i].Personagem_inventario.escudo_nome);
            }
    
         }

        sleep(5); //depois faço o resto do código
        invetario();

        break;
    
    case 3:

        opcoes();

        break;

    default:
        invetario();
        break;
    }
}

//main -> cadastro -> opções -> (andar ou explorar casa)

void opcoes(){
    
    system(CLEAR); //limpa a tela

    printf("*Você está em sua casa e enfim levanta...\n\n");
    sleep(1);
    printf("Você não se recorda de nada...\n");
    sleep(1);
    printf("Segue ao espelho, nada de especial\n");
    sleep(1);
    printf("Seu braço reflete, é possível ver uma mensagem...\n\n'Mate-os, liberte a alma' \n\n");
    sleep(1);
    puts("Você olha ao redor e não vê nada além de uma casa de madeira caindo aos pedaços\n");
    sleep(5);

    system(CLEAR);
    puts("\n\nMenu: ");
    puts("O que deseja fazer??");
    puts("1 - Andar \n2 - Explorar a casa\n3- invetario");
    scanf("%d", &menuNav);
    int i=0;
    do{
        switch (menuNav)
        {
        case 1:
            andar(0); //depois de ter explorado a casa ele pode andar
            break;
        case 2:
            if (inv[0].pergaminho_verificador == 1) // para evitar de ficar explorando a casa
            {
                printf("a casa já foi explorada, vamos sair \n");
                sleep(10);
                opcoes();
            }else{

                explorarCasa();   // primeiro terá que explorar a casa (no arquivo funções)
            }

            break; //tinha apagado os breaks sem querer ao passar as funções

        case 3:
                invetario();

            break;
        default:
            opcoes(); 
            break;
        } 
        
    }while(i < 1);
}

void animation(){
    
   for (int j = 0; j < 2; j++)
   {
    for (int i = 0; i <=4; i++){
            switch (i){
            case 0:
                system(CLEAR);
                printf("%s", titulo_1);
                sleep(1);
                
                break;
            case 1:
                system(CLEAR);
                printf("%s", titulo_2);
                sleep(1);
                
                break;
            case 2:
                system(CLEAR);
                printf("%s", titulo_3);
                sleep(1);
                
                break;
            case 3:
                system(CLEAR);
                printf("%s", titulo_4);
                sleep(1);
                
                break;

            case 4:
                system(CLEAR);
                printf("%s", titulo_1);
                sleep(1);
                
                break;
            
            default:
                break;
            }
        }
   }
   
}

// quarto
void quarto(){

        if(verificador == 0){ // para entrar no quarto ele precisa entrar na sala primeiro

            puts("Você decide entrar no quarto, entretanto a porta esta trancada e não há formas de entrar\n\n");
            puts("talvez tenha algo para abrir a porta em algum lugar...");
            sleep(10); //colocando os sleep para não executar muito rapido e dar tempo de ler
            explorarCasa();

        } else {

            printf("O quarto esta escuro e abandonado, há restos de roupas pelo chão...\n");
            sleep(1);
            printf("Parece ter sido vasculhado por alguem recentemente...\n");
            sleep(1);
            puts("Em meio a bagunça, você observa alguns rasgos na parede. \n");
            sleep(1);
            puts("Na parde ao lado uma escrita em sangue feito a mão 'eles são reais' \n\n");
            sleep(1);
            puts("Logo abaixo um baú de madeira, você deseja abrir? \n");
            
            puts("1-para abrir\n2-para voltar");

            puts("\n\n*Você contará com sua sorte para conseguir ou não abrir o baú*"); //começar a usar o dado daqui depois da introdução

            scanf("%d", &menuNav);


            if (menuNav == 1){
   
                // dado gerado
                dadoGerado = dado();

                if(dadoGerado >= 4 && verificador_bau_tentativa == 0){

                    verificador_bau_tentativa = 1;

                    sleep(1);
                    printf("valor da jogada do dado : %d \n", dadoGerado); // mostra o valor do dado
                    
                    sleep(1);
                    printf("Você empurra o baú, uma parte se solta e você pode conferir o que há dentro\n\n");
                    printf("Legal, você encontrou um pergaminho, item adicionado ao seu inventário\n");

                    inv[0].pergaminho_verificador = 1;
                    
                    sleep(1);
                    printf("Acho que não há mais o que explorar, vamos sair da casa!");
                    sleep(10);
                    opcoes();
                    
                } else {
                    verificador_bau_tentativa = 1; 

                    sleep(1);
                    printf("valor da jogada do dado : %d \n", dadoGerado); // mostra o valor do dado
                    printf("O baú está muito bem lacrado, infelizmente você não consegue abrir\n");
                    sleep(2);
                    printf("Acho que não há mais o que explorar, vamos sair da casa!\n");
                    sleep(10);
                    opcoes();
                }

            }else if(menuNav == 2){
                
                printf("vamos voltar \n");
                sleep(10);
                opcoes();

            }

        }
}

//sala

void sala(){

    
        if(verificador == 0){ // verificar se ele ja entrou ou nao na sala
            printf("Você entra silenciosamente na sala principal.\n");
            sleep(1);

            //removi as funções sprites do código, falta ainda implementar os headers

            sleep(1);
            printf("O local está horrível, há pedaços de madeira podre em toda parte\n");
            sleep(1);
            printf("É possível ver algo brilhante refletindo em uma pequena mesa de centro\n");
            sleep(1);
            puts("Deseja verificar o que é?\n");
            printf("1 - Sim\n2 - Não\n");
            scanf("%d", &menuNav);
            
            if (menuNav == 1){
                puts("Você chega perto para ver, afasta um pouco os pedaçoes destroçados de madeira...\n");
                sleep(1);
                puts("É isso! Uma chave, com certeza é a chave que precisa para entrar no quarto\n");

                verificador = 1; // agora ele ja pode andar e entrar no quarto

                sleep(1);
                printf("Vamos voltar e explorar o quarto...\n");
                sleep(8);
                explorarCasa();

            }else{

                puts("Ah, melhor não ver o que é, devemos voltar!");
                sleep(10);
                explorarCasa(); //para não ficar confuso, ele volta para as opções de sala ou quarto

            }
            
        }
}



/*

              _           _             
             | |         | |            
   _ __ _  __| | __ _ ___| |_ _ __ ___  
  / __/ _` |/ _` |/ _` / __| __| '__/ _ \ 
 | (_| (_| | (_| | (_| \__ \ |_| | | (_) |
  \___\__,_|\__,_|\__,_|___/\__|_|  \___/ 


*/
                                         
//main -> cadastro
void cadastro(){

    system(CLEAR);
    puts("*Depois de uma longa noite, o escolhido finalmente acorda...\n");
    sleep(2);
    getchar();//limpar o buffer
    printf("Como deveriamos lhe chamar?\n");
    scanf("%19s", personagem_principal.nome);
    printf("que bom que acordou, bem-vindo de volta %s \n", personagem_principal.nome);
    sleep(5);
    int escolher;
    do
    {
        system(CLEAR);
        printf("%s", titulo_1);
	    printf("\t\t\t|           Visualize as classes:                 |\n");
	    printf("\t\t\t|    1 - Para Mago                                |\n");
        printf("\t\t\t|    2 - Para Humano                              |\n");
        printf("\t\t\t|    3 - Para Elfo                                |\n");
        printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");
        
        scanf("%d", &menuNav);

        switch (menuNav)
        {
        case 1:
            printf("%s", titulo_1);
            printf("\t\t\t|                  MAGO                           |\n");
            printf("\t\t\t|    VIDA: 15HP                                   |\n");
            printf("\t\t\t|    DANO: 3HP                                    |\n");
            printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");

            printf("1 - Escolher \n2 - Sair\n");

            scanf("%d", &escolher);

            if (escolher == 1)
            {
                strcpy(personagem_principal.classe, "mago");
                personagem_principal.vida = 15;
                personagem_principal.ataque = 3;
                opcoes();
            }
            break;

        case 2:
            printf("%s", titulo_1);
            printf("\t\t\t|                  HUMANO                         |\n");
            printf("\t\t\t|    VIDA: 9HP                                    |\n");
            printf("\t\t\t|    DANO: 6HP                                    |\n");
            printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");
             
            printf("1 - Escolher \n2 - Sair\n");
            scanf("%d", &escolher);

            if (escolher == 1)
            {
                strcpy(personagem_principal.classe, "Humano");
                personagem_principal.vida=9;
                personagem_principal.ataque=6;
                opcoes();
            }
            break;
        
        case 3:
            printf("%s", titulo_1);
            printf("\t\t\t|                  ELFO                           |\n");
            printf("\t\t\t|    VIDA: 10HP                                   |\n");
            printf("\t\t\t|    DANO: 4HP                                    |\n");
            printf("\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - |\n");
            printf("1 - Escolher \n2 - Sair\n");
            scanf("%d", &escolher);
            if (escolher == 1)
            {
                strcpy(personagem_principal.classe, "Elfo");
                personagem_principal.vida = 10;
                personagem_principal.ataque = 4;
                opcoes();
            }
            break;
        }

    }while(escolher != 1);
    
}
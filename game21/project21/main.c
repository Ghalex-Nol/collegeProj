#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define PILHA_VAZIA     1
#define PILHA_NAO_VAZIA 0

#define NAIPE_OURO      0
#define NAIPE_ESPADA    1
#define NAIPE_COPAS     2
#define NAIPE_PAUS      3

const int NAIPES[] = {4, 6, 3, 5};
const char *VALORES = "A23456789TJQK";

typedef struct _Carta {
    struct _Carta *proxima;
    char valor;
    int naipe;
} CARTA;

typedef CARTA *PTR_CARTA;


CARTA CriarCarta(char valor, int naipe){
    CARTA carta;
    carta.valor = valor;
    carta.naipe = naipe;
    return carta;
}

typedef struct _lista {
    PTR_CARTA inicio;
    int tamanho;
} LISTA;

typedef LISTA *PTR_LISTA;

PTR_LISTA criar_lista(){
    PTR_LISTA lista = (PTR_LISTA)malloc(sizeof(PTR_LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    return lista;
}

void exibir_lista(PTR_LISTA lista){
    if (lista->tamanho == 0)
        return;

    PTR_CARTA carta = lista->inicio;
    while (carta != NULL){
        printf("%d\n", carta->valor);
        carta = carta->proxima;
    }
    printf("\n");
}

void inserir_final(PTR_LISTA lista, int valor){
    // Criar uma carta e adicionar o conteúdo
    PTR_CARTA carta = (PTR_CARTA)malloc(sizeof(PTR_CARTA));
    carta->valor = valor;
    carta->proxima = NULL;

    // Inserir a carta na lista vazia
    if (lista->tamanho == 0){
        lista->inicio = carta;
    } else { // Inserir a carta na lista com elementos
        PTR_CARTA temp = lista->inicio;
        while (temp->proxima != NULL){
            temp = temp->proxima;
        }
        temp->proxima = carta;
    }

    lista->tamanho++;
}

void inserir_inicio(PTR_LISTA lista, char valor, char naipe){
// Criar uma carta e adicionar o conteúdo
    PTR_CARTA carta = (PTR_CARTA)malloc(sizeof(PTR_CARTA));
    carta->valor = valor;
    carta->naipe = naipe;
    carta->proxima = NULL;

    // Inserir a carta na lista vazia
    if (lista->tamanho == 0){
        lista->inicio = carta;
    } else {
        carta->proxima = lista->inicio;
        lista->inicio = carta;
    }

    lista->tamanho++;
}


void remover_final(PTR_LISTA lista){
    if (lista->tamanho != 0){
        // Inicio -> 10 -> 20 -> 30 -> 40
        // Lixo -> 40
        PTR_CARTA lixo = lista->inicio;
        PTR_CARTA penultimo = lista->inicio;
        while(lixo->proxima != NULL){
            lixo = lixo->proxima;
            if (lixo->proxima != NULL){
                penultimo = penultimo->proxima;
            }
        }
        penultimo->proxima = NULL;
        free(lixo);
        lista->tamanho--;
    }
}

void remover_inicio(PTR_LISTA lista){
    if (lista->tamanho != 0){
        PTR_CARTA lixo = lista->inicio;
        lista->inicio = lista->inicio->proxima;
        free(lixo);
        lista->tamanho--;
    }
}



void ImprimirCarta(CARTA carta){
    HANDLE tela = GetStdHandle( STD_OUTPUT_HANDLE );
    if (carta.naipe == NAIPES[NAIPE_COPAS] || carta.naipe == NAIPES[NAIPE_OURO])
        SetConsoleTextAttribute(tela, 252);
    else
        SetConsoleTextAttribute(tela, 240);

    printf("%c%c", carta.valor, carta.naipe);
    SetConsoleTextAttribute(tela, 7);
    printf(" ");
}

int main(){
    srand(time(NULL));

   

   
    
    PTR_LISTA baralho = criar_lista();


 for(int x = 0; x<4; x++){
         for(int y = 0; y<13; y++){
             // verificar como colocar esse inserir no for 
    //        inserir_inicio(baralho, VALORES[y], NAIPES[x]);
            printf(" %c %c ", VALORES[y], NAIPES[x]);
         }
    }

   /* for(int y = 0; y<4; y++){
        for(int x = 0; x<14; x++){
            inserir_inicio(baralho, VALORES[x], NAIPES[y]);
            printf(" %c \n " , VALORES[x]);
        }
        printf(" %c \n " , NAIPES[y]);
    }
*/




    //ImprimirCarta(CriarCarta('A', NAIPES[NAIPE_COPAS]));
    //ImprimirCarta(CriarCarta(VALORES[rand() % 13], NAIPES[rand() % 4]));
    return 0;
}

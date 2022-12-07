#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

typedef struct p{
  char c;
  struct p *prox;
}pilha;
typedef struct f{
  char n;
  struct f *prox;
}fila;

pilha *novaPilha(char c){
  pilha *nova = malloc(sizeof(pilha));
  nova->c = c;
  nova->prox = NULL;
  return nova;
}
void apagaPilha();
void pushPilha(pilha *p){}
void popPilha(pilha *p){}
char pilha_getToken(pilha *p){}
fila *novaFila(){}
void apagaFila(fila *p){}
void pushFila(fila *p){}
void popFila(fila *p){}
char fila_getToken(fila *p){}
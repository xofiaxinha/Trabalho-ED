#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

//Tanto pilha e fila são listas encadeadas
//A pilha trabalha utilizando nó sentinela;
//Pilha -> LIFO, ultimo que entra é o primeiro que sai
typedef struct p{
  char c;
  struct p *prox;
}pilha;
typedef struct f{
  char c;
  struct f *prox;
}fila;

pilha *novaPilha(char c){
  pilha *nova = (pilha*)malloc(sizeof(pilha));
  nova->c = c;
  nova->prox = NULL;
  return nova;
}
void apagaPilha(pilha *p){
  free(p);
}
void pushPilha(pilha *p, char c){
  pilha *aux = p;
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  aux->prox = novaPilha(c);
}
void popPilha(pilha *p){
  pilha *aux = p->prox, *aux2 = aux;
  while(aux->prox != NULL) {
    aux2 = aux; //pega o anterior de aux
    aux = aux->prox; //vai pra frente ate o prox ser nulo, 
                    //ou seja, vai pra frente ate ser o ultimo da pilha
  }
  aux2->prox = NULL;
  free(aux);
}
char pilha_getToken(pilha *p){
  return p->c;
}
void printPilha(pilha *p){
  pilha *aux = p->prox;
  while(aux != NULL){
    printf("%c ", aux->c);
    aux = aux->prox;
  }
}
bool isEmptyPilha(pilha *p){
  if(p->prox == NULL)
    return true;
  else
    return false;
}

fila *novaFila(char c){
  fila *nova = (fila*)malloc(sizeof(fila));
  nova->c = c;
  nova->prox = NULL;
  return nova;
}
void apagaFila(fila *f){
  free(f);
}
void pushFila(fila *f, char c){
  fila *aux = f;
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  aux->prox = novaFila(c);
}
void popFila(fila *f){
  fila *aux = f->prox;
  f->prox = aux->prox;
  free(aux);
}
char fila_getToken(fila *f){
  return f->c;
}
void printFila(fila *f){
  fila *aux = f->prox;
  while(aux != NULL){
    printf("%c ", aux->c);
    aux = aux->prox;
  }
}
bool isEmptyFila(fila *f){
  if(f->prox == NULL)
    return true;
  else
    return false;
}
char topoPilha(pilha *p){
  pilha *aux = p->prox;
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  return aux->c;
}
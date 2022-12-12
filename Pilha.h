#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct p;
typedef struct p pilha;

pilha *novaPilha(char c);
void apagaPilha(pilha *p);
void pushPilha(pilha *p, char c);
void popPilha(pilha *p);
char pilha_getToken(pilha *p);
void printPilha(pilha *p);
bool isEmptyPilha(pilha *p);
char topoPilha(pilha *p);
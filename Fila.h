#include <stdio.h>
#include <stdlib.h>
struct f;
typedef struct f fila;

fila *novaFila(char c);
void apagaFila(fila *f);
void pushFila(fila *f, char c);
void popFila(fila *f);
char fila_getToken(fila *f);
void printFila(fila *f);
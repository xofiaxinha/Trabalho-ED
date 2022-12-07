#include <stdio.h>
#include <stdlib.h>
struct f;
typedef struct f fila;

fila *novaFila();
void apagaFila(fila *p);
void pushFila(fila *p);
void popFila(fila *p);
char fila_getToken(fila *p);
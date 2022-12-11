#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

void shuntingYard(char *expressao, fila *posfixa); // Função que converte a expressão infixa para a posfixa
int calcule(fila *posfixa); // Função que calcula a expressão posfixa
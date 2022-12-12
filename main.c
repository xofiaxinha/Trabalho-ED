#include <stdio.h>
#include "ShuntingYard.h"
#include "Fila.h"
#include "Pilha.h"
int main(void) {
    fila *posfixa = novaFila(0);
    char exp[100];
    printf("Digite a expressao: ");
    scanf(" %[^\n]s", exp);
    shuntingYard(exp, posfixa);
    printf("A expressao convertida eh: ");
    printFila(posfixa);
    //int result = calcule(posfixa);
    //printf("O resultado eh: %d", result);
}
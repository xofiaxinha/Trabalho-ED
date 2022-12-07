#include <stdio.h>
#include "Fila.h"
#include "Pilha.h"
int main(void) {
  char s[] = {'H', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', '\n'};
  
  fila* Fila = novaFila(0);
  for(int i = 0; s[i]; i++){
    pushFila(Fila, s[i]);
  }
  printf("Teste com Fila:\n");
  printFila(Fila);
  printf("\n");

  pilha *Pilha = novaPilha(0);
  for(int i = 0; s[i]; i++){
    pushPilha(Pilha, s[i]);
  }
  printf("Teste com Pilha:\n");
  printPilha(Pilha);
  printf("\n");
}
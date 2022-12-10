#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Fila.h"
#include "Pilha.h"

// funções auxiliares de checagem
bool isOP(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case 'm':
        case 'l':
            return true;
        default:
            return false;
    }
}
bool isNum(char c){
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}
bool isPar(char c){
    if(c == '(' || c == ')')
        return true;
    else
        return false;
}
bool isSpace(char c){
    if(c == ' ')
        return true;
    else
        return false;
}
bool isValid(char *exp){
    for(int i=0; i<strlen(exp); i++){
        if(isPar(exp[i])){
            int j = i, opPar = 0, clsPar = 0;
            while(j < strlen(exp)){
                if(exp[j] == '('){
                    opPar += 1;
                }
                if(exp[j] == ')'){
                    clsPar += 1;
                }
                j++;
            }
            if(opPar > clsPar)
                return false;
        } // checagem com os parenteses

        if(isOP(exp[i])){
            if(i == 0){
                if(exp[i] == '-' || exp[i] == '+'){
                    continue;
                }
                else
                    return false;
            }
            else{
            if(isOP(exp[i-1])){
                if(exp[i] == '-' || exp[i] == '+'){
                    continue;
                }
                else
                    return false;
            }

            if(exp[i] == '/'){
                if(exp[i+1] == '0')
                    return false;
                else continue;
            }}
        } // checagem com os operadores

        if(isSpace(exp[i])) continue;
    }
    return true;
}
void shuntingYard(char *expressao, fila *posfixa){
    // 1º passo: se a expressão for inválida retorna
    // 2º passo: cria uma pilha
    // 3º passo: percorre a expressão colocando os números na fila e os operadores na pilha
    // 4º passo: quando encontrar um parêntese, se for aberto, empilha, se for fechado, desempilha até encontrar o parêntese aberto
    // 5º passo: quando encontrar um operador, desempilha até encontrar um operador de menor precedência
    // 6º passo: quando acabar a expressão, desempilha até a pilha ficar vazia, colocando os operadores na fila
}
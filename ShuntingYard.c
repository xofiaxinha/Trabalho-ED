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
        else if(isOP(exp[i])){
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
        else if(isNum(exp[i])) continue;
        else if(isSpace(exp[i])) continue;
          
      else return false;
      /*um token da string pode ser ou um parêntese, 
ou um operador, ou um número, ou um espaço, 
se não for então a operação é inválida*/
    }
    return true;
}
int precedencia(char op){
  switch(op){
    case '(':
    case ')':
      return 4;
      break;
    case '^':
    case 'l':
      return 3;
      break;
    case 'm':
    case '/':
    case '*':
      return 2;
      break;
    case '+':
    case '-':
      return 1;
      break;
  }
  return 0;
}
float operacoes(float a , float b, char x){
  switch(x){
    case '+':
      return a+b;
      break;
    case '-':
      return a-b;
      break;
    case '*':
      return a*b;
      break;
    case '/':
      return a/b;
      break;
    default:
      return 0.0;
  }
}
void desempilharPilha(pilha *op){
  while(!isEmptyPilha(op)&& precedencia(topoPilha(op))!=3){
    popPilha(op);
  }
}
void shuntingYard(char *expressao, fila *posfixa){
    // 1º passo: se a expressão for inválida retorna
    if(!isValid(expressao)){
      printf("Expressao invalida!\n");
			return;
    }
    // 2º passo: cria uma pilha
    pilha *p = novaPilha(0);
    // 3º passo: percorre a expressão colocando os números na fila e os operadores na pilha
    for(int i=0;i<strlen(expressao);i++){
      if(isNum(expressao[i])){
				if(i>=2 && isOP(expressao[i-1]) && isOP(expressao[i-2])) 
					pushFila(posfixa, expressao[i-1]);
        pushFila(posfixa, expressao[i]);
      }
      else if(isOP(expressao[i])){
        pushPilha(p, expressao[i]);
        desempilharPilha(p);
      }
      else if(isPar(expressao[i])){
        pushPilha(p, expressao[i]);
        }
        else{
        popPilha(p);//terminar a parte de desempilhar até achar os parenteses
        }
      }
      
      
    // 4º passo: quando encontrar um parêntese, se for aberto, empilha, se for fechado, desempilha até encontrar o parêntese aberto
    // 5º passo: quando encontrar um operador, desempilha até encontrar um operador de maior precedência
    // 6º passo: quando acabar a expressão, desempilha até a pilha ficar vazia, colocando os operadores na fila
}
int calcule(fila *posfixa){
    // 1º passo: cria uma pilha
    novaPilha(0);
    // 2º passo: percorre a fila
    
    // 3º passo: se for um número, empilha
    // 4º passo: se for um operador, desempilha os dois últimos números, realiza a operação e empilha o resultado
    // 5º passo: quando acabar a fila, desempilha o resultado
    // ps: a fila é uma fila de char, então é necessário converter os números para int
    // ps2: a função atoi() converte uma string para int
}
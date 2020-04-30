#include <stdio.h>
#include <stdlib.h>
#include "gestaoDados.h"


USER registarUser(){
    USER aux;

    printf("Introduza nome:\n");
    scanf("%100[^\n]s",aux.nome);
    printf("Introduza password:\n");
    scanf("%100[^\n]s",aux.passwd);

    return aux;
}

int main() {
    int nPerguntas=0;

    printf("\n");
    printf("Qual a quantidade de perguntas a jogar:");
    scanf("%i",&nPerguntas);
    while(nPerguntas!=0){

        nPerguntas--;
    }

    return 0;
}

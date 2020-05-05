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
int menu_arranque () {
    int opc = 0;
    printf("*************MENU-************\n");
    printf("***********1-JOGAR************\n");
    printf("***********2-ADMINISTRAR******\n");
    printf("***********0-SAIR*************\n");
    scanf("%i", &opc);
    return opc;
}
int menu_user() {
    int opc=0;
    printf("*******MENU*************\n");
    printf("******1-ACESSAR CONTA***\n");
    printf("******2-REGISTAR*******\n");
    printf("******0-SAIR***********\n");
    scanf("%i", &opc);
    return opc;

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

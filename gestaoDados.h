//
// Created by Luis on 30/04/2020.
//

#ifndef PROJETO_GESTAODADOS_H
#define PROJETO_GESTAODADOS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct util{
    char nome[100];
    char username[30];
    char passwd[30];
    int idade;
    char nacionalidade[100];
    int isAdmin;
    DATA ultima;
}USER;

typedef struct elem{
    USER info;
    struct elem *seguinte;
    struct elem *anterior;
}ELEMENTO;

typedef struct perguntas{
    int indice;
    char pergunta[100];
    char respostas[5][100];
    char correta[1];
}PERGUNTA;

typedef struct elemp{
    PERGUNTA info;
    struct elemp *seguinte;
    struct elemp *anterior;
}ELEMENTOP;
void painelAdmin(USER users[], int totregistos);
int gravarEmFicheiro(ELEMENTO *inilista,int totregistos);
int inserirFimLista(ELEMENTO **inilista,ELEMENTO **fimlista, USER aux_info);
void limparLista(ELEMENTO **inilista, ELEMENTO **fimlista);
int loginUser (USER users[], int totregistos);
ELEMENTO *login(ELEMENTO *iniLista, ELEMENTO *fimLista);
#endif //PROJETO_GESTAODADOS_H

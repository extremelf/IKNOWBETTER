//
// Created by Luis on 30/04/2020.
//

#ifndef PROJETO_GESTAODADOS_H
#define PROJETO_GESTAODADOS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>


typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct util{
    char nome[100];
    char username[30];
    char passwd[30];
    char carater[1];
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
    char respostas[4][100];
    char correta[100];
    int tipoPergunta;
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
USER *login (USER *iniLista, USER *fimLista);
void geradorPerguntas(ELEMENTOP **iniLista, ELEMENTOP **fimLista,int totperguntas);
void removerP (ELEMENTOP **inilista, ELEMENTO **fimlista, ELEMENTO totperguntas);
int inserirFimListaPerguntas(ELEMENTOP **inilista,ELEMENTOP **fimlista, PERGUNTA aux_info);
void lerPerguntas(ELEMENTOP **iniLista, ELEMENTOP **fimLista);
#endif //PROJETO_GESTAODADOS_H

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

typedef struct utilizador{
    char nome[100];
    char username[30];
    char passwd[30];
    char carater;
    int idade;
    char nacionalidade[100];
    int isAdmin;
    float dinheiro;
    DATA ultima;
}USER;

typedef struct elem{
    USER info;
    struct elem *seguinte;
    struct elem *anterior;
}ELEMENTO;

typedef struct perguntas{
    int indice;
    char pergunta[300];
    char respostas[5][300];
    char correta[100];
    int tipoPergunta;
}PERGUNTA;

typedef struct elemp{
    PERGUNTA info;
    struct elemp *seguinte;
    struct elemp *anterior;
}ELEMENTOP;
void painelAdmin(USER users[], int totregistos);
int gravarEmFicheiro(ELEMENTO *inilista);
int inserirFimLista(ELEMENTO **inilista,ELEMENTO **fimlista, USER aux_info);
int inserirFimListaPerguntas(ELEMENTOP **inilista,ELEMENTOP **fimlista, PERGUNTA aux_info);

void limparLista(ELEMENTO **inilista, ELEMENTO **fimlista);
void limparListaPerguntas(ELEMENTOP **inilista, ELEMENTOP **fimlista);

int loginUser (USER users[], int totregistos);
ELEMENTO *login(ELEMENTO *iniLista);
void geradorPerguntas(ELEMENTOP *iniLista1, ELEMENTOP **iniLista2, ELEMENTOP **fimLista2,int totperguntas);

void lerPerguntas(ELEMENTOP **iniLista, ELEMENTOP **fimLista);
void lerUserEmFicheiro(ELEMENTO **iniListaUser, ELEMENTO **fimListaUser);

void listarPerguntas(ELEMENTOP *iniLista);
#endif //PROJETO_GESTAODADOS_H

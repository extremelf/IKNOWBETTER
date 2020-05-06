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

typedef struct perguntas{
    char pergunta[100];
    char resposta1[100];
    char resposta2[100];
    char resposta3[100];
    char resposta4[100];
    char respostaDireta[100];
    char opcaoCorreta[100];
    int categoria;
}PERGUNTA;


typedef struct elem{
    PERGUNTA info;
    struct elem *seguinte;
    struct elem *anterior;
}ELEMENTOP;

typedef struct util{
    char nome[100];
    char passwd[100];
    int admin;
    int idade;
    char nacionalidade[100];
    int score;
    int scoretotal;
    int dinheiroCaixa;
    DATA ultima;
}USER;

typedef struct elem{
    USER info;
    struct elem *seguinte;
    struct elem *anterior;
}ELEMENTO;

void painelAdmin(USER users[], int totregistos);
int gravarEmFicheiro(ELEMENTO *inilista,int totregistos);
int inserirFimLista(ELEMENTO **inilista,ELEMENTO **fimlista, USER aux_info);
void limparLista(ELEMENTO **inilista, ELEMENTO **fimlista);
#endif //PROJETO_GESTAODADOS_H

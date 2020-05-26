//
// Created by Luis on 30/04/2020.
//

#ifndef PROJETO_GESTAODADOS_H
#define PROJETO_GESTAODADOS_H
#include <stdlib.h>
#include <stdio.h>


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
    DATA ultima;
}USER;

typedef struct elem{
    USER info;
    struct elem *seguinte;
    struct elem *anterior;
}ELEMENTO;
void painelAdmin(USER users[], int totregistos)
int gravarEmFicheiro(ELEMENTO *inilista,int totregistos);
int inserirFimLista(ELEMENTO **inilista,ELEMENTO **fimlista, USER aux_info);
void limparLista(ELEMENTO **inilista, ELEMENTO **fimlista);
int loginUser (USER users[], int totregistos);
void ordenaPorNome(USER users[], int totregistos, int tam);
void listUsers(USER users[], int totregistos);


#endif //PROJETO_GESTAODADOS_H

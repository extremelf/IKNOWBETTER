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


typedef struct ranking{
    char username[30];
    int dinheiro;
    char username2[30];
    int dinheiro2;
    DATA data;
}RANKING;

typedef struct elemr{
    RANKING info;
    struct elemr *seguinte;
    struct elemr *anterior;
}ELEMENTOR;

typedef struct utilizador{
    char nome[100];
    char username[30];
    char passwd[30];
    char carater;
    int idade;
    char nacionalidade[100];
    int isAdmin;
    int dinheiro;
    int carteira;
    int apostaFinal;
    DATA ultima;
}USER;

typedef struct elem{
    USER info;
    struct elem *seguinte;
    struct elem *anterior;
}ELEMENTO;

typedef struct perguntas{
    int indice;
    int categoria;
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
void painelAdmin(ELEMENTO *admin,ELEMENTO **iniListaUser,ELEMENTO **fimListaUser,ELEMENTOP **iniListaPerguntas,ELEMENTOP **fimListaPerguntas);
void jogada(ELEMENTO *user[],ELEMENTOP *iniListaPerguntas2,ELEMENTOP *fimListaPerguntas2,int totPerguntas,ELEMENTOP *iniListaPerguntas,ELEMENTOP *fimListaPerguntas);

int inserirFimLista(ELEMENTO **inilista,ELEMENTO **fimlista, USER aux_info);
int inserirFimListaPerguntas(ELEMENTOP **inilista,ELEMENTOP **fimlista, PERGUNTA aux_info);
int inserirFimListaRanking(ELEMENTOR **inilista,ELEMENTOR **fimlista, RANKING aux_info);
int removerPergunta(ELEMENTOP **inilista, ELEMENTOP **fimlista, int indice);

void limparLista(ELEMENTO **inilista, ELEMENTO **fimlista);
void limparListaPerguntas(ELEMENTOP **inilista, ELEMENTOP **fimlista);
void limparListaRanking(ELEMENTOR **inilista, ELEMENTOR **fimlista);

ELEMENTO *login(ELEMENTO *iniLista);
void geradorPerguntas(ELEMENTOP *iniLista1, ELEMENTOP **iniLista2, ELEMENTOP **fimLista2,int totperguntas);
ELEMENTOP *perguntaFinal(int categoria,ELEMENTOP *iniLista,ELEMENTOP *iniLista2);

void lerUserEmFicheiro(ELEMENTO **iniListaUser, ELEMENTO **fimListaUser);
void lerPerguntas(ELEMENTOP **iniLista, ELEMENTOP **fimLista);
void lerRanking(ELEMENTOR **iniLista,ELEMENTOR **fimLista);
int gravarEmFicheiro(ELEMENTO *inilista);
void gravarRanking(ELEMENTO *iniLista,ELEMENTO *user[],int caixa,DATA dataAtual);

void apresentacaoPerguntas(ELEMENTOP *aux);
void verificaRespostas(ELEMENTOP *aux,ELEMENTO *aux2[],int *caixa);
void verificarPerguntaFinal(ELEMENTOP *aux,ELEMENTO *maiorPontuacao,ELEMENTO *menorPontuacao,int totalApostaFinal, int *caixa);
void apresentarInfoJogo(ELEMENTO *aux[],int caixa);

DATA getdate();

void alteraPergunta(ELEMENTOP *iniLista, int indice);
void swap(ELEMENTO *a, ELEMENTO *b);
void bubbleSort(ELEMENTO **iniLista);

void listarPerguntas(ELEMENTOP *iniLista);
void listarUtilizadores(ELEMENTO *iniLista);
#endif //PROJETO_GESTAODADOS_H

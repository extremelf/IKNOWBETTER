//
// Created by Luis on 30/04/2020.
//

#ifndef PROJETO_GESTAODADOS_H
#define PROJETO_GESTAODADOS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys\time.h>

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


typedef struct elemp{
    PERGUNTA info;
    struct elemp *seguinte;
    struct elemp *anterior;
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

typedef struct perguntachoosen{
    int posicao;
}PCHOOSEN;
typedef struct perguntaEscolhida{
    PCHOOSEN info;
    struct perguntaEscolhida *seguinte;
    struct perguntaEscolhida *anterior;
}PESCOLHIDA;

void painelAdmin(USER users[], int totregistos);
int gravarEmFicheiro(ELEMENTO *inilista,int totregistos);
int inserirFimListaUser(ELEMENTO **inilista,ELEMENTO **fimlista, USER aux_info);
int inserirFimListaPergunta(ELEMENTOP **inilista,ELEMENTOP **fimlista, PERGUNTA aux_info);
int inserirFimListaPerguntaEscolhida(PESCOLHIDA **iniListaPerguntaEscolhida,PESCOLHIDA **fimListaPerguntaEscolhida, PCHOOSEN aux_info);
void limparListaUser(ELEMENTO **iniListaUser, ELEMENTO **fimListaUser);
void limparListaPerguntas(ELEMENTOP **iniListaPerguntas, ELEMENTOP **fimListaPerguntas);
void limparListaPerguntaEscolhida(PESCOLHIDA **iniListaPerguntaEscolhida, PESCOLHIDA **fimListaPerguntaEscolhida);
int removerPergunta(PESCOLHIDA **iniListaPerguntaEscolhida, PESCOLHIDA **fimListaPerguntaEscolhida, int posicao);
#endif //PROJETO_GESTAODADOS_H

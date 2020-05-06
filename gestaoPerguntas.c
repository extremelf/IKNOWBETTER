//
// Created by Luis on 06/05/2020.
//
#include "gestaoDados.h"
#define LOCALIZACAO "C:\\Users\\mingo\\Desktop\\IPVC\\PROG1\\Teorico-pratica\\IKNOWBETTER\\bases de dados\\perguntas.txt"


//************************************************************
//               Ler perguntas do ficheiro de texto
//************************************************************

void lerPerguntas(ELEMENTOP **iniListaPerguntas,ELEMENTOP **fimListaPerguntas){
    FILE *fp;
    int tamanho;
    int i,j;
    PERGUNTA aux;

    fp=fopen(LOCALIZACAO,"r");

    fscanf(fp,"%d",&tamanho);
    for(i=0;i<tamanho;i++){
        fscanf(fp,"%i\t%s\t%s\t%s\t%s\t%s\t%s\t%s",aux.categoria,aux.pergunta,aux.resposta1,aux.resposta2,
                aux.resposta3,aux.resposta4,aux.respostaDireta,aux.opcaoCorreta);
        inserirFimListaPergunta(&iniListaPerguntas,&fimListaPerguntas,aux);
    }
    fclose(fp);
}
//************************************************************

//************************************************************
//               Ler perguntas do ficheiro de texto
//************************************************************
int selecaoPerguntas(ELEMENTOP **iniListaPerguntas,ELEMENTOP **fimListaPerguntas,PESCOLHIDA **iniListaPerguntaEscolhida, PESCOLHIDA **fimListaPerguntaEscolhida, int *totperguntas){
    int i=0,posicaoRand=0,verificacao=0;
    PCHOOSEN aux;


    for(i=0;i<totperguntas;i++){
        aux.posicao=i;
        inserirFimListaPerguntaEscolhida(&iniListaPerguntaEscolhida,&fimListaPerguntaEscolhida,aux);
    }
    while(verificacao!=(-1)){
        posicaoRand= rand() % (*totperguntas);
        verificacao=removerPergunta(&iniListaPerguntaEscolhida,&fimListaPerguntaEscolhida,posicaoRand);
    }
    (*totperguntas)--;
    return posicaoRand;
}
//************************************************************
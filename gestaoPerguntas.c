//
// Created by Luis on 06/05/2020.
//
#include "gestaoDados.h"
#define LOCALIZACAO "C:\\Users\\mingo\\Desktop\\IPVC\\PROG1\\Teorico-pratica\\IKNOWBETTER\\bases de dados\\perguntas.txt"


//************************************************************
//               Ler perguntas do ficheiro de texto
//************************************************************

void lerPerguntas(ELEMENTO *iniListaPerguntas,ELEMENTO *fimListaPerguntas){
    FILE *fp;
    int tamanho;
    int i,j;
    ELEMENTOP aux;

    fp=fopen(LOCALIZACAO,"r");

    fscanf(fp,"%d",&tamanho);
    for(i=0;i<tamanho;i++){
        fscanf(fp,"%i\t%s\t%s\t%s\t%s\t%s\t%s\t%s",aux->categoria,aux->pergunta,aux->resposta1,aux->resposta2,
                aux->resposta3,aux->resposta4,aux->respostaDireta,aux->opcaoCorreta);
    }
    fclose(fp);
}
//************************************************************
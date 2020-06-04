//
// Created by Luis on 26/05/2020.
//

#include "gestaoPerguntas.h"

void geradorPerguntas(ELEMENTOP *iniLista1, ELEMENTOP **iniLista2, ELEMENTOP **fimLista2,int totperguntas){
    int list[9], vetor[totperguntas];
    int cont=0,i=0,j=0,k=0,check=1,temp;
    ELEMENTOP *aux=NULL;

    for (i = 0; i < 9; i++) {
        list[i] = i;
    }
    for (i = 0; i < totperguntas; i++) {
        j = (i + (rand() % (9 - i)));
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;

        vetor[i] = list[i];
    }


    for(i=0;i<totperguntas;i++){
        printf("poisção:%i\n",vetor[i]);
    }
    i=0;
    do{
        aux=iniLista1;

        while((aux->info.indice)!=(vetor[i])){
            if(aux->info.indice==vetor[i]){
                break;
            }
            aux=aux->seguinte;
            printf("aux errado %i\n", aux->info.indice);
        }

        if(aux->info.indice==vetor[i]){
            printf("guardou na lista\n");
            inserirFimListaPerguntas(iniLista2,fimLista2,aux->info);
            i++;
        }

    }while(i!=totperguntas);
}

//************************************************************
//                      Ler Perguntas de ficheiro
//************************************************************
void lerPerguntas(ELEMENTOP **iniLista, ELEMENTOP **fimLista){
    FILE *fp=NULL;
    PERGUNTA pergunta;

    fp=fopen("perguntas.dat","rb");
    if(fp==NULL){
        printf("Erro a abrir o ficheiro\n");
        return;
    }
    while(1){
        fread(&pergunta,sizeof(pergunta),1,fp);
        inserirFimListaPerguntas(iniLista,fimLista,pergunta);
        if(feof(fp)){
            break;
        }
    }
}
//************************************************************
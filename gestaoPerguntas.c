//
// Created by Luis on 26/05/2020.
//

#include "gestaoPerguntas.h"

int geradorPerguntas(ELEMENTOP *iniLista, ELEMENTOP *fimLista,int totperguntas){
    int *perguntasJogo[totperguntas];
    int posicoes[totperguntas];
    int posicaorand=0;
    int cont=0,i=0,j=0,k=0,check=0;
    ELEMENTOP *aux=NULL;

    do{
        posicaorand=rand()%totperguntas;

        for(j=0;j<totperguntas;j++){
            if(posicaorand==posicoes[j]){
                check=0;
                break;
            }
            else{
                check=1;
            }
        }

        if(check==1){
            posicoes[i]=posicaorand;
            i++;
            cont++;
        }

    }while(cont!=totperguntas || check!=1);

    do{
        aux=iniLista;
        while((aux->info.indice)!=(posicoes[i])){
            aux=aux->seguinte;
        }
        perguntasJogo[k]=aux;
        k++;
        i++;
    }while(k!=totperguntas && i!=totperguntas);
    return perguntasJogo[];
}

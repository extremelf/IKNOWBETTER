//
// Created by Luis on 26/05/2020.
//

#include "gestaoPerguntas.h"

void geradorPerguntas(ELEMENTOP **iniLista, ELEMENTOP **fimLista,int totperguntas){
    int posicoes[totperguntas];
    int posicaorand=0;
    int cont=0,i=0,j=0,k=0,check=0;
    
    ELEMENTOP *aux=NULL;

    do{
        posicaorand=srand()%totperguntas;

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
        inserirFimListaPerguntas(iniLista,fimLista,aux->info);
        i++;
    }while(i!=totperguntas);


}

void lerPerguntas(ELEMENTOP **iniLista, ELEMENTOP **fimLista){
    int posicao=0;
    int contador=0;
    FILE *fp=NULL;
    PERGUNTA perguntas[100];

    fp=fopen("C:\\Users\\mingo\\Desktop\\IPVC\\PROG1\\I know better\\perguntas.dat","rb");
    if(fp==NULL){
        printf("Erro a abrir o ficheiro\n");
        return;
    }
    while(1){
        fread(&perguntas[posicao],sizeof(perguntas),1,fp);
        if(feof(fp)){
            break;
        }
        posicao++;
    }
    for(contador=0;contador<100;contador++){
        inserirFimListaPerguntas(iniLista,fimLista,perguntas[contador]);
    }
    //free(perguntas);
}
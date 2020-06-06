//
// Created by Luis on 26/05/2020.
//

#include "gestaoPerguntas.h"

void geradorPerguntas(ELEMENTOP *iniLista1, ELEMENTOP **iniLista2, ELEMENTOP **fimLista2,int totperguntas){
    int list[16], vetor[totperguntas];
    int i=0,j=0,temp;
    ELEMENTOP *aux=NULL;

    for (i = 0; i < 16; i++) {
        list[i] = i;
    }
    for (i = 0; i < totperguntas; i++) {
        j = 1 + (i + (rand() % (16 - i)));
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;

        vetor[i] = list[i];
    }

    i=0;

    do{
        aux=iniLista1;

        while((aux->info.indice)!=(vetor[i])){
            if(aux->info.indice==vetor[i]){
                break;
            }
            aux=aux->seguinte;
        }

        if(aux->info.indice==vetor[i]){
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

//************************************************************
//                      Gerar a pergunta Final
//************************************************************
ELEMENTOP *perguntaFinal(int categoria,ELEMENTOP *iniLista,ELEMENTOP *iniLista2){
    int vetor;
    int cont=0,i=0,j=0,k=0,check=1,temp;
    ELEMENTOP *aux=NULL,*aux2=NULL;
    aux=iniLista;

    do{
        vetor=rand()%100;
        for(aux2=iniLista2;aux2!=NULL;aux2=aux2->seguinte){
            if(aux2->info.indice==vetor){
                check=0;
                break;
            }
        }
        printf("aqui\n");

        if (check==1) {
            while (1) {
                if (aux->info.indice == vetor && aux->info.categoria == categoria) {
                    return aux;
                }
                if(aux==NULL){
                    break;
                }
                aux = aux->seguinte;
            }
        }
    }while(1);
}
//************************************************************

//************************************************************
//              Apresentar e responder perguntas
//************************************************************
void apresentacaoPerguntas(ELEMENTOP *aux){
    switch (aux->info.tipoPergunta) {
        case 1: {
            printf(" %s\n %s\t %s\n %s\t %s", aux->info.pergunta, aux->info.respostas[0],
                   aux->info.respostas[1], aux->info.respostas[2], aux->info.respostas[3]);
            break;
        }
        case 2: {
            printf(" %s\n Resposta:", aux->info.pergunta);
            break;
        }
        case 3: {
            printf("%s \n Resposta V/F:", aux->info.pergunta);
        }
    }
}

void verificaRespostas(ELEMENTOP *aux,ELEMENTO *aux2[],int *caixa){
    char resposta[100];
    switch (aux->info.tipoPergunta) {
        case 1: {
            printf("Jogador %s a responder:\n", aux2[0]->info.username);
            scanf(" %100[^\n]s", resposta);
            if (strcmp(resposta, (aux->info.correta)) == 0) {
                printf("resposta correta\n");
                aux2[0]->info.dinheiro += 250;
                break;
            }
            if (strcmp(resposta, (aux->info.correta)) != 0) {
                printf("Jogador %s a responder:\n", aux2[1]->info.username);
                scanf(" %100[^\n]s", resposta);
                if (strcmp(resposta, (aux->info.correta)) == 0) {
                    printf("resposta correta\n");
                    aux2[1]->info.dinheiro += 300;
                    break;
                } else {
                    *caixa += 300;
                    break;
                }
            }
        }
        case 2: {
            printf("Jogador %s a responder:\n", aux2[0]->info.username);
            scanf(" %100[^\n]s", resposta);
            if (strcmp(resposta, (aux->info.correta)) == 0) {
                printf("resposta correta\n");
                aux2[0]->info.dinheiro += 250;
                break;
            }
            if (strcmp(resposta, (aux->info.correta)) != 0) {
                printf("Jogador %s a responder:\n", aux2[1]->info.username);
                scanf(" %100[^\n]s", resposta);
                if (strcmp(resposta, (aux->info.correta)) == 0) {
                    printf("resposta correta\n");
                    aux2[1]->info.dinheiro += 300;
                    break;
                } else {
                    printf("Resposta errada\n");
                    *caixa += 300;
                    break;
                }
            }
        }
        case 3: {
            printf("Jogador %s a responder V/F:\n", aux2[0]->info.username);
            scanf(" %100[^\n]s", resposta);
            if (strcmp(resposta, (aux->info.correta)) == 0) {
                printf("resposta correta\n");
                aux2[0]->info.dinheiro += 250;
                break;
            }
            if (strcmp(resposta, (aux->info.correta)) != 0) {
                printf("Jogador %s a responder V/F:\n", aux2[1]->info.username);
                scanf(" %100[^\n]s", resposta);
                if (strcmp(resposta, (aux->info.correta)) == 0) {
                    printf("resposta correta\n");
                    aux2[1]->info.dinheiro += 300;
                    break;
                } else {
                    printf("Resposta errada\n");
                    *caixa += 300;
                    break;
                }
            }
        }
    }
}
//************************************************************

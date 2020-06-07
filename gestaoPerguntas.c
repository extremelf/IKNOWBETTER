//
// Created by Luis on 26/05/2020.
//

#include "gestaoPerguntas.h"

//************************************************************
// Gerador de perguntas aleatoriamente da lista sem repetir
//************************************************************
void geradorPerguntas(ELEMENTOP *iniLista1, ELEMENTOP **iniLista2, ELEMENTOP **fimLista2,int totperguntas){
    int list[66], vetor[totperguntas];
    int i=0,j=0,temp;
    ELEMENTOP *aux=NULL;

    for (i = 0; i < 66; i++) {
        list[i] = i;
    }
    for (i = 0; i < totperguntas; i++) {
        j = 1 + (i + (rand() % (66 - i)));
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

//************************************************************
//                  Remover Pergunta
//************************************************************
int removerPergunta(ELEMENTOP **inilista, ELEMENTOP **fimlista, int indice){
    ELEMENTOP *aux=NULL;

    aux=(*inilista);
    while(aux!=NULL && aux->info.indice!=indice){
        aux=aux->seguinte;
    }
    if(aux==NULL){
        printf("Numero não existe\n");
        return -1;
    }
    if(aux->anterior==NULL){                //remover 1º da lista
        *inilista=aux->seguinte;
        if(*inilista!=NULL){
            (*inilista)->anterior=NULL;
            aux->seguinte->anterior=*inilista;
        }
    }
    else{
        aux->anterior->seguinte=aux->seguinte;
    }
    if(aux->seguinte==NULL){                //remover ultimo da lista
        *fimlista=aux->anterior;
        if(*fimlista!=NULL){
            (*fimlista)->seguinte=NULL;
        }
    }
    else{
        aux->seguinte->anterior=aux->anterior;
    }
    free(aux);
    return 0;
}
//************************************************************

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
        if(feof(fp)){
            break;
        }
        fread(&pergunta,sizeof(pergunta),1,fp);
        inserirFimListaPerguntas(iniLista,fimLista,pergunta);
    }
}
//************************************************************

//************************************************************
//                      Remover ultima pergunta lida
//************************************************************
int removerUltimaPerguntaLida(ELEMENTOP **iniLista,ELEMENTOP **fimLista){
    ELEMENTOP *aux=NULL;

    aux=(*fimLista);

    if(aux==NULL){
        printf("Lista Vazia\n");
        return -1;
    }
    aux->anterior->seguinte=NULL;
    (*fimLista)=aux->anterior;
    free(aux);
    return 0;
}
//************************************************************

//************************************************************
//                      Remover ultima pergunta lida
//************************************************************
int removerUltimoRankingLido(ELEMENTOR **iniLista,ELEMENTOR **fimLista){
    ELEMENTOR *aux=NULL;

    aux=(*fimLista);

    if(aux==NULL){
        return -1;
    }
    aux->anterior->seguinte=NULL;
    (*fimLista)=aux->anterior;
    free(aux);
    return 0;
}
//************************************************************

//************************************************************
//                      Gerar a pergunta Final
//************************************************************
ELEMENTOP *perguntaFinal(int categoria,ELEMENTOP *iniLista){
    int vetor;
    ELEMENTOP *aux=NULL;

    do{
        aux=iniLista;
        vetor=rand()%66;
        while(aux!=NULL){
            if ((aux->info.indice == vetor) && (aux->info.categoria == categoria)) {
                return aux;
            }
            if(aux==NULL){
                break;
            }
            aux = aux->seguinte;
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
            printf(" %s\n %s\t %s\n %s\t %s\n", aux->info.pergunta, aux->info.respostas[0],
                   aux->info.respostas[1], aux->info.respostas[2], aux->info.respostas[3]);
            break;
        }
        case 2: {
            printf(" %s\n Resposta:\n", aux->info.pergunta);
            break;
        }
        case 3: {
            printf("%s \n Resposta:\n", aux->info.pergunta);
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

void verificarPerguntaFinal(ELEMENTOP *aux,ELEMENTO *maiorPontuacao,ELEMENTO *menorPontuacao,int totalApostaFinal, int *caixa){
    char resposta[100];
    switch (aux->info.tipoPergunta) {
        case 1: {
            printf("Jogador %s a responder:\n", maiorPontuacao->info.username);
            scanf(" %100[^\n]s", resposta);
            if (strcmp(resposta, (aux->info.correta)) == 0) {
                printf("resposta correta\n");
                maiorPontuacao->info.dinheiro += totalApostaFinal;
                break;
            }
            if (strcmp(resposta, (aux->info.correta)) != 0) {
                printf("Jogador %s a responder:\n", menorPontuacao->info.username);
                scanf(" %100[^\n]s", resposta);
                if (strcmp(resposta, (aux->info.correta)) == 0) {
                    printf("resposta correta\n");
                    menorPontuacao->info.dinheiro += totalApostaFinal;
                    break;
                } else {
                    printf("Resposta errada\n");
                    *caixa += 300;
                    break;
                }
            }
        }
        case 2: {
            printf("Jogador %s a responder:\n", maiorPontuacao->info.username);
            scanf(" %100[^\n]s", resposta);
            if (strcmp(resposta, (aux->info.correta)) == 0) {
                printf("resposta correta\n");
                maiorPontuacao->info.dinheiro += totalApostaFinal;
                break;
            }
            if (strcmp(resposta, (aux->info.correta)) != 0) {
                printf("Jogador %s a responder:\n", menorPontuacao->info.username);
                scanf(" %100[^\n]s", resposta);
                if (strcmp(resposta, (aux->info.correta)) == 0) {
                    printf("resposta correta\n");
                    menorPontuacao->info.dinheiro += totalApostaFinal;
                    break;
                } else {
                    printf("Resposta errada\n");
                    *caixa += 300;
                    break;
                }
            }
        }
        case 3: {
            printf("Jogador %s a responder V/F:\n", maiorPontuacao->info.username);
            scanf(" %100[^\n]s", resposta);
            if (strcmp(resposta, (aux->info.correta)) == 0) {
                printf("resposta correta\n");
                maiorPontuacao->info.dinheiro += totalApostaFinal;
                break;
            }
            if (strcmp(resposta, (aux->info.correta)) != 0) {
                printf("Jogador %s a responder:\n", menorPontuacao->info.username);
                scanf(" %100[^\n]s", resposta);
                if (strcmp(resposta, (aux->info.correta)) == 0) {
                    printf("resposta correta\n");
                    menorPontuacao->info.dinheiro += totalApostaFinal;
                    break;
                } else {
                    printf("Resposta errada\n");
                    *caixa += totalApostaFinal;
                    break;
                }
            }
        }
    }
}
//************************************************************

//************************************************************
//              Alterar uma Pergunta já existente
//************************************************************
void alteraPergunta(ELEMENTOP *iniLista, int indice){
    ELEMENTOP *aux=NULL;
    int opcao=0;
    int check=0;
    char respostaAlterar='\0';
    aux=iniLista;

    while(1){
        if(aux->info.indice==indice){
            break;
        }
        if(aux==NULL){
            printf("Elemento não encontrado");
            return;
        }
        aux=aux->seguinte;
    }
    do{
        printf("O que deseja alterar:\n"
               "1- Pergunta\n"
               "2- Respostas\n"
               "3- Resposta Correta\n"
               "0- SAIR\n");
        scanf("%i",&opcao);

        switch(opcao){
            case 1:{
                printf("Pergunta atual: %s\n",aux->info.pergunta);
                printf("Introduza 1 para continuar ou 0 para cancelar\n");
                scanf("%i",&check);
                if(check==0){
                    break;
                }
                printf("Introduza a nova pergunta:");
                scanf(" %300[^\n]s",aux->info.pergunta);
                printf("Pergunta alterada com sucesso");
                break;
            }
            case 2:{
                printf("Respostas atuais: %s\t%s\n%s\t%s",aux->info.respostas[0],aux->info.respostas[1],aux->info.respostas[2],aux->info.respostas[3]);
                printf("Introduza 1 para continuar ou 0 para cancelar\n");
                scanf("%i",&check);
                if(check==0){
                    break;
                }
                printf("Qual das opções alterar:");
                scanf("%c",&respostaAlterar);
                switch(respostaAlterar){
                    case 'A':{
                        printf("Introduza a nova opcão A:");
                        scanf(" %300[^\n]s",aux->info.respostas[0]);
                        break;
                    }
                    case 'B':{
                        printf("Introduza a nova opcão B:");
                        scanf(" %300[^\n]s",aux->info.respostas[1]);
                        break;

                    }
                    case 'C':{
                        printf("Introduza a nova opcão C:");
                        scanf(" %300[^\n]s",aux->info.respostas[2]);
                        break;
                    }
                    case 'D':{
                        printf("Introduza a nova opcão D:");
                        scanf(" %300[^\n]s",aux->info.respostas[3]);
                        break;
                    }
                }
                break;
            }
            case 3:{
                printf("Resposta correta Atual: %s",aux->info.correta);
                printf("Introduza 1 para continuar ou 0 para cancelar\n");
                scanf("%i",&check);
                if(check==0){
                    break;
                }
                printf("Introduza a nova resposta correta:");
                scanf(" %100[^\n]s",aux->info.correta);
                break;
            }
        }

    }while(opcao!=0);

}
//************************************************************

//************************************************************
//          Listar perguntas em memória
//************************************************************
void listarPerguntas(ELEMENTOP *iniLista){
    ELEMENTOP *aux = NULL;

    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        switch (aux->info.tipoPergunta) {
            case 1: {
                printf("\n\n%i - %s\n %s\t %s\n %s\t %s\nResposta: %s\n",aux->info.indice, aux->info.pergunta, aux->info.respostas[0],
                       aux->info.respostas[1], aux->info.respostas[2], aux->info.respostas[3], aux->info.correta);
                break;
            }
            case 2: {
                printf("\n\n%i - %s\n Resposta: %s\n",aux->info.indice, aux->info.pergunta, aux->info.correta);
                break;
            }
            case 3: {
                printf("\n\n%i - %s \n Resposta V/F: %s\n",aux->info.indice, aux->info.pergunta, aux->info.correta);
            }
        }
    }
}
//************************************************************
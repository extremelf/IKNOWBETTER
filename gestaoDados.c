//
// Created by Luis on 30/04/2020.
//

#include "gestaoDados.h"

//************************************************************
//                     Guardar Fim da lista User
//************************************************************
int inserirFimListaUser(ELEMENTO **iniListaUser,ELEMENTO **fimListaUser, USER aux_info){
    ELEMENTO *novo=NULL;
    novo=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));

    if(novo==NULL){
        printf("Erro ao alocar memória\n");
        return -1;
    }
    novo->info=aux_info;
    novo->anterior=NULL;
    novo->seguinte=NULL;
    if(*fimListaUser==NULL){
        *iniListaUser=novo;
        *fimListaUser=novo;
    }
    else{
        novo->anterior=*fimListaUser;
        (*fimListaUser)->seguinte=novo;
        *fimListaUser=novo;
    }
    return 0;
}
//************************************************************

//************************************************************
//                      Limpar Lista User
//************************************************************
void limparListaUser(ELEMENTO **iniListaUser, ELEMENTO **fimListaUser){
    ELEMENTO *aux, *proximo;

    aux=*iniListaUser;
    while(aux!=NULL){
        proximo=aux->seguinte;
        free(aux);
        aux=proximo;
    }
    *iniListaUser=NULL;
    *fimListaUser=NULL;
    free(proximo);
}
//************************************************************



//************************************************************
//                 Login de utilizador existente
//************************************************************
ELEMENTO *login(ELEMENTO *iniLista){
    char user[30], passw[100];
    ELEMENTO *aux=NULL;
    int tentativas=3;

    printf("Introduza o nome de utilizador:\n");
    scanf(" %30[^\n]s",user);

    aux=iniLista;

    while(strcmp(aux->info.username,user)!=0){
    aux=aux->seguinte;
    }

    do{
        printf("Introduza a password:\n");
        scanf(" %100[^\n]s",passw);
        if(strcmp(aux->info.passwd,passw)==0){
            printf("Password Correta\n");
            return aux;
        }
        else{
            tentativas--;
            printf("Password incorreta - %i tentativas restantes\n",tentativas);
        }
    }while(tentativas<0);
    return NULL;
}
//************************************************************





//************************************************************
//                     Guardar Fim da lista
//************************************************************
int inserirFimLista(ELEMENTO **inilista,ELEMENTO **fimlista, USER aux_info){
    ELEMENTO *novo=NULL;
    novo=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));

    if(novo==NULL){
        printf("Erro ao alocar memória\n");
        return -1;
    }
    novo->info=aux_info;
    novo->anterior=NULL;
    novo->seguinte=NULL;
    if(*fimlista==NULL){
        *inilista=novo;
        *fimlista=novo;
    }
    else{
        novo->anterior=*fimlista;
        (*fimlista)->seguinte=novo;
        *fimlista=novo;
    }
    return 0;
}
//************************************************************

//************************************************************
//                     Guardar Fim da lista Perguntas
//************************************************************
int inserirFimListaPerguntas(ELEMENTOP **inilista,ELEMENTOP **fimlista, PERGUNTA aux_info){
    ELEMENTOP *novo=NULL;
    novo=(ELEMENTOP *)calloc(1,sizeof(ELEMENTOP));

    if(novo==NULL){
        printf("Erro ao alocar memória\n");
        return -1;
    }
    novo->info=aux_info;
    novo->anterior=NULL;
    novo->seguinte=NULL;
    if(*fimlista==NULL){
        *inilista=novo;
        *fimlista=novo;
    }
    else{
        novo->anterior=*fimlista;
        (*fimlista)->seguinte=novo;
        *fimlista=novo;
    }
    return 0;
}
//************************************************************


//************************************************************
//                      Limpar Lista
//************************************************************
void limparLista(ELEMENTO **inilista, ELEMENTO **fimlista){
    ELEMENTO *aux, *proximo;

    aux=*inilista;
    while(aux!=NULL){
        proximo=aux->seguinte;
        free(aux);
        aux=proximo;
    }
    *inilista=NULL;
    *fimlista=NULL;
    free(proximo);
}
//************************************************************

//************************************************************
//                      Guardar em ficheiro
//************************************************************
int gravarEmFicheiro(ELEMENTO *inilista,int totregistos) {
    ELEMENTO *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("utilizadores.dat", "wb");

    if (fp == NULL) {
        printf("Erro ao criar ficheiro\n");
        return -1;
    }
    fwrite(totregistos, sizeof(int), 1, fp);
    for (aux = inilista; aux != NULL; aux = aux->seguinte) {
        fwrite(&(aux->info), sizeof(USER), 1, fp);
    }
    fclose(fp);
    printf("Ficheiro criado com sucesso\n");

    return 0;
}
//************************************************************

//************************************************************
//                      Obter tempo atual
//************************************************************
DATA getdate(){
    DATA atual;
    struct timeval usec_time;
    time_t now = time(0);
    gettimeofday(&usec_time,NULL);

    struct tm *current = localtime(&now);
    atual.ano=current->tm_year+1900;
    atual.mes=current->tm_mon+1;
    atual.dia=current->tm_mday;

    return atual;
}
//************************************************************




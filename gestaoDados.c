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


//*****************************************************
//LISTAR UTILIZADORES
//*****************************************************
void listUsers(USER users[], int totregistos){
    int i;

    if (totregistos==0) {
        printf("Não ha utilizadores\n");
        return;
    }

    for (i=0;i<totregistos;i++) {
        printf("Nome: %s\n username: %s \n idade: %s \n  nacionalidade: %s \n ",users[i].nome,users[i].username,users[i].idade, users[i].nacionalidade);
        if (users[i].isAdmin==1) {
            printf("E Administrador\n");
        } else {
            printf("E Jogador\n");
        }
    }
}



//********************************************************
// Listar por ordem alfabetica
//********************************************************
void ordenaPorNome(USER users[], int totregistos, int tam){
    int i,j,mudar=1;
    USER aux;
    mudar=0;
    for (x=0;x<tam && mudar=0;x++) {
        mudar=1;
        for (i=0;i<tam-1;i++) {
            if (stricmp(users[i].nome,users[i+1].nome)>0) {
                aux=users[i];
                users[i]=users[i+1];
                users[i+1]=aux;
                mudar=0;
            }
        }
    }
}

//*********************************************************
// LOGIN USER
//*********************************************************
int loginUser (USER users[], int totregistos){
    char utili[30];
    char senha[30];
    int aux, id=-1; //-1 começa do anterior e vai "escalando"

    printf("Introduza o sue username:\n");
    fflush(stdin);
    gets(utili);
    for(aux=0;aux<totregistos;aux++){
        if(strcmp(users[aux].username,utili)==0){
            id=aux;
        }

    }
    //1 via equivale verdadeiro
    if(id==1){
        printf("Esse utilizador não está registado\n");
        return -1;
    }
        printf("Introduza a password:\n");
        fflush(stdin);
         gets(senha); //FALTA ENCRIPTAR
    if( strcmp(users[id].senha, senha)!=0){  // comparar as senhas para verificar se é a correta no utilizador inserido
        printf("A senha não corresponde ao utilizador inserido"\n);
     return -1;
    }
    if(users[id].isAdmin==1){
        printf("Administrador não está autorizado a jogar\n");
        return -1
    }
    return id;  //retornar ao usuario
}


//************************************************************
// LOGIN
//************************************************************
USER *login (USER *iniLista, USER *fimLista){
    char user[30], passw[100];
    ELEMENTO *aux=NULL;
    int check=0, tentativas=3;

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
            check=1;
            return aux;
        }
        else{
            tentativas--;
            printf("Password incorreta - %i tentativas restantes\n",tentativas);
            check=0;
        }
    }while(check!=1 || tentativas<0);
    return NULL;
}


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
// REMOVER PERGUNTA
//***********************************************************

void removerP (ELEMENTOP **inilista, ELEMENTO **fimlista, ELEMENTO totperguntas) {
    PERGUNTA  *aux=NULL; char perg;

    if(*inilista==NULL) {
        printf("lista vazia\n");return -1;
    }

    printf("Insira a  pergunta\n");
    fflush(stdin);
    scanf("%c",&perg);

    aux=*inilista;

    while(aux!=NULL && aux->nodo.perg!=perg) {
        aux=aux->seguinte;
    }

    if(aux==NULL){
        printf("Número não existe\n");
        return -1;
    }

    if(aux->anterior==NULL) {
        *inilista=aux->seguinte;
        if(*inilista!=NULL) {
            (*inilista)->anterior=NULL;
        }
    } else{
        aux->anterior->seguinte=aux->seguinte;
    }

    if(aux->seguinte==NULL) {
        *fimlista=aux->anterior;
        if(*fimlista!=NULL){
            (*fimlista)->seguinte=NULL;
        }
    } else{
        aux->seguinte->anterior=aux->anterior;
    }
    free(aux);
    return;
}





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




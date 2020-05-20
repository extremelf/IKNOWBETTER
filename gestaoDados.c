//
// Created by Luis on 30/04/2020.
//

#include "gestaoDados.h"

//***********************************************************
//             Registo Usuario
//**********************************************************
int recebeDados(USER users[], int totregistos){
    printf("Introduza o nome: \n");
    fflush(stdin);
    fgets(users[totregistos].nome, 100, stdin);
    users[totregistos].nome[strlen(users[totregistos].nome)-1]='\0';
    printf ("Introduza um user:\n");
    fflsuh(stdin);
    fgets(users[totregistos].username, 30, stdin);
    users[totregistos].username[strlen(users[totregistos].username)-1]='\0';
    printf("Insira a senha:\n");
    //faltapartedasenha
    printf("Idade atual:\n");
    scanf("%i", &users[totregistos].idade);
    printf("Introduza a sua nacionalidade:\n");
    fflush(stdin);
    fgets(users[totregistos].nacionalidade, 100,stdin);
    users[totregistos].nacionalidade[strlen(users[tot].nacionalidade)-1]='\0'


}

//*********************************************************
// LOGIN USER
//*********************************************************
int loginUser (USER users[], int totregistos){
    char utili[30];
    char senha[30];
    int aux, id=-1; //-1 começa do anterior e vai "escalando"

    printf("Introduza o sue username:\n");
    fflsuh(stdin);
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
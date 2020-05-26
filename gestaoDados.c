//
// Created by Luis on 30/04/2020.
//
#include <stdlib.h>
#include <conio.h>
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
// LOGIN ADMINISTRADOR
//********************************************************
int checkAdmin (USER users[],int totregistos) {
    char username[50];
    char password[50];
    int x,id=-1;

    printf("Introduza o seu username:\n");
    fflush(stdin);
    gets(utilizador);
    for (x=0;x<totalr;x++) {
        if (strcmp(users[x].nick,utilizador)==0) {
            id=x;
        }
    }
    if (id==-1) {
        printf("O utilizador não está registado\n");
        return 0;
    }
    printf("Introduza a Password:\n");
    fflush(stdin);
    gets(password);

    if (strcmp(users[id].password,password)!=0) {
        printf("A password não coresponde\n");
        return -1;
    }
    if (users[id].isAdmin==1) {
        printf("Bem Vindo Administrador %s\n",users[id].username);
        return 1;
    } else {
        printf("Não é administrador");
        return login;
    }
}



//*********************************************************
// LOGIN USER
//*********************************************************

void login_user(USER users, int totregistos){
        char username[50];
        char password[50];
        int i;

                printf("Introduza o username : \n");
//gets(username);
//fflush(stdin);
//scanf("%s",username);

printf("Introduza a senha : \n");
fflsuh(stdin);
fgets(users[totregistos].username, 30, stdin);
users[totregistos].username[strlen(users[totregistos].username)-1]='\0';
/* Aceitar senha */


for(i=0;i<8;i++)
{
password[i]=getch();
printf("*");
}
password[i]='\0';

/*------------------*/

printf("\n\n Digite em qualque tecla");
getch();

if(!strcmp(username,"") && !strcmp(password,""))
{
printf("\n\n Login efetuado com sucesso");
}else
{
printf("\n\n Senha incorreta");
}
if (users[id].isAdmin==1) {
        printf("Como e administrador nao pode jogar\n");
        return -1;
    }
/*  return game;                  FALTA RETURNNNNNN                              FALTA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

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
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
    printf("Insira a senha:\n");
    //faltapartedasenha
    printf("Idade atual:\n");
    scanf("%i", &users[totregistos].idade);
    printf("Introduza a sua nacionalidade:\n");
    fflush(stdin);
    fgets(users[totregistos].nacionalidade, 100,stdin);
    users[totregistos].nacionalidade[strlen(users[totregistos].nacionalidade)-1]='\0';


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
// No final da execução guardar tudo
int gravarEmFicheiro(ELEMENTO *inilista,int totregistos){
    ELEMENTO *aux=NULL;
    FILE *fp=NULL;
    fp=fopen("utilizadores.dat","wb");

    if(fp==NULL){
        printf("Erro ao criar ficheiro\n");
        return -1;
    }
    fwrite(totregistos,sizeof(int),1,fp);
    for(aux=inilista;aux!=NULL;aux=aux->seguinte){
        fwrite(&(aux->info),sizeof(USER),1,fp);
    }
    fclose(fp);
    printf("Ficheiro criado com sucesso\n");

    return 0;
}
//************************************************************

//************************************************************
//                      Guardar em ficheiro
//************************************************************

//************************************************************
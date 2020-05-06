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
//                     Guardar Fim da lista Perguntas
//************************************************************
int inserirFimListaPergunta(ELEMENTOP **iniListaPerguntas,ELEMENTOP **fimListaPerguntas, PERGUNTA aux_info){
    ELEMENTOP *novo=NULL;
    novo=(ELEMENTOP *)calloc(1,sizeof(ELEMENTOP));

    if(novo==NULL){
        printf("Erro ao alocar memória\n");
        return -1;
    }
    novo->info=aux_info;
    novo->anterior=NULL;
    novo->seguinte=NULL;
    if(*fimListaPerguntas==NULL){
        *iniListaPerguntas=novo;
        *fimListaPerguntas=novo;
    }
    else{
        novo->anterior=*fimListaPerguntas;
        (*fimListaPerguntas)->seguinte=novo;
        *fimListaPerguntas=novo;
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
//                      Limpar Lista Perguntas
//************************************************************
void limparListaPerguntas(ELEMENTOP **iniListaPerguntas, ELEMENTOP **fimListaPerguntas){
    ELEMENTOP *aux, *proximo;

    aux=*iniListaPerguntas;
    while(aux!=NULL){
        proximo=aux->seguinte;
        free(aux);
        aux=proximo;
    }
    *iniListaPerguntas=NULL;
    *fimListaPerguntas=NULL;
    free(proximo);
}
//************************************************************

//************************************************************
//                     Guardar Fim da lista Pergunta Escolhida
//************************************************************
int inserirFimListaPerguntaEscolhida(PESCOLHIDA **iniListaPerguntaEscolhida,PESCOLHIDA **fimListaPerguntaEscolhida, PCHOOSEN aux_info){
    PESCOLHIDA *novo=NULL;
    novo=(PESCOLHIDA *)calloc(1,sizeof(PESCOLHIDA));

    if(novo==NULL){
        printf("Erro ao alocar memória\n");
        return -1;
    }
    novo->info=aux_info;
    novo->anterior=NULL;
    novo->seguinte=NULL;
    if(*fimListaPerguntaEscolhida==NULL){
        *iniListaPerguntaEscolhida=novo;
        *fimListaPerguntaEscolhida=novo;
    }
    else{
        novo->anterior=*fimListaPerguntaEscolhida;
        (*fimListaPerguntaEscolhida)->seguinte=novo;
        *fimListaPerguntaEscolhida=novo;
    }
    return 0;
}
//************************************************************

//************************************************************
//                      Limpar Lista Pergunta escolhida
//************************************************************
void limparListaPerguntaEscolhida(PESCOLHIDA **iniListaPerguntaEscolhida, PESCOLHIDA **fimListaPerguntaEscolhida){
    ELEMENTO *aux, *proximo;

    aux=*iniListaPerguntaEscolhida;
    while(aux!=NULL){
        proximo=aux->seguinte;
        free(aux);
        aux=proximo;
    }
    *iniListaPerguntaEscolhida=NULL;
    *fimListaPerguntaEscolhida=NULL;
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

//************************************************************
//                  Remover participante
//************************************************************
int removerPergunta(PESCOLHIDA **iniListaPerguntaEscolhida, PESCOLHIDA **fimListaPerguntaEscolhida, int posicao){
    PESCOLHIDA *aux=NULL;

    aux=*iniListaPerguntaEscolhida;
    while(aux!=NULL && aux->info.posicao!=posicao){
        aux=aux->seguinte;
    }
    if(aux==NULL){
        printf("Numero não existe\n");
        return -1;
    }
    if(aux->anterior==NULL){                //remover 1º da lista
        *iniListaPerguntaEscolhida=aux->seguinte;
        if(*iniListaPerguntaEscolhida!=NULL){
            (*iniListaPerguntaEscolhida)->anterior=NULL;
            aux->seguinte->anterior=*iniListaPerguntaEscolhida;
        }
    }
    else{
        aux->anterior->seguinte=aux->seguinte;
    }
    if(aux->seguinte==NULL){                //remover ultimo da lista
        *fimListaPerguntaEscolhida=aux->anterior;
        if(*fimListaPerguntaEscolhida!=NULL){
            (*fimListaPerguntaEscolhida)->seguinte=NULL;
        }
    }
    else{
        aux->seguinte->anterior=aux->anterior;
    }
    free(aux);
    return 0;
}
//************************************************************


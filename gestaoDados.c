//
// Created by Luis on 30/04/2020.
//

#include <sys/time.h>
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

    while((strcmp(aux->info.username,user)!=0)){
        aux=aux->seguinte;
        if(aux==NULL){
            break;
        }
    }
    if(aux==NULL){
        printf("Utilizador inexistente\n");
        return aux;
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
    }while(tentativas>0);
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
//             Guardar Fim da lista Perguntas
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
//              Inserir fim lista Ranking
//************************************************************
int inserirFimListaRanking(ELEMENTOR **inilista,ELEMENTOR **fimlista, RANKING aux_info){
    ELEMENTOR *novo=NULL;
    novo=(ELEMENTOR *)calloc(1,sizeof(ELEMENTOR));

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
//                      Limpar Lista Perguntas
//************************************************************
void limparListaPerguntas(ELEMENTOP **inilista, ELEMENTOP **fimlista){
    ELEMENTOP *aux, *proximo;

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
//                      Limpar Lista Perguntas
//************************************************************
void limparListaRanking(ELEMENTOR **inilista, ELEMENTOR **fimlista){
    ELEMENTOR *aux, *proximo;

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
// Listar os utilizadores armazenados em lista
//************************************************************
void listarUtilizadores(ELEMENTO *iniLista){
    ELEMENTO *aux=NULL;
    for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
        printf("%s \t %s\t %i\t %s\t%i/%i/%i\n",aux->info.nome,aux->info.username,aux->info.idade,aux->info.nacionalidade,
                aux->info.ultima.dia,aux->info.ultima.mes,aux->info.ultima.ano);
    }
}
//************************************************************

//************************************************************
//        Organizar a informação dos jogadores por nomes
//************************************************************
void bubbleSort(ELEMENTO **iniLista){
    int swapped, i;
    ELEMENTO *ptr1;
    ELEMENTO *lptr = NULL;

    if (iniLista == NULL){
        printf("Lista está Vazia\n");
        return;
    }

    do{
        swapped = 0;
        ptr1 = *iniLista;

        while (ptr1->seguinte != lptr){
            if (strcmp(ptr1->info.nome,ptr1->seguinte->info.nome)>0){
                swap(ptr1, ptr1->seguinte);
                swapped = 1;
            }
            ptr1 = ptr1->seguinte;
        }
        lptr = ptr1;
    }while (swapped);
}
//************************************************************

//************************************************************
//                      Trocar posições da lista
//************************************************************
void swap(ELEMENTO *a, ELEMENTO *b){
    USER temp = a->info;
    a->info = b->info;
    b->info = temp;
}
//************************************************************

//************************************************************
//              Apresentar informação atual de jogo
//************************************************************
void apresentarInfoJogo(ELEMENTO *aux2[], int caixa){
    printf("Dinheiro\t\tCaixa\t\tApostas\n");
    printf("%s: %i\t%i\t\t%i\n", aux2[0]->info.username, aux2[0]->info.dinheiro, caixa, aux2[0]->info.apostaFinal);
    printf("%s: %i\t\t\t\t\t%i\n", aux2[1]->info.username, aux2[1]->info.dinheiro, aux2[1]->info.apostaFinal);
}

//************************************************************

//************************************************************
//                      Guardar em ficheiro
//************************************************************
int gravarEmFicheiro(ELEMENTO *inilista) {
    ELEMENTO *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("utilizadores.dat", "wb");

    if (fp == NULL) {
        printf("Erro ao criar ficheiro\n");
        return -1;
    }
    //fwrite(totregistos, sizeof(int), 1, fp);
    for (aux = inilista; aux != NULL; aux = aux->seguinte) {
        fwrite(&(aux->info), sizeof(USER), 1, fp);
    }
    fclose(fp);
    printf("Ficheiro criado com sucesso\n");

    return 0;
}
//************************************************************

//************************************************************
//Lê cada utilizador em ficheiro
//************************************************************
void lerUserEmFicheiro(ELEMENTO **iniListaUser, ELEMENTO **fimListaUser){
    FILE *fp=NULL;
    USER aux;
    fp=fopen("utilizadores.dat","rb");
    if(fp==NULL){
        fp=fopen("utilizadores.dat","wb");
        fclose(fp);
        fp=fopen("utilizadores.dat","rb");
    }
    while(1){
        if(feof(fp)){
            break;
        }
        fread(&aux,sizeof(USER),1,fp);
        inserirFimListaUser(iniListaUser,fimListaUser,aux);
    }
    fclose(fp);
}
//************************************************************

//************************************************************
//              Ler Ranking de ficheiro
//************************************************************
void lerRanking(ELEMENTOR **iniLista,ELEMENTOR **fimLista){
    FILE *ranking=NULL;
    RANKING *aux=NULL;

    ranking=fopen("ranking.txt","r");

    while(1){
        fscanf(ranking,"%s;%i;%s;%i;%i;%i/%i/%i\n",aux->username,&aux->dinheiro,aux->username2,&aux->dinheiro2,&aux->data.dia,&aux->data.mes,&aux->data.ano);
        inserirFimListaRanking(iniLista,fimLista,*aux);
        if(feof(ranking)){
            break;
        }
    }
}
//************************************************************

//************************************************************
//             Gravar Ranking em ficheiro
//************************************************************
void gravarRanking(ELEMENTO *iniLista,ELEMENTO *user[],int caixa,DATA dataAtual){
    FILE *ranking=NULL;
    ELEMENTO *aux=NULL;

    ranking=fopen("ranking.txt","w");

    for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
        fprintf(ranking,"%s;%i;%s;%i;%i;%i/%i/%i\n",user[0]->info.username,user[0]->info.dinheiro,user[1]->info.username,user[1]->info.dinheiro,caixa,dataAtual.dia,dataAtual.mes,dataAtual.ano);
    }
    fclose(ranking);
}
//************************************************************

//************************************************************
//              Função de jogo principal
//************************************************************
void jogada(ELEMENTO *user[],ELEMENTOP *iniListaPerguntas2,ELEMENTOP *fimListaPerguntas2,int totPerguntas,ELEMENTOP *iniListaPerguntas,ELEMENTOP *fimListaPerguntas) {
    int jogada = 0, i = 0, j = 0;
    char carater;
    char resposta[100];
    int caixa = 900;
    int categoria = 0;
    int totalApostaFinal;
    ELEMENTO *maiorPontuacao = NULL, *menorPontuacao = NULL;
    DATA dataAtual;

    ELEMENTOP *aux = NULL;
    ELEMENTO *aux2[2] = {NULL, NULL};

    user[0]->info.dinheiro=0;
    user[1]->info.dinheiro=0;
    user[0]->info.apostaFinal=0;
    user[1]->info.apostaFinal=0;

    aux = iniListaPerguntas2;

    for (i = 0; i < 2; i++) {
        printf("Introduza o carater de jogo do jogador %i - %s :", i + 1, user[i]->info.username);
        scanf(" %c", &user[i]->info.carater);
    }

    for (jogada = 0; jogada < totPerguntas; jogada++) {
        apresentarInfoJogo(user,caixa);
        apresentacaoPerguntas(aux);

        while (carater != user[0]->info.carater && carater != user[1]->info.carater) {
            printf("\nJogador a responder:");
            scanf(" %c", &carater);
        }

        if (user[0]->info.carater == carater) {
            aux2[0] = user[0];
            aux2[1] = user[1];
        }
        if (user[1]->info.carater == carater) {
            aux2[0] = user[1];
            aux2[1] = user[0];
        }

        verificaRespostas(aux,aux2,&caixa);

        aux = aux->seguinte;
        carater = '\0';
    }

    printf("Aposta final:\n");
    if (user[0]->info.dinheiro > user[1]->info.dinheiro) {
        maiorPontuacao = user[0];
        menorPontuacao = user[1];
    } else {
        maiorPontuacao = user[1];
        menorPontuacao = user[0];
    }
    printf("Jogador %s\n", maiorPontuacao->info.username);
    printf("Introduza a categoria da pergunta:\n"
           "1- Geografia\t2- História\t3- Cinema\t4- Música\t5- Desporto\n"
           "6- Informatica\t7- Biologia\t8- Agricultura\t9- Matematica\t10- Cultura Geral\n"
           "Opção:");
    scanf("%i", &categoria);

    aux = perguntaFinal(categoria, iniListaPerguntas);

    for (i = 0; i < 2; i++) {
        do {
            printf("Introduza o valor da aposta final do jogador %s:\n", user[i]->info.username);
            scanf("%i", &user[i]->info.apostaFinal);

        } while (user[i]->info.apostaFinal < 500 && user[i]->info.apostaFinal > user[i]->info.dinheiro);
    }

    //user[0]->info.dinheiro -= user[0]->info.apostaFinal;
    //user[1]->info.dinheiro -= user[1]->info.apostaFinal;

    totalApostaFinal = user[0]->info.apostaFinal + user[1]->info.apostaFinal;

    apresentarInfoJogo(user,caixa);
    apresentacaoPerguntas(aux);
    verificarPerguntaFinal(aux,maiorPontuacao,menorPontuacao,totalApostaFinal,&caixa);

    dataAtual=getdate();
    user[0]->info.ultima=dataAtual;
    user[1]->info.ultima=dataAtual;
}
//************************************************************
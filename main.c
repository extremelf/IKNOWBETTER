#include <sys/time.h>
#include "gestaoDados.h"


USER registarUser(){
    USER aux;

    printf("Introduza nome:\n");
    scanf(" %100[^\n]s",aux.nome);
    printf("Introduza um username:\n");
    scanf(" %100[^\n]s",aux.username);
    printf("Introduza password:\n");
    scanf(" %100[^\n]s",aux.passwd);
    printf("Introduza a idade atual:\n");
    scanf("%i",&aux.idade);
    printf("Introduza a sua nacionalidade:\n");
    scanf(" %100[^\n]s",aux.nacionalidade);
    aux.isAdmin=0;
    return aux;
}
int menu_arranque () {
    int opc = 0;
    printf("*************MENU-************\n");
    printf("***********1-JOGAR************\n");
    printf("***********2-ADMINISTRAR******\n");
    printf("***********0-SAIR*************\n");
    scanf("%i", &opc);
    return opc;
}
int menu_user() {
    int opc = 0;
    printf("*******MENU*************\n");
    printf("******1-ACESSAR CONTA***\n");
    printf("******2-REGISTAR*******\n");
    printf("******3-JOGAR**********\n");
    printf("******0-SAIR***********\n");
    scanf("%i", &opc);
    return opc;
}

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

    aux = perguntaFinal(categoria, iniListaPerguntas, iniListaPerguntas2);

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
                    caixa += 300;
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
                    caixa += 300;
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
                    caixa += totalApostaFinal;
                    break;
                }
            }
        }
    }
    dataAtual=getdate();
    user[0]->info.ultima=getdate();
    user[1]->info.ultima=getdate();
}

int main() {
    int nPerguntas=0;
    int opc1=0, opc2=0;
    int i=0;
    int pid;
    struct timeval t;
    gettimeofday(&t, NULL);
    srand(t.tv_usec * t.tv_sec * pid);

    USER newUser;
    ELEMENTO *user[2]={NULL,NULL};
    ELEMENTO *iniListaUser=NULL, *fimListaUser=NULL;
    ELEMENTOP *iniListaPerguntas=NULL, *fimListaPerguntas=NULL;
    ELEMENTOP *iniListaPerguntas2=NULL, *fimListaPerguntas2=NULL;
    ELEMENTOR *iniListaRanking=NULL, *fimListaRanking=NULL;

    lerPerguntas(&iniListaPerguntas,&fimListaPerguntas);
    lerUserEmFicheiro(&iniListaUser,&fimListaUser);
    //lerRanking(&iniListaRanking,fimListaRanking);
    //listarPerguntas(iniListaPerguntas);

    do{
        opc1=menu_arranque();
        switch(opc1){
            case 1:{
                do{
                    opc2=menu_user();
                    switch (opc2) {
                        case 1:{
                            if(user[0]!=NULL && user[1]!=NULL){
                                printf("Maximo de jogadores em simultâneo\n");
                                break;
                            }
                            do{
                                do{
                                    printf("Jogador %i:\n",i+1);
                                    user[i]=login(iniListaUser);
                                }while(user[i]==NULL);
                                i++;
                                if(user[1]==user[0]){
                                    printf("Utilizador já logado\n");
                                    user[1]=NULL;
                                    i--;
                                }
                            }while(user[0]==NULL || user[1]==NULL);

                            break;
                        }
                        case 2:{
                            newUser=registarUser();
                            inserirFimLista(&iniListaUser,&fimListaUser,newUser);
                            break;
                        }
                        case 3:{
                            if(user[0]==NULL || user[1]==NULL){
                                printf("Sem utilizadores com sessão iniciada\n");
                                break;
                            }
                            else{
                                printf("Introduza a quantidade de perguntas a jogar:\n");
                                scanf("%i",&nPerguntas);
                                geradorPerguntas(iniListaPerguntas,&iniListaPerguntas2,&fimListaPerguntas2,nPerguntas);
                                jogada(user,iniListaPerguntas2,fimListaPerguntas2,nPerguntas,iniListaPerguntas,fimListaPerguntas);
                            }
                            break;
                        }
                        default:{
                            printf("Opção errada\n");
                        }
                    }
                }while(opc2!=0);
            }
            case 2:{
                break;
            }
            case 0:{
                printf("Saindo...\n");
                gravarEmFicheiro(iniListaUser);
                limparLista(&iniListaUser,&iniListaUser);
                limparListaPerguntas(&iniListaPerguntas,&iniListaPerguntas);
                limparListaPerguntas(&iniListaPerguntas2,&iniListaPerguntas2);
                limparListaRanking(&iniListaRanking,&fimListaRanking);
            }
            default:{
                printf("Opção errada\n");
            }
        }
    }while(opc1!=0);

    return 0;
}

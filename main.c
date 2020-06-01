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

void jogada(ELEMENTO *user[],ELEMENTOP *iniListaPerguntas2,ELEMENTOP *fimListaPerguntas2,int totPerguntas){
    int jogada=0,i=0,j=0;
    char carater;
    char resposta[100];
    int caixa=900;

    ELEMENTOP *aux=NULL;
    ELEMENTO *aux2[2]={NULL,NULL};

    aux=iniListaPerguntas2;


    //FODEUUUUUUUUU!!!! XD
    //Não sei que raio fazer
    for(i=0;i<2;i++){
        printf("Introduza o carater de jogo do jogador %i",i+1);
        scanf(" %c",&user[i]->info.carater);
    }

    for(jogada=0;jogada<totPerguntas+1;jogada++){
        if(aux->info.tipoPergunta==1){
            printf(" %s\n %s\t %s\n %s\t %s",aux->info.pergunta,aux->info.respostas[0],
                   aux->info.respostas[1],aux->info.respostas[2],aux->info.respostas[3]);
        }
        if(aux->info.tipoPergunta==2){
            printf(" %s\n Resposta:",aux->info.respostas[4]);
        }
        printf("Jogador a responder:");
        carater=getchar();
        if(user[0]->info.carater==carater){
            aux2[0]=user[0];
            aux2[1]=user[1];
        }
        if(user[1]->info.carater==carater){
            aux2[0]=user[1];
            aux2[1]=user[0];
        }
        switch(aux->info.tipoPergunta){
            case 1:{
                printf("Jogador %s a responder:\n",aux2[0]->info.username);
                scanf(" %100[^\n]s", resposta);
                if(strcmp(resposta,(aux->info.correta))==0){
                    printf("resposta correta\n");
                    aux2[0]->info.dinheiro+=250;
                }
                if(strcmp(resposta,(aux->info.correta))!=0){
                    printf("Jogador %s a responder:\n",aux2[1]->info.username);
                    scanf(" %100[^\n]s", resposta);
                    if(strcmp(resposta,(aux->info.correta))==0){
                        printf("resposta correta\n");
                        aux2[1]->info.dinheiro+=300;
                    }
                    else{

                        caixa+=300;
                    }
                }
            }
            case 2:{
                printf("Jogador %s a responder:\n",aux2[0]->info.username);
                scanf(" %100[^\n]s", resposta);
                if(strcmp(resposta,(aux->info.correta))==0){
                    printf("resposta correta\n");
                    aux2[0]->info.dinheiro+=250;
                }
                if(strcmp(resposta,(aux->info.correta))!=0){
                    printf("Jogador %s a responder:\n",aux2[1]->info.username);
                    scanf(" %100[^\n]s", resposta);
                    if(strcmp(resposta,(aux->info.correta))==0){
                        printf("resposta correta\n");
                        aux2[1]->info.dinheiro+=300;
                    }
                    else{
                        printf("Resposta errada\n");
                        caixa+=300;
                    }
                }
            }
            case 3:{
                printf("Jogador %s a responder V/F:\n",aux2[0]->info.username);
                scanf(" %100[^\n]s", resposta);
                if(strcmp(resposta,(aux->info.correta))==0){
                    printf("resposta correta\n");
                    aux2[0]->info.dinheiro+=250;
                }
                if(strcmp(resposta,(aux->info.correta))!=0){
                    printf("Jogador %s a responder V/F:\n",aux2[1]->info.username);
                    scanf(" %100[^\n]s", resposta);
                    if(strcmp(resposta,(aux->info.correta))==0){
                        printf("resposta correta\n");
                        aux2[1]->info.dinheiro+=300;
                    }
                    else{
                        printf("Resposta errada\n");
                        caixa+=300;
                    }
                }
            }

        }
        aux=aux->seguinte;
    }
}

int main() {
    int nPerguntas=0;
    int opc1=0, opc2=0;
    int i=0;

    USER newUser;
    ELEMENTO *user[2]={NULL,NULL};
    ELEMENTO *iniListaUser=NULL, *fimListaUser=NULL;
    ELEMENTOP *iniListaPerguntas=NULL, *fimListaPerguntas=NULL;
    ELEMENTOP *iniListaPerguntas2=NULL, *fimListaPerguntas2=NULL;

    /*
    iniListaUser=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));
    iniListaPerguntas=(ELEMENTOP *)calloc(1,sizeof(ELEMENTOP));
    iniListaPerguntas2=(ELEMENTOP *)calloc(1,sizeof(ELEMENTOP));
    */

    lerPerguntas(&iniListaPerguntas,&fimListaPerguntas);
    lerUserEmFicheiro(&iniListaUser,&fimListaUser);
    //listarPerguntas(iniListaPerguntas);

    do{
        opc1=menu_arranque();
        switch(opc1){
            case 1:{
                do{
                    opc2=menu_user();
                    switch (opc2) {
                        case 1:{
                            do{
                                do{
                                    printf("Jogador %i:\n",i+1);
                                    user[i]=login(iniListaUser);
                                }while(user[i]==NULL);
                                i++;
                            }while(i!=2 && user[0]==NULL && user[1]==NULL);

                            break;
                        }
                        case 2:{
                            newUser=registarUser();
                            inserirFimLista(&iniListaUser,&fimListaUser,newUser);
                            //guardarUserEmFicheiro(&newUser);
                            break;
                        }
                        case 3:{
                            printf("Introduza a quantidade de perguntas a jogar:\n");
                            scanf("%i",&nPerguntas);
                            geradorPerguntas(&iniListaPerguntas2,&fimListaPerguntas2,nPerguntas);
                            printf("SIM");
                            jogada(user,iniListaPerguntas2,fimListaPerguntas2,nPerguntas);

                        }

                    }
                }while(opc2!=0);
            }
            case 2:{
                break;
            }
            case 0:{
                printf("Saindo\n");
                gravarEmFicheiro(iniListaUser);
            }
        }
    }while(opc1!=0);

    return 0;
}

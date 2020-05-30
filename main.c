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
    int jogada=0,i=0;
    char carater;
    char resposta[100];
    int caixa=900;

    ELEMENTOP *aux=NULL;

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
        scanf(" %c", &carater);

        printf("Qual a resposta:\n");
        scanf(" %100[^\n]s", resposta);

    }


}

int main() {
    int nPerguntas=0;
    int opc1=0, opc2=0;
    int i=0;

    USER newUser;
    ELEMENTO *iniListaUser=NULL, *fimListaUser=NULL;
    ELEMENTO *user[2];
    ELEMENTOP *iniListaPerguntas=NULL, *fimListaPerguntas=NULL;
    ELEMENTOP *iniListaPerguntas2=NULL, *fimListaPerguntas2=NULL;

    iniListaUser=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));
    iniListaPerguntas=(ELEMENTOP *)calloc(1,sizeof(ELEMENTOP));
    iniListaPerguntas2=(ELEMENTOP *)calloc(1,sizeof(ELEMENTOP));

    lerPerguntas(&iniListaPerguntas,&fimListaPerguntas);

    do{
        opc1=menu_arranque();
        switch(opc1){
            case 1:{
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
                        break;
                    }
                    case 3:{
                        printf("Introduza a quantidade de perguntas a jogar:\n");
                        scanf("%i",&nPerguntas);
                        ELEMENTOP perguntasJogo[nPerguntas];
                        geradorPerguntas(&iniListaPerguntas2,&fimListaPerguntas2,nPerguntas);

                    }

                }
            }
        }
    }while(opc1!=0);

    return 0;
}
